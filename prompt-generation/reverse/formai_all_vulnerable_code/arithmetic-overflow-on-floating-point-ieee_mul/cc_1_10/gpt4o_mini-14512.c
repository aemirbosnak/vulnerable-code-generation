//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100
#define MAX_AMPLITUDE 32767.0

void generateSineWave(double frequency, double duration, const char *filename) {
    int numSamples = (int)(SAMPLE_RATE * duration);
    double *buffer = (double *)malloc(numSamples * sizeof(double));
    
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < numSamples; i++) {
        buffer[i] = MAX_AMPLITUDE * sin(2 * M_PI * frequency * (i / (double)SAMPLE_RATE));
    }

    SF_INFO sfinfo;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    sfinfo.frames = numSamples;
    sfinfo.channels = 1; // mono
    sfinfo.samplerate = SAMPLE_RATE;

    SNDFILE *outfile = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Could not open file for writing: %s\n", sf_strerror(NULL));
        free(buffer);
        return;
    }

    sf_writef_double(outfile, buffer, numSamples);
    sf_close(outfile);
    free(buffer);
}

void applyEcho(double *inputBuffer, int numSamples, double delayInSeconds, double decayFactor) {
    int delaySamples = (int)(delayInSeconds * SAMPLE_RATE);
    
    for (int i = delaySamples; i < numSamples; i++) {
        inputBuffer[i] += decayFactor * inputBuffer[i - delaySamples];
    }
}

void processAudio(const char *inputFile, const char *outputFile, double delay, double decay) {
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(inputFile, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Could not open input file: %s\n", sf_strerror(NULL));
        return;
    }

    double *buffer = (double *)malloc(sfinfo.frames * sizeof(double));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        sf_close(infile);
        return;
    }

    sf_readf_double(infile, buffer, sfinfo.frames);
    sf_close(infile);

    applyEcho(buffer, sfinfo.frames, delay, decay);

    SNDFILE *outfile = sf_open(outputFile, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Could not open output file: %s\n", sf_strerror(NULL));
        free(buffer);
        return;
    }

    sf_writef_double(outfile, buffer, sfinfo.frames);
    sf_close(outfile);
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <sine_wave_frequency> <duration> <output_file> <echo_delay_in_seconds> <echo_decay>\n", argv[0]);
        return 1;
    }

    double frequency = atof(argv[1]);
    double duration = atof(argv[2]);
    const char *outputFile = argv[3];
    double delay = atof(argv[4]);
    double decay = atof(argv[5]);

    // Step 1: Generate a sine wave
    char tempWaveFile[] = "temp_wave.wav";
    generateSineWave(frequency, duration, tempWaveFile);
    
    // Step 2: Process audio to apply echo
    processAudio(tempWaveFile, outputFile, delay, decay);

    // Cleanup temporary file
    remove(tempWaveFile);

    printf("Audio processing complete. Output saved to %s\n", outputFile);
    return 0;
}