//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WAV_HEADER_SIZE 44

// Function to set the volume
void set_volume(int16_t *buffer, size_t length, float volume) {
    for (size_t i = 0; i < length; i++) {
        // Adjust volume and clip values to the valid range
        int32_t sample = (int32_t)(buffer[i] * volume);
        if (sample > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)sample;
        }
    }
}

// Function to read a WAV file
int read_wav(const char *filename, int16_t **buffer, size_t *length) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return -1;
    }

    // Read header
    uint8_t header[WAV_HEADER_SIZE];
    fread(header, sizeof(uint8_t), WAV_HEADER_SIZE, file);

    // Check for WAV magic number
    if (strncmp((char *)header, "RIFF", 4) != 0 || strncmp((char *)(header + 8), "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file\n");
        fclose(file);
        return -1;
    }

    // Get the data chunk size and sample count
    uint32_t data_size = *(uint32_t *)(header + 40);
    *length = data_size / sizeof(int16_t);
    *buffer = malloc(data_size);
    if (*buffer == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return -1;
    }

    // Read the sound data
    fread(*buffer, sizeof(int16_t), *length, file);
    fclose(file);

    return 0;
}

// Function to write a WAV file
int write_wav(const char *filename, const int16_t *buffer, size_t length) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to create file");
        return -1;
    }

    // Create WAV header
    uint8_t header[WAV_HEADER_SIZE] = {0};
    memcpy(header, "RIFF", 4);
    uint32_t chunk_size = 36 + length * sizeof(int16_t);
    *(uint32_t *)(header + 4) = chunk_size;
    memcpy(header + 8, "WAVE", 4);
    memcpy(header + 12, "fmt ", 4);
    *(uint32_t *)(header + 16) = 16; // Subchunk1Size
    *(uint16_t *)(header + 20) = 1;  // AudioFormat (PCM)
    *(uint16_t *)(header + 22) = 1;  // NumChannels
    *(uint32_t *)(header + 24) = 44100; // SampleRate
    *(uint32_t *)(header + 28) = 44100 * sizeof(int16_t); // ByteRate
    *(uint16_t *)(header + 32) = sizeof(int16_t); // BlockAlign
    *(uint16_t *)(header + 34) = 16; // BitsPerSample
    memcpy(header + 36, "data", 4);
    *(uint32_t *)(header + 40) = length * sizeof(int16_t); // Subchunk2Size

    // Write header and data to the file
    fwrite(header, sizeof(uint8_t), WAV_HEADER_SIZE, file);
    fwrite(buffer, sizeof(int16_t), length, file);
    fclose(file);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <volume_multiplier>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float volume_multiplier = atof(argv[3]);

    int16_t *buffer = NULL;
    size_t length = 0;

    if (read_wav(input_file, &buffer, &length) != 0) {
        return EXIT_FAILURE;
    }

    set_volume(buffer, length, volume_multiplier);

    if (write_wav(output_file, buffer, length) != 0) {
        free(buffer);
        return EXIT_FAILURE;
    }

    free(buffer);
    printf("Processing complete: %s created with volume %.2f\n", output_file, volume_multiplier);
    return EXIT_SUCCESS;
}