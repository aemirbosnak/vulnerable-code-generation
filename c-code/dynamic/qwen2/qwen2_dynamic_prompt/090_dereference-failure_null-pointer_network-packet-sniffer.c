#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(unsigned char *packet, int length) {
    unsigned char *data = NULL;
    data = packet + 14; // Ethernet header length
    if (length < 60) {
        return;
    }
    printf("Packet Length: %d\n", length);
    printf("Source MAC: ");
    for (int i = 0; i < 6; i++) {
        printf("%02x:", data[i]);
    }
    printf("\n");
    data += 6; // Skip source MAC
    printf("Destination MAC: ");
    for (int i = 0; i < 6; i++) {
        printf("%02x:", data[i]);
    }
    printf("\n");
    data += 6; // Skip destination MAC
    printf("Protocol: ");
    if (ntohs(*(unsigned short *)data) == 0x0800) {
        printf("IPv4\n");
    } else if (ntohs(*(unsigned short *)data) == 0x0806) {
        printf("ARP\n");
    } else {
        printf("Unknown\n");
    }
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    while (1) {
        int length = read(0, buffer, BUFFER_SIZE); // Simulate reading from a socket
        if (length <= 0) {
            break;
        }
        process_packet(buffer, length);
    }
    return 0;
}
