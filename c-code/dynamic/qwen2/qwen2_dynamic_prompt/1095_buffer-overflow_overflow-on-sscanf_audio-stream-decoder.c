#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void decode_audio_stream(const char *stream) {
    char buffer[BUFFER_SIZE];
    int volume;
    float balance;

    // Simulate decoding process
    if (sscanf(stream, "%d %f", &volume, &balance) != 2) {
        fprintf(stderr, "Error parsing audio stream\n");
        return;
    }

    // Deliberate buffer overflow vulnerability
    snprintf(buffer, sizeof(buffer), "Volume: %d, Balance: %.2f", volume, balance);

    printf("%s\n", buffer);
}

int main() {
    const char *audio_stream = "100 0.5";
    decode_audio_stream(audio_stream);
    return 0;
}
