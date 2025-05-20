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
    int length;

    // Simulate receiving a packet
    printf("Enter packet length: ");
    scanf("%d", &length);
    if (length > BUFFER_SIZE) {
        fprintf(stderr, "Packet too large\n");
        return 1;
    }
    printf("Enter packet data: ");
    fread(packet, 1, length, stdin);

    process_packet(packet, length);

    return 0;
}
