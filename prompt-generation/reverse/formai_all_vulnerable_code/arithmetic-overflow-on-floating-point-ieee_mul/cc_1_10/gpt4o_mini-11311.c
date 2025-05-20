//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>

// Define a structure to pass to the thread
typedef struct {
    int16_t *buffer;
    size_t size;
    float gain;
} AudioData;

// Function to apply gain to audio samples
void *apply_gain(void *arg) {
    AudioData *data = (AudioData *)arg;
    for(size_t i = 0; i < data->size; i++) {
        int32_t sample = (int32_t)(data->buffer[i] * data->gain);
        // Clipping the values to the int16_t range
        data->buffer[i] = (int16_t)(sample > INT16_MAX ? INT16_MAX :
                            (sample < INT16_MIN ? INT16_MIN : sample));
    }
    return NULL;
}

// Function to read the WAV file header and audio data
int read_wav(const char *filename, int16_t **buffer, size_t *size) {
    FILE *file = fopen(filename, "rb");
    if (!file) return -1;

    char header[44]; // WAV header size
    fread(header, sizeof(char), 44, file); // Read header

    // Extract number of samples from the header (assumes PCM)
    *size = *(int32_t *)&header[40] / sizeof(int16_t);
    *buffer = (int16_t *)malloc(*size * sizeof(int16_t));
    if (!*buffer) return -1;

    fread(*buffer, sizeof(int16_t), *size, file); // Read audio data
    fclose(file);
    return 0;
}

// Function to write the modified audio data back to a WAV file
int write_wav(const char *filename, int16_t *buffer, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (!file) return -1;

    char header[44] = {
        'R','I','F','F',               // ChunkID
        0,0,0,0,                       // ChunkSize placeholder
        'W','A','V','E',               // Format
        'f','m','t',' ',               // Subchunk1ID
        16,0,0,0,                      // Subchunk1Size (for PCM)
        1,0,                           // AudioFormat (PCM)
        1,0,                           // NumChannels
        44100 & 0xff, (44100 >> 8) & 0xff, (44100 >> 16) & 0xff, (44100 >> 24) & 0xff, // SampleRate
        2,0,0,0,                       // ByteRate (SampleRate * NumChannels * BitsPerSample/8)
        2,0,                           // BlockAlign (NumChannels * BitsPerSample/8)
        16,0,                          // BitsPerSample
        'd','a','t','a',               // Subchunk2ID
        0,0,0,0                        // Subchunk2Size placeholder
    };

    *(int32_t *)&header[4] = 36 + size * sizeof(int16_t); // Update ChunkSize
    *(int32_t *)&header[40] = size * sizeof(int16_t); // Update Subchunk2Size

    // Write header
    fwrite(header, sizeof(char), 44, file);
    // Write audio data
    fwrite(buffer, sizeof(int16_t), size, file);
    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    int16_t *audio_buffer = NULL;
    size_t num_samples;

    // Read audio data from WAV file
    if (read_wav(input_file, &audio_buffer, &num_samples) < 0) {
        fprintf(stderr, "Failed to read WAV file\n");
        return EXIT_FAILURE;
    }

    // Prepare audio data for processing thread
    AudioData audio_data = {audio_buffer, num_samples, gain};
    pthread_t thread;

    // Create a thread to apply gain
    if (pthread_create(&thread, NULL, apply_gain, &audio_data) != 0) {
        fprintf(stderr, "Failed to create thread\n");
        free(audio_buffer);
        return EXIT_FAILURE;
    }

    // Wait for the thread to finish processing
    pthread_join(thread, NULL);

    // Write the modified audio data to a new WAV file
    if (write_wav(output_file, audio_buffer, num_samples) < 0) {
        fprintf(stderr, "Failed to write WAV file\n");
        free(audio_buffer);
        return EXIT_FAILURE;
    }

    // Cleanup
    free(audio_buffer);
    printf("Processing complete. Output written to %s\n", output_file);
    return EXIT_SUCCESS;
}