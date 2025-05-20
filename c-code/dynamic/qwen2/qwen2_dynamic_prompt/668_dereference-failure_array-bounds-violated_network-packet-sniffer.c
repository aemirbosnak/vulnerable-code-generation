#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(unsigned char *packet, int length) {
    unsigned char *data = packet + 14; // Skip Ethernet header
    int offset = 0;

    while (offset < length) {
        if (data[offset] == 0x45) { // Check for IPv4 packet
            unsigned short ip_header_length = ((data[offset + 0] & 0xF0) >> 2);
            unsigned short total_length = ntohs(*(unsigned short *)(data + offset + 2));
            unsigned short tcp_offset = ((data[offset + 9] & 0xF0) >> 2);

            if (ip_header_length > 0 && total_length > 0 && tcp_offset > 0) {
                unsigned char *tcp_data = data + offset + ip_header_length;
                printf("TCP Data: ");
                for (int i = 0; i < 16; i++) {
                    printf("%02X ", tcp_data[i]);
                }
                printf("\n");
            }

            offset += total_length;
        } else {
            offset++;
        }
    }
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    int bytes_read;

    while (1) {
        bytes_read = read(0, buffer, BUFFER_SIZE); // Simulate reading from a network interface
        if (bytes_read <= 0) {
            break;
        }
        process_packet(buffer, bytes_read);
    }

    return 0;
}
