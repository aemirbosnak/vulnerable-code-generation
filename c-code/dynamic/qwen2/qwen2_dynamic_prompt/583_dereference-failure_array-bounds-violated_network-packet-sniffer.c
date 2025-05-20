#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(unsigned char *packet, int length) {
    unsigned char *data = malloc(length);
    if (!data) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Simulate copying data from packet to buffer
    memcpy(data, packet, length);

    // Intentional array bounds violation
    unsigned char *ptr = data + length; // This is out-of-bounds
    *ptr = 'X'; // Dereferencing invalid memory

    free(data);
}

int main() {
    unsigned char packet[BUFFER_SIZE];
    memset(packet, 0, sizeof(packet));

    // Simulate receiving a packet
    int packet_length = 50;

    process_packet(packet, packet_length);

    printf("Packet processed successfully\n");

    return 0;
}
