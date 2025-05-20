//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

#define SAMPLE_RATE 44100
#define DURATION 5
#define AMPLITUDE 32767

typedef struct {
    int16_t *samples;
    int size;
} AudioBuffer;

void generate_sine_wave(AudioBuffer *buffer, double frequency) {
    int num_samples = SAMPLE_RATE * DURATION;
    buffer->size = num_samples;
    buffer->samples = (int16_t *)malloc(num_samples * sizeof(int16_t));
    
    if (buffer->samples == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    for (int i = 0; i < num_samples; i++) {
        buffer->samples[i] = (int16_t)(AMPLITUDE * sin((2.0 * M_PI * frequency * i) / SAMPLE_RATE));
    }
}

void save_wav(const char *filename, AudioBuffer *buffer) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        exit(1);
    }
    
    // WAV file header
    fwrite("RIFF", 1, 4, file);
    uint32_t chunk_size = 36 + buffer->size * sizeof(int16_t);
    fwrite(&chunk_size, sizeof(uint32_t), 1, file);
    
    fwrite("WAVE", 1, 4, file);
    fwrite("fmt ", 1, 4, file);
    
    uint32_t subchunk1_size = 16; // for PCM
    fwrite(&subchunk1_size, sizeof(uint32_t), 1, file);
    
    uint16_t audio_format = 1; // PCM
    fwrite(&audio_format, sizeof(uint16_t), 1, file);
    
    uint16_t num_channels = 1; // mono
    fwrite(&num_channels, sizeof(uint16_t), 1, file);
    
    fwrite(&(uint32_t){SAMPLE_RATE}, sizeof(uint32_t), 1, file);
    uint32_t byte_rate = SAMPLE_RATE * num_channels * sizeof(int16_t);
    fwrite(&byte_rate, sizeof(uint32_t), 1, file);
    
    uint16_t block_align = num_channels * sizeof(int16_t);
    fwrite(&block_align, sizeof(uint16_t), 1, file);
    
    uint16_t bits_per_sample = 16;
    fwrite(&bits_per_sample, sizeof(uint16_t), 1, file);
    
    fwrite("data", 1, 4, file);
    uint32_t subchunk2_size = buffer->size * sizeof(int16_t);
    fwrite(&subchunk2_size, sizeof(uint32_t), 1, file);
    
    // Write samples
    fwrite(buffer->samples, sizeof(int16_t), buffer->size, file);
    
    fclose(file);
}

void free_buffer(AudioBuffer *buffer) {
    free(buffer->samples);
    buffer->samples = NULL;
    buffer->size = 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <output.wav> <frequency>\n", argv[0]);
        return 1;
    }
    
    const char *filename = argv[1];
    double frequency = atof(argv[2]);
    
    AudioBuffer audio_buffer;
    generate_sine_wave(&audio_buffer, frequency);
    save_wav(filename, &audio_buffer);
    
    printf("Generated sine wave at %.2f Hz and saved to %s\n", frequency, filename);
    
    free_buffer(&audio_buffer);
    return 0;
}