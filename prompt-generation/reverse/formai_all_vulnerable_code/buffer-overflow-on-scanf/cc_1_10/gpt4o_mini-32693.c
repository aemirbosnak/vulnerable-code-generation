//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 256
#define NUM_USERS 4
#define MAX_AUDIO_LENGTH (NUM_USERS * FRAMES_PER_BUFFER)

typedef struct {
    float recordedSamples[NUM_USERS][MAX_AUDIO_LENGTH];
    int currentUser;
} AudioData;

static int audioCallback(const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo *timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData) {
    AudioData *data = (AudioData *)userData;
    float *in = (float *)inputBuffer;
    float *out = (float *)outputBuffer;

    // Mixing audio from each user
    for (int i = 0; i < framesPerBuffer; i++) {
        out[i] = 0.0f; // Initialize output sample
        for (int j = 0; j < NUM_USERS; j++) {
            out[i] += data->recordedSamples[j][i]; // Mix audio from each user
        }
        // Clamp to avoid clipping
        if (out[i] > 1.0f) out[i] = 1.0f;
        if (out[i] < -1.0f) out[i] = -1.0f;
    }

    // Record audio for the current user
    for (int i = 0; i < framesPerBuffer; i++) {
        data->recordedSamples[data->currentUser][i] = in[i];
    }

    return paContinue;
}

int main(void) {
    AudioData audioData;
    PaStream *stream;
    int numUsers = 0;

    // Initialize recorded samples
    memset(&audioData.recordedSamples, 0, sizeof(audioData.recordedSamples));
    audioData.currentUser = 0;

    // Initialize PortAudio
    PaError err = Pa_Initialize();
    if (err != paNoError) goto error;

    // Open stream
    err = Pa_OpenDefaultStream(&stream, 1, 1, paFloat32, SAMPLE_RATE,
                                FRAMES_PER_BUFFER, audioCallback, &audioData);
    if (err != paNoError) goto error;

    // Start stream
    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;

    printf("Audio processing started. Type 'exit' to quit.\n");

    // Loop to handle user input for selecting current user
    while (1) {
        char input[10];
        printf("Enter user index (0 to %d) to record, or type 'exit' to stop: ", NUM_USERS - 1);
        scanf("%s", input);
        
        if (strcmp(input, "exit") == 0) break;
        
        int userIndex = atoi(input);
        if (userIndex >= 0 && userIndex < NUM_USERS) {
            audioData.currentUser = userIndex;
            printf("Now recording for user %d\n", userIndex);
        } else {
            printf("Invalid user index. Please try again.\n");
        }
    }

    // Stop and clean up
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();
    printf("Audio processing stopped.\n");

    return 0;
    
error:
    Pa_Terminate();
    fprintf(stderr, "An error occurred while using PortAudio: %s\n", Pa_GetErrorText(err));
    return -1;
}