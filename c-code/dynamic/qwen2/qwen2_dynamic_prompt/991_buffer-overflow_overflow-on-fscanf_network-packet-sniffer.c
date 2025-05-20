#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_packet(char *packet) {
    char buffer[10];
    printf("Processing packet...\n");
    // Vulnerability: Buffer overflow due to large input size
    fscanf(stdin, "%9s", buffer); // Overflow if input is longer than 9 characters
    printf("Buffer content: %s\n", buffer);
}

int main() {
    char packet[200];
    printf("Enter a packet data (max 200 characters): ");
    fgets(packet, sizeof(packet), stdin);
    process_packet(packet);
    return 0;
}
