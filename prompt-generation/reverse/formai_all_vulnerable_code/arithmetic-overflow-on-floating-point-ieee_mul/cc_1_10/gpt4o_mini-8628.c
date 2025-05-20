//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(1)
typedef struct {
    char chunkID[4];
    uint32_t chunkSize;
    char format[4];
} RIFFHeader;

typedef struct {
    char subchunk1ID[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
} WAVHeader;

typedef struct {
    char subchunk2ID[4];
    uint32_t subchunk2Size;
} DataHeader;

void apply_gain(int16_t *samples, size_t num_samples, float gain) {
    for (size_t i = 0; i < num_samples; i++) {
        int32_t temp = (int32_t)(samples[i] * gain);
        // Clipping
        if (temp > INT16_MAX) {
            samples[i] = INT16_MAX;
        } else if (temp < INT16_MIN) {
            samples[i] = INT16_MIN;
        } else {
            samples[i] = (int16_t)temp;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    float gain = atof(argv[3]);
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    RIFFHeader riff_header;
    fread(&riff_header, sizeof(RIFFHeader), 1, input_file);
    if (strncmp(riff_header.chunkID, "RIFF", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    WAVHeader wav_header;
    fread(&wav_header, sizeof(WAVHeader), 1, input_file);
    if (strncmp(wav_header.subchunk1ID, "fmt ", 4) != 0 || wav_header.audioFormat != 1) {
        fprintf(stderr, "Unsupported audio format\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    DataHeader data_header;
    fread(&data_header, sizeof(DataHeader), 1, input_file);
    fread(data_header.subchunk2ID, sizeof(data_header.subchunk2ID), 1, input_file);
    
    fseek(input_file, sizeof(wav_header) + sizeof(data_header), SEEK_SET);
    
    size_t num_samples = data_header.subchunk2Size / sizeof(int16_t);
    int16_t *samples = malloc(num_samples * sizeof(int16_t));
    fread(samples, sizeof(int16_t), num_samples, input_file);
    fclose(input_file);
    
    apply_gain(samples, num_samples, gain);
    
    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        perror("Error opening output file");
        free(samples);
        return EXIT_FAILURE;
    }
    
    fwrite(&riff_header, sizeof(RIFFHeader), 1, output_file);
    fwrite(&wav_header, sizeof(WAVHeader), 1, output_file);
    fwrite(&data_header, sizeof(DataHeader), 1, output_file);
    
    fwrite(samples, sizeof(int16_t), num_samples, output_file);
    free(samples);
    fclose(output_file);
    
    printf("Audio processing completed. Output written to %s\n", argv[2]);
    return EXIT_SUCCESS;
}