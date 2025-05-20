//Code Llama-13B DATASET v1.0 Category: Audio processing ; Style: Donald Knuth
/*
 * Donald Knuth-style C audio processing example program
 *
 * This program reads audio from the default input device and
 * writes it to the default output device, with a
 * Donald Knuth-style filter applied.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define FRAMES_PER_BUFFER 1024
#define SAMPLE_RATE 44100
#define FILTER_CUTOFF 20000

typedef struct {
    float x;
    float y;
} Complex;

Complex filter(Complex in) {
    Complex out;
    out.x = in.x * cos(in.y) - in.y * sin(in.x);
    out.y = in.x * sin(in.y) + in.y * cos(in.x);
    return out;
}

int main() {
    PaStreamParameters inputParameters;
    PaStreamParameters outputParameters;
    PaStream *stream;
    PaError err;

    inputParameters.device = Pa_GetDefaultInputDevice();
    inputParameters.channelCount = 2;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    outputParameters.device = Pa_GetDefaultOutputDevice();
    outputParameters.channelCount = 2;
    outputParameters.sampleFormat = paFloat32;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    err = Pa_OpenStream(&stream, &inputParameters, &outputParameters, SAMPLE_RATE, FRAMES_PER_BUFFER, paClipOff, NULL, NULL);
    if (err != paNoError) {
        fprintf(stderr, "Error opening stream: %s\n", Pa_GetErrorText(err));
        return err;
    }

    Complex *in, *out;
    in = (Complex *)malloc(FRAMES_PER_BUFFER * sizeof(Complex));
    out = (Complex *)malloc(FRAMES_PER_BUFFER * sizeof(Complex));

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error starting stream: %s\n", Pa_GetErrorText(err));
        return err;
    }

    for (;;) {
        err = Pa_ReadStream(stream, in, FRAMES_PER_BUFFER);
        if (err != paNoError) {
            fprintf(stderr, "Error reading stream: %s\n", Pa_GetErrorText(err));
            break;
        }

        for (int i = 0; i < FRAMES_PER_BUFFER; i++) {
            out[i] = filter(in[i]);
        }

        err = Pa_WriteStream(stream, out, FRAMES_PER_BUFFER);
        if (err != paNoError) {
            fprintf(stderr, "Error writing stream: %s\n", Pa_GetErrorText(err));
            break;
        }
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        fprintf(stderr, "Error closing stream: %s\n", Pa_GetErrorText(err));
        return err;
    }

    free(in);
    free(out);

    return 0;
}