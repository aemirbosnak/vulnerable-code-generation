//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 44 // Standard WAV header size

// Function to reverse the audio data from the WAV file
void reverse_audio(const char* input_filename, const char* output_filename) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Error opening input file");
        exit(1);
    }

    // Read WAV header
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, input_file);

    // Check for valid WAV file
    if (strncmp((char*)header, "RIFF", 4) != 0 || strncmp((char*)&header[8], "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file.\n");
        fclose(input_file);
        exit(1);
    }

    // Extract number of channels and sample rate
    int num_channels = *(short*)&header[22];
    int sample_rate = *(int*)&header[24];
    int bits_per_sample = *(short*)&header[34];
    int byte_rate = sample_rate * num_channels * bits_per_sample / 8;

    // Calculate data chunk size
    int data_size = *(int*)&header[40];
    int num_samples = data_size / (num_channels * bits_per_sample / 8);

    // Allocate memory for audio data
    unsigned char *data = (unsigned char*)malloc(data_size);
    if (!data) {
        perror("Unable to allocate memory for audio data");
        fclose(input_file);
        exit(1);
    }

    // Read audio data
    fread(data, sizeof(unsigned char), data_size, input_file);
    fclose(input_file);

    // Reverse the audio data
    unsigned char *reversed_data = (unsigned char*)malloc(data_size);
    if (!reversed_data) {
        perror("Unable to allocate memory for reversed audio data");
        free(data);
        exit(1);
    }
    
    for (int i = 0; i < data_size; i++) {
        reversed_data[i] = data[data_size - 1 - i];
    }

    // Write the reversed data to a new WAV file
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Error opening output file");
        free(data);
        free(reversed_data);
        exit(1);
    }

    // Write the header and the reversed data
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, output_file);
    fwrite(reversed_data, sizeof(unsigned char), data_size, output_file);
    fclose(output_file);

    // Clean up
    free(data);
    free(reversed_data);

    printf("Reversed audio written to %s\n", output_filename);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input wav file> <output wav file>\n", argv[0]);
        return 1;
    }

    reverse_audio(argv[1], argv[2]);

    return 0;
}