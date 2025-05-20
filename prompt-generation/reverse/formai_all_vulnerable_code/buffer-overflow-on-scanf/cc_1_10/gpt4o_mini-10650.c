//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 256
#define TABLE_SIZE 200
#define PI 3.14159

typedef struct {
    float phase;
    float frequency;
    float volume;
    int effect; // 0: none, 1: reverb, 2: distortion
} AudioData;

static int audioCallback(const void *inputBuffer, 
                         void *outputBuffer, 
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo *timeInfo,
                         PaStreamCallbackFlags statusFlags,
                         void *userData) 
{
    AudioData *data = (AudioData*)userData;
    float *out = (float*)outputBuffer;
    unsigned long i;

    (void)inputBuffer; // Prevent unused variable warning

    for (i = 0; i < framesPerBuffer; i++) {
        // Generate a simple sine wave
        float value = data->volume * sinf(data->phase);
        data->phase += 2.0f * PI * data->frequency / SAMPLE_RATE;

        // Apply effects
        switch(data->effect) {
            case 1: // Reverb effect
                value += 0.5f * sinf(data->phase * 0.5); // Simulating a basic reverb
                break;
            case 2: // Distortion effect
                if(value > 0.5f)         value = 0.5f;
                else if(value < -0.5f)   value = -0.5f;
                break;
            default: // No effect
                break;
        }

        // Output the processed value
        *out++ = value; // left channel
        *out++ = value; // right channel
    }
    return paContinue;
}

void displayMenu() {
    printf("\n--- Cyberpunk Audio Synthesizer ---\n");
    printf("1. Change Frequency\n");
    printf("2. Change Volume\n");
    printf("3. Apply/Revert Effect\n");
    printf("4. Exit\n");
    printf("------------------------------------\n");
    printf("Choose an option: ");
}

int main(void) {
    PaError err;
    AudioData data;
    data.phase = 0.0f;
    data.frequency = 440.0f; // A4
    data.volume = 0.5f;       // Volume 50%
    data.effect = 0;          // No effect

    err = Pa_Initialize();
    if (err != paNoError) goto error;

    PaStream *stream;
    err = Pa_OpenDefaultStream(&stream,
                               0,          // No input
                               2,          // Stereo output
                               paFloat32,  // 32 bit floating point output
                               SAMPLE_RATE,
                               FRAMES_PER_BUFFER,
                               audioCallback,
                               &data);
    if (err != paNoError) goto error;

    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;

    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter new frequency (Hz): ");
                scanf("%f", &data.frequency);
                printf("Frequency set to: %.2f Hz\n", data.frequency);
                break;
            case 2:
                printf("Enter new volume (0.0 to 1.0): ");
                scanf("%f", &data.volume);
                printf("Volume set to: %.2f\n", data.volume);
                break;
            case 3:
                data.effect = (data.effect + 1) % 3; // Cycle through effects
                printf("Effect toggled to: %d\n", data.effect);
                break;
            case 4:
                goto cleanup;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

cleanup:
    err = Pa_StopStream(stream);
    if (err != paNoError) goto error;
    err = Pa_CloseStream(stream);
    if (err != paNoError) goto error;
    Pa_Terminate();
    printf("Exiting Cyberpunk Audio Synthesizer...\n");
    return 0;

error:
    Pa_Terminate();
    fprintf(stderr, "An error occurred while using the PortAudio stream: %s\n", Pa_GetErrorText(err));
    return -1;
}