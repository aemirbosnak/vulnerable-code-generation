//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 2048

typedef struct {
    float freq;
    float gain;
} Filter;

void init_filter(Filter* filter, float frequency, float gain) {
    filter->freq = frequency;
    filter->gain = gain;
}

float process_sample(Filter* filter, float sample) {
    float b0 = 1.0f;
    float b1 = -2.0f * cos(2.0f * M_PI * filter->freq / SAMPLE_RATE);
    float a1 = -1.0f;
    float y1 = 0.0f;
    float x1 = sample;
    float y0 = 0.0f;
    float x0 = 0.0f;

    for (int i = 0; i < 10; i++) {
        float xn = x1 - a1 * y1 + b1 * x0;
        y1 = y0 + a1 * xn - b1 * y1;
        x0 = x1;
        x1 = xn;
    }

    float output = (b0 * x1 - b1 * y1) * filter->gain;
    return output;
}

int main() {
    Filter filter;
    init_filter(&filter, 440.0f, 0.5f);

    FILE* input_file = fopen("input.wav", "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_file = fopen("output.wav", "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    char header[44];
    fread(header, 1, 44, input_file);
    fwrite(header, 1, 44, output_file);

    short buffer[BUFFER_SIZE];
    while (fread(buffer, 2, BUFFER_SIZE, input_file) == BUFFER_SIZE) {
        for (int i = 0; i < BUFFER_SIZE; i++) {
            float sample = buffer[i] / 32768.0f;
            float processed_sample = process_sample(&filter, sample);
            buffer[i] = processed_sample * 32768.0f;
        }
        fwrite(buffer, 2, BUFFER_SIZE, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}