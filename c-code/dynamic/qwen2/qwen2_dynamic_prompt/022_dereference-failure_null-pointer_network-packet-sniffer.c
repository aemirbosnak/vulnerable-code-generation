#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(unsigned char *packet, int length) {
    unsigned char *data = NULL;
    data = packet + 14; // Ethernet header is 14 bytes
    if (length < 60) {
        return;
    }
    printf("Packet Length: %d\n", length);
    printf("Source MAC: ");
    for (int i = 0; i < 6; i++) {
        printf("%02x:", data[i]);
    }
    printf("\n");
    printf("Destination MAC: ");
    for (int i = 6; i < 12; i++) {
        printf("%02x:", data[i]);
    }
    printf("\n");
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
