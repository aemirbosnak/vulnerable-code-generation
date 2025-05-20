//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define HEADER_SIZE 44

typedef struct {
    char chunkID[4];
    uint32_t chunkSize;
    char format[4];
    char subchunk1ID[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2ID[4];
    uint32_t subchunk2Size;
} WAVHeader;

void apply_gain(int16_t *buffer, uint32_t num_samples, float gain) {
    for (uint32_t i = 0; i < num_samples; i++) {
        int32_t sample = (int32_t)(buffer[i] * gain);
        if (sample > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)sample;
        }
    }
}

void process_wav_file(const char *input_file, const char *output_file, float gain) {
    FILE *infile = fopen(input_file, "rb");
    if (!infile) {
        perror("Error opening input file");
        return;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, infile);

    // Check for WAV format
    if (strncmp(header.chunkID, "RIFF", 4) != 0 || strncmp(header.format, "WAVE", 4) != 0) {
        fprintf(stderr, "Error: Not a valid WAV file.\n");
        fclose(infile);
        return;
    }

    // Calculate the number of samples
    uint32_t num_samples = header.subchunk2Size / sizeof(int16_t);
    int16_t *buffer = (int16_t *)malloc(header.subchunk2Size);

    if (buffer == NULL) {
        perror("Error allocating memory for audio buffer");
        fclose(infile);
        return;
    }

    fread(buffer, sizeof(int16_t), num_samples, infile);
    fclose(infile);

    // Apply gain effect
    apply_gain(buffer, num_samples, gain);

    // Write the modified buffer to a new WAV file
    FILE *outfile = fopen(output_file, "wb");
    if (!outfile) {
        perror("Error opening output file");
        free(buffer);
        return;
    }

    fwrite(&header, sizeof(WAVHeader), 1, outfile);
    fwrite(buffer, sizeof(int16_t), num_samples, outfile);
    
    fclose(outfile);
    free(buffer);
    printf("Processed and saved output to %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    process_wav_file(input_file, output_file, gain);

    return EXIT_SUCCESS;
}