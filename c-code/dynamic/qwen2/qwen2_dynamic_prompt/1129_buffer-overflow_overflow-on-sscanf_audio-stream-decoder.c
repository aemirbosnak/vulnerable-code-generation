#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void decode_audio_stream(const char *stream) {
    char buffer[128];
    int volume;
    float balance;

    // Simulate decoding process
    if (sscanf(stream, "%d %f", &volume, &balance) != 2) {
        fprintf(stderr, "Error parsing audio stream\n");
        return;
    }

    // Vulnerability: Buffer overflow due to insufficient buffer size
    snprintf(buffer, sizeof(buffer), "Volume: %d, Balance: %.2f", volume, balance);

    printf("%s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <audio_stream>\n", argv[0]);
        return 1;
    }

    decode_audio_stream(argv[1]);

    return 0;
}
