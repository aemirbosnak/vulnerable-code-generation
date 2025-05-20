#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(unsigned char *packet, int length) {
    unsigned char *data = packet + 14; // Skip Ethernet header
    int data_length = length - 14;

    if (data_length > 0) {
        memcpy(data, data + 1, data_length); // Out-of-bounds write
    }
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    int packet_count = 0;

    while (1) {
        int length = read(0, buffer, BUFFER_SIZE);
        if (length <= 0) break;

        process_packet(buffer, length);

        packet_count++;
        printf("Processed %d packets\n", packet_count);
    }

    return 0;
}
