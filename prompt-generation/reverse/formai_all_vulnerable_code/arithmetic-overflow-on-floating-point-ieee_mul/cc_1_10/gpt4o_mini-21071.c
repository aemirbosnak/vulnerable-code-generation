//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char chunkID[4];        // "RIFF"
    uint32_t chunkSize;     // Size of the chunk
    char format[4];         // "WAVE"
} WAVHeader;

typedef struct {
    char subchunk1ID[4];    // "fmt "
    uint32_t subchunk1Size;  // Size of the fmt chunk
    uint16_t audioFormat;    // Audio format (1 for PCM)
    uint16_t numChannels;     // Number of channels
    uint32_t sampleRate;      // Sample rate
    uint32_t byteRate;        // Bytes per second
    uint16_t blockAlign;      // Block align
    uint16_t bitsPerSample;   // Bits per sample
} WAVFormat;

typedef struct {
    char subchunk2ID[4];     // "data"
    uint32_t subchunk2Size;   // Size of the data section
} WAVDataHeader;
#pragma pack(pop)

void apply_gain(int16_t *buffer, size_t samples, float gain) {
    for (size_t i = 0; i < samples; i++) {
        buffer[i] = (int16_t)(buffer[i] * gain);

        // Clamp the value to the 16-bit signed range
        if (buffer[i] > 32767) buffer[i] = 32767;
        if (buffer[i] < -32768) buffer[i] = -32768;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float gain = atof(argv[3]);

    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    WAVHeader wav_header;
    fread(&wav_header, sizeof(wav_header), 1, input_file);
    
    if (strncmp(wav_header.chunkID, "RIFF", 4) != 0 || 
        strncmp(wav_header.format, "WAVE", 4) != 0) {
        fprintf(stderr, "Unsupported WAV file format\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    WAVFormat wav_format;
    fread(&wav_format, sizeof(wav_format), 1, input_file);

    WAVDataHeader wav_data_header;
    fread(&wav_data_header, sizeof(wav_data_header), 1, input_file);

    size_t num_samples = wav_data_header.subchunk2Size / (wav_format.bitsPerSample / 8);
    int16_t *buffer = (int16_t *)malloc(wav_data_header.subchunk2Size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    fread(buffer, wav_data_header.subchunk2Size, 1, input_file);
    fclose(input_file);

    apply_gain(buffer, num_samples, gain);

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Failed to open output file");
        free(buffer);
        return EXIT_FAILURE;
    }

    fwrite(&wav_header, sizeof(wav_header), 1, output_file);
    fwrite(&wav_format, sizeof(wav_format), 1, output_file);
    fwrite(&wav_data_header, sizeof(wav_data_header), 1, output_file);
    fwrite(buffer, wav_data_header.subchunk2Size, 1, output_file);

    free(buffer);
    fclose(output_file);

    printf("Gain applied successfully. Output saved to %s\n", output_filename);
    return EXIT_SUCCESS;
}