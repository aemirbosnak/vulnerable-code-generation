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
    strcpy(buffer, packet); // Vulnerable to buffer overflow
}

int main() {
    char input[200];
    printf("Enter a packet data: ");
    scanf("%s", input); // Potential buffer overflow here
    process_packet(input);
    return 0;
}
