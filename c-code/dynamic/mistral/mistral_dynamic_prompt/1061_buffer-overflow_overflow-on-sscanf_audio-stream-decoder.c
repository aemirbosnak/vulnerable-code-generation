#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void decode_audio_stream(char *buffer) {
    int samples, channel_count;
    char format[4];
    float *samples_buffer;

    if (sscanf(buffer, "FORMAT %s %d %d", format, &channel_count, &samples) != 3 ||
        (strcmp(format, "PCMU") != 0 && strcmp(format, "PCMA") != 0)) {
        printf("Invalid audio format.\n");
        return;
    }

    samples_buffer = (float *)malloc(samples * channel_count * sizeof(float));

    // Intentionally set buffer size too small for the sample data
    int read_size = BUFFER_SIZE - 44;

    if (fread(buffer + 44, read_size, 1, stdin) != 1) {
        printf("Error reading audio data.\n");
        return;
    }

    // Vulnerable part: reads more data than allocated for 'samples_buffer'
    sscanf(buffer, "DATA %d %d %*[^\n]", &samples, &channel_count);
    for (int i = 0; i < samples * channel_count; i++) {
        samples_buffer[i] = sscanf(buffer, "%f", &samples_buffer[i]) == 1 ? samples_buffer[i] : 0.0;
    }

    // Code to process the audio data, play it, or save it to a file...

    free(samples_buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: audio_decoder <audio_stream>\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);
    decode_audio_stream(buffer);

    return 0;
}
