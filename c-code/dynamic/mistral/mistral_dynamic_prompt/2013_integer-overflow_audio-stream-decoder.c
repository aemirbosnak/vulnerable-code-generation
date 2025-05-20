#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define PACKET_MAX 16

typedef struct {
    unsigned char header[8];
    unsigned short payload_len;
    unsigned char payload[BUFFER_SIZE];
} Packet;

int main(int argc, char *argv[]) {
    FILE *input_file;
    Packet packet;
    int i, j;

    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening input file");
        return 2;
    }

    while (fread(&packet, sizeof(Packet), 1, input_file)) {
        // Check if header is valid
        if (memcmp(packet.header, "FFRIENDS", 8)) continue;

        // Read oversized payload intentionally
        j = packet.payload_len + 1;
        for (i = packet.payload_len; i < j; i++) {
            packet.payload[i] = getc(input_file);
        }

        // Overflow occurred here
        // ... continue processing payload ...
    }

    fclose(input_file);
    return 0;
}
