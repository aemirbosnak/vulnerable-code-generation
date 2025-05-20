//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char riff[4];          // RIFF Header
    uint32_t overall_size; // Overall size of file
    char wave[4];         // WAVE Header
    char fmt[4];          // FMT header
    uint32_t fmt_length;  // Length of the fmt data
    uint16_t format_type; // Format type
    uint16_t channels;     // Number of channels
    uint32_t sample_rate;  // Sample Rate
    uint32_t byte_rate;    // Bytes per second
    uint16_t block_align;  // 2=16-bit mono, 4=16-bit stereo
    uint16_t bits_per_sample; // Number of bits per sample (16 for PCM)
    char data[4];         // DATA header
    uint32_t data_size;   // Size of the data section
} WAVHeader;
#pragma pack(pop)

void apply_gain(int16_t *buffer, int32_t samples, float gain) {
    for(int32_t i = 0; i < samples; i++) {
        int32_t temp = (int32_t)(buffer[i] * gain);
        // Clip to avoid overflowing
        if(temp > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if(temp < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = temp;
        }
    }
}

void print_wav_header(const WAVHeader *header) {
    printf("WAV Header Information:\n");
    printf("RIFF: %.4s\n", header->riff);
    printf("Overall Size: %u\n", header->overall_size);
    printf("WAVE: %.4s\n", header->wave);
    printf("FMT: %.4s\n", header->fmt);
    printf("Format Length: %u\n", header->fmt_length);
    printf("Format Type: %u\n", header->format_type);
    printf("Channels: %u\n", header->channels);
    printf("Sample Rate: %u\n", header->sample_rate);
    printf("Byte Rate: %u\n", header->byte_rate);
    printf("Block Align: %u\n", header->block_align);
    printf("Bits per Sample: %u\n", header->bits_per_sample);
    printf("DATA: %.4s\n", header->data);
    printf("Data Size: %u\n", header->data_size);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float gain = atof(argv[3]);
    
    // Open input WAV file
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Read WAV header
    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, input_file);
    print_wav_header(&header);

    // Check if file is PCM
    if (header.format_type != 1) {
        fprintf(stderr, "Unsupported WAV format. Only PCM is supported.\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    size_t num_samples = header.data_size / sizeof(int16_t);
    int16_t *buffer = (int16_t *)malloc(num_samples * sizeof(int16_t));

    if (!buffer) {
        fclose(input_file);
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Read audio data
    fseek(input_file, sizeof(WAVHeader), SEEK_SET);
    fread(buffer, sizeof(int16_t), num_samples, input_file);

    // Apply gain
    apply_gain(buffer, num_samples, gain);

    // Write output WAV file
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Error opening output file");
        free(buffer);
        fclose(input_file);
        return EXIT_FAILURE;
    }

    fwrite(&header, sizeof(WAVHeader), 1, output_file);
    fwrite(buffer, sizeof(int16_t), num_samples, output_file);

    // Clean up
    free(buffer);
    fclose(input_file);
    fclose(output_file);

    printf("Processing completed. Output saved to %s\n", output_filename);
    return EXIT_SUCCESS;
}