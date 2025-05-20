//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    char chunkID[4];       // "RIFF"
    uint32_t chunkSize;
    char format[4];        // "WAVE"
    char subchunk1ID[4];   // "fmt "
    uint32_t subchunk1Size;
    uint16_t audioFormat;  // PCM=1
    uint16_t numChannels;   // Mono=1, Stereo=2
    uint32_t sampleRate;    // e.g. 44100
    uint32_t byteRate;      // SampleRate * NumChannels * BitsPerSample/8
    uint16_t blockAlign;    // NumChannels * BitsPerSample/8
    uint16_t bitsPerSample; // e.g. 16 for PCM
    char subchunk2ID[4];    // "data"
    uint32_t subchunk2Size; // == NumSamples * NumChannels * BitsPerSample/8
} WAVHeader;
#pragma pack(pop)

void normalize_audio(const char *input_file, const char *output_file, float target_volume) {
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Error opening input file");
        return;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, input);

    // Check if the file is a valid WAV file
    if (header.chunkID[0] != 'R' || header.chunkID[1] != 'I' ||
        header.chunkID[2] != 'F' || header.chunkID[3] != 'F') {
        fprintf(stderr, "Not a valid WAV file.\n");
        fclose(input);
        return;
    }

    // Calculate average volume
    int16_t *buffer = (int16_t*)malloc(header.subchunk2Size);
    if (buffer == NULL) {
        fclose(input);
        perror("Memory allocation failed");
        return;
    }

    fread(buffer, sizeof(int16_t), header.subchunk2Size / sizeof(int16_t), input);
    fclose(input);

    int max_value = 0;
    for (uint32_t i = 0; i < header.subchunk2Size / sizeof(int16_t); i++) {
        int abs_value = abs(buffer[i]);
        if (abs_value > max_value) {
            max_value = abs_value;
        }
    }

    // Normalize the audio
    float normalization_factor = target_volume / max_value;

    for (uint32_t i = 0; i < header.subchunk2Size / sizeof(int16_t); i++) {
        buffer[i] = (int16_t)(buffer[i] * normalization_factor);
    }

    // Write the normalized audio to a new file
    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Error opening output file");
        free(buffer);
        return;
    }

    fwrite(&header, sizeof(WAVHeader), 1, output);
    fwrite(buffer, sizeof(int16_t), header.subchunk2Size / sizeof(int16_t), output);
    fclose(output);
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <target_volume>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float target_volume = atof(argv[3]);

    if (target_volume <= 0) {
        fprintf(stderr, "Please provide a positive target volume.\n");
        return EXIT_FAILURE;
    }

    normalize_audio(input_file, output_file, target_volume);
    printf("Normalization complete. Output saved to: %s\n", output_file);
    
    return EXIT_SUCCESS;
}