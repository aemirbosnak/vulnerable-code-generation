//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100  // Standard sample rate for audio files
#define PI 3.14159265358979323846

typedef struct {
    float *data;
    int num_samples;
} AudioBuffer;

// Function to read audio from file
AudioBuffer read_audio(const char *filename) {
    SF_INFO sfinfo;
    sfinfo.format = 0;

    // Open audio file
    SNDFILE *file = sf_open(filename, SFM_READ, &sfinfo);
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(1);
    }

    // Allocate memory for audio buffer
    AudioBuffer buffer;
    buffer.num_samples = sfinfo.frames * sfinfo.channels;
    buffer.data = (float *)malloc(buffer.num_samples * sizeof(float));
    
    // Read samples into buffer
    sf_readf_float(file, buffer.data, sfinfo.frames);
    sf_close(file);

    return buffer;
}

// Function to write audio to file
void write_audio(const char *filename, AudioBuffer buffer, int channels) {
    SF_INFO sfinfo;
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    sfinfo.channels = channels;
    sfinfo.samplerate = SAMPLE_RATE;

    // Open audio file for writing
    SNDFILE *file = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!file) {
        fprintf(stderr, "Could not open file for writing: %s\n", filename);
        free(buffer.data);
        exit(1);
    }

    // Write samples from buffer to file
    sf_writef_float(file, buffer.data, buffer.num_samples / channels);
    sf_close(file);
}

// Function to apply a simple gain effect to the audio buffer
void apply_gain(AudioBuffer buffer, float gain) {
    for (int i = 0; i < buffer.num_samples; i++) {
        buffer.data[i] *= gain; // Apply gain to each sample
    }
}

// Function to create a sine wave oscillator
void generate_sine_wave(AudioBuffer *buffer, float frequency, float duration) {
    buffer->num_samples = (int)(SAMPLE_RATE * duration);
    buffer->data = (float *)malloc(buffer->num_samples * sizeof(float));

    for (int i = 0; i < buffer->num_samples; i++) {
        buffer->data[i] = 0.5f * sinf(2.0f * PI * frequency * i / SAMPLE_RATE); // Amplitude set to 0.5
    }
}

// Main function to process audio
int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    // Read audio data from file
    AudioBuffer input_buffer = read_audio(input_file);
    printf("Read %d samples from %s\n", input_buffer.num_samples, input_file);

    // Apply gain effect
    apply_gain(input_buffer, gain);
    printf("Applied gain of %f to the audio samples.\n", gain);

    // Write the processed audio to a new file
    write_audio(output_file, input_buffer, 1);
    printf("Written processed audio to %s\n", output_file);

    // Free the allocated memory
    free(input_buffer.data);
    printf("Freed memory allocated for audio samples. Program completed.\n");

    return 0;
}