#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    size_t length;
} AudioPacket;

AudioPacket* decode_audio(const char *stream) {
    AudioPacket *packet = (AudioPacket*)malloc(sizeof(AudioPacket));
    if (!packet) return NULL;

    packet->length = strlen(stream);
    packet->data = (char*)malloc(packet->length + 1);
    if (!packet->data) {
        free(packet);
        return NULL;
    }

    strcpy(packet->data, stream);

    // Simulate decoding process
    for (size_t i = 0; i < packet->length; ++i) {
        packet->data[i] += 1; // Increment each byte to simulate decoding
    }

    return packet;
}

void play_audio(AudioPacket *packet) {
    if (packet && packet->data) {
        printf("Playing audio: %s\n", packet->data);
    }
}

int main() {
    const char *audio_stream = "Sample audio data";
    AudioPacket *decoded_packet = decode_audio(audio_stream);

    if (decoded_packet) {
        play_audio(decoded_packet);
        free(decoded_packet->data); // Free the allocated memory
        decoded_packet->data = NULL; // Set pointer to NULL after freeing
    } else {
        fprintf(stderr, "Failed to decode audio.\n");
        return 1;
    }

    // Use after free vulnerability
    play_audio(decoded_packet); // This will cause undefined behavior

    return 0;
}
