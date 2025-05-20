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
    fscanf(packet, "%s", buffer); // Vulnerable to buffer overflow
}

int main() {
    char input[200];
    printf("Enter a packet data: ");
    fgets(input, sizeof(input), stdin);
    process_packet(input);
    return 0;
}
