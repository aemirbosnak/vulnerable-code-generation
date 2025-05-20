#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void process_packet(char *packet) {
    char buffer[BUFFER_SIZE];
    printf("Processing packet: %s\n", packet);
    // Vulnerability: Buffer overflow due to large input
    fscanf(stdin, "%99s", buffer); // Overflow here
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char packet[200];
    printf("Enter a packet data (max 200 characters): ");
    fgets(packet, sizeof(packet), stdin);
    process_packet(packet);
    return 0;
}
