//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <sndfile.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 256
#define TABLE_SIZE 200

typedef struct {
    double phase;
    double frequency;
    double volume;
} paData;

int audioCallback(const void *inputBuffer, void *outputBuffer,
                  unsigned long framesPerBuffer,
                  const PaStreamCallbackTimeInfo *timeInfo,
                  PaStreamCallbackFlags statusFlags,
                  void *userData) {
    
    paData *data = (paData*)userData;
    float *out = (float*)outputBuffer;
    unsigned int i;

    for (i = 0; i < framesPerBuffer; i++) {
        // Generate Sine Wave
        out[i] = (float)(data->volume * sin(data->phase));
        data->phase += (2.0 * M_PI * data->frequency) / SAMPLE_RATE;
        if (data->phase >= 2.0 * M_PI)
            data->phase -= 2.0 * M_PI;
    }
    
    return paContinue;
}

void displayWaveform(const char *filename) {
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(filename, SFM_READ, &sfinfo);

    if (!infile) {
        fprintf(stderr, "Error opening file: %s\n", sf_strerror(NULL));
        return;
    }

    float *buffer = malloc(sfinfo.frames * sfinfo.channels * sizeof(float));
    sf_read_float(infile, buffer, sfinfo.frames * sfinfo.channels);
    sf_close(infile);

    printf("Waveform Data for: %s\n", filename);
    for (int i = 0; i < sfinfo.frames; i += sfinfo.channels) {
        printf("%.3f\n", buffer[i]);
    }
    free(buffer);
}

int main(void) {
    // Initialize PortAudio
    PaError err;
    err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    // Prepare the data structure
    paData data;
    data.frequency = 440.0; // Frequency in Hz
    data.volume = 0.5;      // Volume (0.0 - 1.0)
    data.phase = 0.0;

    PaStream *stream;
    err = Pa_OpenDefaultStream(&stream, 
                                0, 
                                1, // mono output
                                paFloat32, 
                                SAMPLE_RATE, 
                                FRAMES_PER_BUFFER, 
                                audioCallback, 
                                &data);
                                
    if (err != paNoError) {
        fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    // Start the audio stream
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    printf("Playing a Sine Wave - Press Enter to stop...\n");
    getchar(); // Wait for user input

    // Stop and clean the audio stream
    err = Pa_StopStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio Error: %s\n", Pa_GetErrorText(err));
    }

    Pa_Terminate();

    // Display waveform of an audio file
    const char *filename = "example.wav"; // Change to the desired input file
    displayWaveform(filename);

    return 0;
}