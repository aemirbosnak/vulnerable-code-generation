#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(unsigned char *packet, int length) {
    unsigned char *ptr = packet;
    while (length > 0) {
        printf("%02x ", *(ptr++));
        if ((--length % 16) == 0) {
            printf("\n");
        }
    }
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    int packet_length;

    // Simulate receiving a packet
    packet_length = read(0, buffer, BUFFER_SIZE);

    if (packet_length <= 0) {
        return 1;
    }

    // Dereference an invalid pointer to cause a crash
    unsigned char *invalid_ptr = NULL;
    printf("Invalid pointer value: %p\n", (void *)invalid_ptr);
    printf("%02x\n", *invalid_ptr); // This will cause a segmentation fault

    // Process the packet
    process_packet(buffer, packet_length);

    return 0;
}
