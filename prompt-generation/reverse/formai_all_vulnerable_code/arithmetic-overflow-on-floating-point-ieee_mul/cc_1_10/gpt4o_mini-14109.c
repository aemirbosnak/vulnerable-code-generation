//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 256
#define GAIN 2.0f

// Function to apply gain to audio samples
void apply_gain(float *buffer, int num_frames, float gain) {
    for (int i = 0; i < num_frames; i++) {
        buffer[i] *= gain;
    }
}

// Audio callback for PortAudio
static int audio_callback(const void *inputBuffer, void *outputBuffer,
                          unsigned long framesPerBuffer,
                          const PaStreamCallbackTimeInfo *timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData) {
    float *in = (float *)inputBuffer;
    float *out = (float *)outputBuffer;
    int num_frames = framesPerBuffer;

    if (inputBuffer == NULL) {
        for (int i = 0; i < num_frames; i++) {
            out[i] = 0; // mute output
        }
    } else {
        for (int i = 0; i < num_frames; i++) {
            out[i] = in[i] * GAIN; // Apply gain
        }
    }
    return paContinue;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav>\n", argv[0]);
        return 1;
    }

    // Read audio file
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(argv[1], SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Could not open input file %s: %s\n", argv[1], sf_strerror(infile));
        return 1;
    }

    // Prepare output audio file
    SNDFILE *outfile = sf_open(argv[2], SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Could not open output file %s: %s\n", argv[2], sf_strerror(outfile));
        sf_close(infile);
        return 1;
    }

    // Initialize PortAudio
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        sf_close(infile);
        sf_close(outfile);
        return 1;
    }

    // Setup audio stream
    PaStream *stream;
    err = Pa_OpenDefaultStream(&stream, 1, 1, paFloat32, SAMPLE_RATE, FRAMES_PER_BUFFER, audio_callback, NULL);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        Pa_Terminate();
        sf_close(infile);
        sf_close(outfile);
        return 1;
    }

    // Start audio stream
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "PortAudio error: %s\n", Pa_GetErrorText(err));
        Pa_CloseStream(stream);
        Pa_Terminate();
        sf_close(infile);
        sf_close(outfile);
        return 1;
    }

    // Buffer for audio samples
    float buffer[FRAMES_PER_BUFFER];

    // Process audio in blocks
    int read_count;
    while ((read_count = sf_readf_float(infile, buffer, FRAMES_PER_BUFFER)) > 0) {
        apply_gain(buffer, read_count, GAIN);
        sf_writef_float(outfile, buffer, read_count);
    }

    // Cleanup
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();
    sf_close(infile);
    sf_close(outfile);

    printf("Processed file written to %s\n", argv[2]);
    return 0;
}