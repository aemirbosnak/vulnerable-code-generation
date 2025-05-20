#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Custom audio codec (for presentation purposes)
#define MAX_SAMPLES 100000
typedef struct AudioSample {
    unsigned char sample[4];
} AudioSample;

void process_audio_stream(AudioSample* buffer, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        // Some arbitrary audio processing logic
        printf("Sample %d: 0x%02X%02X%02X%02X\n", i, buffer[i].sample[0], buffer[i].sample[1], buffer[i].sample[2], buffer[i].sample[3]);
    }
}

int main(int argc, char* argv[]) {
    AudioSample buffer[MAX_SAMPLES];
    int samples_count, i;

    if (argc < 2) {
        printf("Usage: %s <samples_count>\n", argv[0]);
        return 1;
    }

    // Vulnerable part of the code: overflow on sscanf
    if (sscanf(argv[1], "%d", &samples_count) != 1 || samples_count <= 0 || samples_count > MAX_SAMPLES) {
        printf("Invalid samples count.\n");
        return 1;
    }

    // Buffer overflow due to incorrect input validation
    for (i = samples_count; i < MAX_SAMPLES; ++i) {
        buffer[i] = (AudioSample){ {0, 1, 2, 3} }; // Arbitrary audio sample data
    }

    process_audio_stream(buffer, samples_count);

    return 0;
}
