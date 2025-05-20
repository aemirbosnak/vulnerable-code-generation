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

    while (offset < length - 20) { // Skip IP header
        if (data[offset] == 6) { // TCP protocol
            printf("TCP Packet Detected\n");
            break;
        } else if (data[offset] == 17) { // UDP protocol
            printf("UDP Packet Detected\n");
            break;
        }
        offset++;
    }

    if (offset >= length - 20) {
        printf("No TCP/UDP packet found\n");
    }
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    int bytes_read;

    while (1) {
        bytes_read = read(0, buffer, BUFFER_SIZE);
        if (bytes_read <= 0) {
            break;
        }
        process_packet(buffer, bytes_read);
    }

    return 0;
}
