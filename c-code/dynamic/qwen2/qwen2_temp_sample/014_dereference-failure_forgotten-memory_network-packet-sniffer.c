#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(unsigned char* packet, int length) {
    unsigned char* data = packet + 14; // Skip Ethernet header
    int offset = 0;

    while (offset < length - 20) { // Skip IP header
        if (data[offset] == 6) { // TCP protocol
            unsigned short source_port = ntohs(*(unsigned short*)(data + offset + 2));
            unsigned short dest_port = ntohs(*(unsigned short*)(data + offset + 4));
            printf("Source Port: %d, Dest Port: %d\n", source_port, dest_port);
            break;
        }
        offset += 20; // Move to next header
    }
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    int bytes_read;

    while (1) {
        bytes_read = read(0, buffer, BUFFER_SIZE); // Simulate reading from a socket
        if (bytes_read <= 0) {
            break;
        }
        process_packet(buffer, bytes_read);
    }

    return 0;
}
