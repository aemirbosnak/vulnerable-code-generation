#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void process_packet(char *packet) {
    char buffer[BUFFER_SIZE];
    gets(buffer); // Vulnerable to buffer overflow
}

int main() {
    char packet[2048];
    printf("Enter a network packet: ");
    fgets(packet, sizeof(packet), stdin);
    process_packet(packet);
    return 0;
}
