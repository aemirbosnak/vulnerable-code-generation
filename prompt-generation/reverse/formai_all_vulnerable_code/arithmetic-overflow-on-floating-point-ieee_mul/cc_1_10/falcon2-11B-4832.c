//Falcon2-11B DATASET v1.0 Category: Audio processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    int i, j, num_samples;
    float *audio_buffer, *spectrum_buffer;
    double sample_rate;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_audio_file> <output_spectrum_file>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file %s\n", argv[1]);
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    num_samples = ftell(input_file) / sizeof(float);
    fseek(input_file, 0, SEEK_SET);

    audio_buffer = (float*)malloc(num_samples * sizeof(float));
    if (audio_buffer == NULL) {
        fprintf(stderr, "Error allocating memory for audio buffer\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    spectrum_buffer = (float*)malloc(num_samples * sizeof(float));
    if (spectrum_buffer == NULL) {
        fprintf(stderr, "Error allocating memory for spectrum buffer\n");
        fclose(input_file);
        fclose(output_file);
        free(audio_buffer);
        return 1;
    }

    sample_rate = 44100.0; // default sample rate (44.1 kHz)

    for (i = 0; i < num_samples; i++) {
        fread(&audio_buffer[i], sizeof(float), 1, input_file);
        for (j = 0; j < num_samples; j++) {
            spectrum_buffer[j] += audio_buffer[j] * audio_buffer[j];
        }
    }

    fclose(input_file);

    for (i = 0; i < num_samples; i++) {
        spectrum_buffer[i] = sqrt(spectrum_buffer[i]);
    }

    for (i = 0; i < num_samples; i++) {
        fprintf(output_file, "%.4f\n", spectrum_buffer[i]);
    }

    fclose(output_file);

    free(audio_buffer);
    free(spectrum_buffer);

    return 0;
}