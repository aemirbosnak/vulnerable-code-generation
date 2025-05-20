#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

void process_packet(unsigned char *packet, int length) {
    // Simulate processing a packet
    printf("Packet received: ");
    for (int i = 0; i < length; i++) {
        printf("%02x ", packet[i]);
    }
    printf("\n");
}

int main() {
    unsigned char buffer[BUFSIZE];
    int length;

    while (1) {
        // Simulate receiving a packet
        length = fread(buffer, 1, BUFSIZE, stdin);
        if (length <= 0) break;

        // Process the packet without bounds checking
        process_packet(buffer, length);

        // Deliberate dereference failure
        unsigned char *ptr = NULL;
        *ptr = 0; // This will cause a segmentation fault
    }

    return 0;
}
