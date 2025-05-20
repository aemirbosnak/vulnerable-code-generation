#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(unsigned char *packet, int length) {
    unsigned int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += packet[i];
    }
    printf("Sum: %u\n", sum);
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    int packet_length = 1024;

    // Simulate receiving a packet
    memset(buffer, 0xFF, sizeof(buffer));

    // Process the packet
    process_packet(buffer, packet_length);

    return 0;
}
