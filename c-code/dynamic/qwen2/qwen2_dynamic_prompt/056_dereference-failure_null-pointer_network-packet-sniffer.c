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

    if (data == NULL) {
        printf("Packet data is null\n");
        return;
    }

    if (data_length <= 0) {
        printf("No data in packet\n");
        return;
    }

    printf("Data: ");
    for (int i = 0; i < data_length; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    int packet_count = 0;

    while (1) {
        int length = read(0, buffer, BUFFER_SIZE);
        if (length <= 0) {
            break;
        }

        packet_count++;
        process_packet(buffer, length);

        if (packet_count >= 10) {
            break;
        }
    }

    return 0;
}
