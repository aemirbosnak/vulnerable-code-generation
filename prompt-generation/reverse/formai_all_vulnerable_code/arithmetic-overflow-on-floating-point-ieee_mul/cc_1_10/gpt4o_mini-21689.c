//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100
#define NUM_CHANNELS 2
#define FRAMES_PER_BUFFER 256

typedef struct {
    double frequency;
    double amplitude;
    double phase;
} SynthParams;

void generateSineWave(double *outputBuffer, int frames, SynthParams *params) {
    for (int i = 0; i < frames; i++) {
        outputBuffer[i] = params->amplitude * sin(2.0 * M_PI * params->frequency * (i / (double)SAMPLE_RATE) + params->phase);
        params->phase += (2.0 * M_PI * params->frequency) / SAMPLE_RATE;
        
        // Ensure phase is wrapped between 0 and 2PI
        if (params->phase > 2.0 * M_PI) {
            params->phase -= 2.0 * M_PI;
        }
    }
}

void applyReverb(double *inputBuffer, double *outputBuffer, int frames, double reverbAmount) {
    static double delayBuffer[44100];
    static int delayIndex = 0;

    for (int i = 0; i < frames; i++) {
        double delayedSample = delayBuffer[delayIndex];
        outputBuffer[i] = inputBuffer[i] + (delayedSample * reverbAmount);
        delayBuffer[delayIndex] = inputBuffer[i];
        delayIndex = (delayIndex + 1) % 44100; // Assuming a 1-second delay
    }
}

void processAudio(SynthParams *synthParams, double reverbAmount, const char *outputFile) {
    SNDFILE *sf;
    SF_INFO sfinfo;
    double *sineWaveBuffer = malloc(FRAMES_PER_BUFFER * sizeof(double));
    double *outputBuffer = malloc(FRAMES_PER_BUFFER * sizeof(double));

    sfinfo.frames = 0;
    sfinfo.samplerate = SAMPLE_RATE;
    sfinfo.channels = NUM_CHANNELS;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

    sf = sf_open(outputFile, SFM_WRITE, &sfinfo);
    if (!sf) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        free(sineWaveBuffer);
        free(outputBuffer);
        return;
    }

    for (int i = 0; i < SAMPLE_RATE * 5; i += FRAMES_PER_BUFFER) {
        generateSineWave(sineWaveBuffer, FRAMES_PER_BUFFER, synthParams);
        applyReverb(sineWaveBuffer, outputBuffer, FRAMES_PER_BUFFER, reverbAmount);

        sf_writef_double(sf, outputBuffer, FRAMES_PER_BUFFER);
    }

    sf_close(sf);
    free(sineWaveBuffer);
    free(outputBuffer);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <frequency> <amplitude> <reverb_amount>\n", argv[0]);
        return EXIT_FAILURE;
    }

    SynthParams synthParams;
    synthParams.frequency = atof(argv[1]);
    synthParams.amplitude = atof(argv[2]);
    synthParams.phase = 0.0;

    double reverbAmount = atof(argv[3]);
    const char *outputFile = "output.wav";

    printf("Generating audio with Frequency: %.2f Hz, Amplitude: %.2f, Reverb Amount: %.2f\n", 
           synthParams.frequency, synthParams.amplitude, reverbAmount);
    
    processAudio(&synthParams, reverbAmount, outputFile);

    printf("Finished processing audio. Output saved to: %s\n", outputFile);

    return EXIT_SUCCESS;
}