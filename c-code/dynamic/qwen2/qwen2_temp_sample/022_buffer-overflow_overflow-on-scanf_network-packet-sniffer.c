#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void process_packet(char *packet) {
    char buffer[BUFFER_SIZE];
    printf("Received packet: %s\n", packet);
    // Vulnerability: Buffer overflow due to insufficient bounds checking
    strcpy(buffer, packet); // This will overflow if packet is longer than BUFFER_SIZE - 1
}

int main() {
    char input[256];
    printf("Enter a packet data (max 255 characters): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    process_packet(input);
    return 0;
}
