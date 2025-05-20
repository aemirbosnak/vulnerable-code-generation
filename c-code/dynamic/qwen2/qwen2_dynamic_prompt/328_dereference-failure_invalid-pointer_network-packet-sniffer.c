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
    int length;

    // Simulate receiving a packet
    length = read(0, buffer, BUFFER_SIZE);

    if (length <= 0) {
        return 1;
    }

    // Intentionally create an invalid pointer to demonstrate dereference failure
    unsigned char *invalid_ptr = NULL;
    unsigned char *valid_ptr = buffer + length; // This is invalid as it points beyond the buffer

    // Dereference the invalid pointer
    printf("Invalid Pointer Value: %02x\n", *invalid_ptr); // This will cause a segmentation fault

    // Process the packet using a valid pointer
    process_packet(valid_ptr, length);

    return 0;
}
