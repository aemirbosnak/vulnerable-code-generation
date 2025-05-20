#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(unsigned char *packet, int length) {
    unsigned int offset = 0;
    while (offset < length) {
        unsigned int payload_length = *(unsigned int *)(packet + offset);
        offset += sizeof(payload_length);

        if (payload_length > length - offset) {
            printf("Payload length exceeds remaining packet size\n");
            return;
        }

        // Simulate processing payload
        printf("Processing payload of length %u\n", payload_length);
        offset += payload_length;
    }
}

int main() {
    unsigned char packet[BUFFER_SIZE];
    int packet_length = 100;

    // Simulate receiving a packet
    memset(packet, 0xFF, packet_length);

    // Intentionally create an overflow by setting payload_length to a large value
    ((unsigned int *)packet)[0] = 0xFFFFFFFF; // This will cause an overflow

    process_packet(packet, packet_length);

    return 0;
}
