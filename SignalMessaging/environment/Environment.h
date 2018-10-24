//
//  Copyright (c) 2018 Open Whisper Systems. All rights reserved.
//

#import <SignalServiceKit/SSKEnvironment.h>

@class LockInteractionController;
@class OWSAudioSession;
@class OWSContactsManager;
@class OWSPreferences;
@class OWSSounds;
@class OWSWindowManager;

/**
 *
 * Environment is a data and data accessor class.
 * It handles application-level component wiring in order to support mocks for testing.
 * It also handles network configuration for testing/deployment server configurations.
 *
 **/
// TODO: Rename to SMGEnvironment?
@interface Environment : NSObject

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithAudioSession:(OWSAudioSession *)audioSession
                         preferences:(OWSPreferences *)preferences
                              sounds:(OWSSounds *)sounds
           lockInteractionController:(LockInteractionController *)lockInteractionController
                       windowManager:(OWSWindowManager *)windowManager;

@property (nonatomic, readonly) OWSAudioSession *audioSession;
@property (nonatomic, readonly) OWSContactsManager *contactsManager;
@property (nonatomic, readonly) OWSPreferences *preferences;
@property (nonatomic, readonly) OWSSounds *sounds;
@property (nonatomic, readonly) LockInteractionController *lockInteractionController;
@property (nonatomic, readonly) OWSWindowManager *windowManager;

@property (class, nonatomic) Environment *shared;

#ifdef DEBUG
// Should only be called by tests.
+ (void)clearSharedForTests;
#endif

@end
