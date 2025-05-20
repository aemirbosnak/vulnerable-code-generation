//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WAV_HEADER_SIZE 44

typedef struct {
    unsigned char chunkID[4];       // "RIFF"
    unsigned int chunkSize;
    unsigned char format[4];         // "WAVE"
    unsigned char subchunk1ID[4];    // "fmt "
    unsigned int subchunk1Size;
    unsigned short audioFormat;
    unsigned short numChannels;
    unsigned int sampleRate;
    unsigned int byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
    unsigned char subchunk2ID[4];     // "data"
    unsigned int subchunk2Size;
} WAVHeader;

void apply_gain(short *buffer, size_t num_samples, float gain) {
    for (size_t i = 0; i < num_samples; i++) {
        int sample = (int)(buffer[i] * gain);
        // Clamping the samples to avoid overflow
        if (sample > 32767) {
            buffer[i] = 32767;
        } else if (sample < -32768) {
            buffer[i] = -32768;
        } else {
            buffer[i] = sample;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.wav> <output.wav> <gain_factor>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float gain = atof(argv[3]);

    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, input_file);
    if (strncmp((char *)header.chunkID, "RIFF", 4) != 0 || 
        strncmp((char *)header.format, "WAVE", 4) != 0) {
        fprintf(stderr, "This file is not a valid WAV file.\n");
        fclose(input_file);
        return 1;
    }

    size_t num_samples = header.subchunk2Size / sizeof(short);
    short *buffer = (short *)malloc(header.subchunk2Size);
    if (!buffer) {
        perror("Failed to allocate memory for audio buffer");
        fclose(input_file);
        return 1;
    }

    fread(buffer, sizeof(short), num_samples, input_file);
    fclose(input_file);

    apply_gain(buffer, num_samples, gain);

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Error opening output file");
        free(buffer);
        return 1;
    }

    fwrite(&header, sizeof(WAVHeader), 1, output_file);
    fwrite(buffer, sizeof(short), num_samples, output_file);
    fclose(output_file);
    free(buffer);

    printf("Processed %zu samples with gain %.2f. Output saved to %s.\n", num_samples, gain, output_filename);
    return 0;
}