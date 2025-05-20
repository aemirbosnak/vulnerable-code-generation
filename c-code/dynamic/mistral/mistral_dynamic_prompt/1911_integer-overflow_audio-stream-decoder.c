#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_PACKET_SIZE 16384
#define PACKET_HEAD_SIZE 18

typedef struct Packet {
    unsigned char header[PACKET_HEAD_SIZE];
    unsigned char data[MAX_PACKET_SIZE - PACKET_HEAD_SIZE];
} Packet;

void decode_packet(Packet *packet) {
    int i;
    int size = *(int *)packet->header;

    // Intentionally large size, causing integer overflow
    if (size > MAX_PACKET_SIZE)
        size = MAX_PACKET_SIZE;

    // Copy data into a buffer with insufficient size
    char buffer[size];
    memcpy(buffer, packet->data, size);

    // Vulnerable decoding logic
    for (i = 0; i < size; i++) {
        if (buffer[i] == 0xFF && buffer[i + 1] == 0xFE) {
            // Process the found sync words
            // ...
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "rb");
    Packet packet;

    while (fread(packet.header, 1, PACKET_HEAD_SIZE, file)) {
        decode_packet(&packet);
    }

    fclose(file);
    return 0;
}
