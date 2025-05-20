//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// WAV header structure
typedef struct {
    char riff[4];          // RIFF
    uint32_t size;         // File size
    char wave[4];          // WAVE
    char fmt[4];           // fmt
    uint32_t fmt_size;     // Size of this chunk
    uint16_t format;       // Format type
    uint16_t channels;     // Number of channels
    uint32_t sample_rate;  // Sample rate
    uint32_t byte_rate;    // Byte rate
    uint16_t block_align;  // Block align
    uint16_t bits_per_sample; // Bits per sample
    char data[4];          // data
    uint32_t data_size;    // Size of data
} WAVHeader;

WAVHeader read_wav_header(FILE *file) {
    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, file);
    return header;
}

void write_wav_header(FILE *file, WAVHeader header) {
    fwrite(&header, sizeof(WAVHeader), 1, file);
}

int16_t* read_audio_data(FILE *file, uint32_t size) {
    int16_t *data = malloc(size);
    if (data) {
        fread(data, sizeof(int16_t), size / sizeof(int16_t), file);
    }
    return data;
}

void apply_gain(int16_t *data, uint32_t size, float gain) {
    for (uint32_t i = 0; i < size / sizeof(int16_t); i++) {
        int32_t sample = (int32_t)data[i] * gain; // Apply gain
        data[i] = (sample > 32767) ? 32767 : (sample < -32768 ? -32768 : sample); // Saturation
    }
}

void write_audio_data(FILE *file, int16_t *data, uint32_t size) {
    fwrite(data, sizeof(int16_t), size / sizeof(int16_t), file);
}

void process_audio(const char *input_file, const char *output_file, float gain) {
    FILE *in_file = fopen(input_file, "rb");
    if (!in_file) {
        perror("Error opening input file");
        return;
    }
    
    WAVHeader header = read_wav_header(in_file);
    uint32_t data_size = header.data_size;
    
    int16_t *audio_data = read_audio_data(in_file, data_size);
    fclose(in_file);

    if (audio_data == NULL) {
        perror("Error reading audio data");
        return;
    }

    apply_gain(audio_data, data_size, gain);

    FILE *out_file = fopen(output_file, "wb");
    if (!out_file) {
        perror("Error opening output file");
        free(audio_data);
        return;
    }

    header.data_size = data_size;
    header.size = sizeof(WAVHeader) + data_size - 8; // Adjust size field
    write_wav_header(out_file, header);
    write_audio_data(out_file, audio_data, data_size);
    
    fclose(out_file);
    free(audio_data);
    printf("Processing complete: '%s' -> '%s' with gain of %.2f\n", input_file, output_file, gain);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    process_audio(input_file, output_file, gain);

    return EXIT_SUCCESS;
}