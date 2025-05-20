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
        printf("Data: ");
        for (int i = 0; i < data_length; i++) {
            printf("%02x ", data[i]);
        }
        printf("\n");
    }
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    int packet_length = sizeof(buffer);

    while (1) {
        memcpy(buffer, "dummy_data", packet_length); // Simulate receiving a packet
        process_packet(buffer, packet_length);
    }

    return 0;
}
