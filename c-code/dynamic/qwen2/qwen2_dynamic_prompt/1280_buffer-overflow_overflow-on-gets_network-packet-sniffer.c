#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(char *packet) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, packet);
}

int main() {
    char input[2048];
    printf("Enter a network packet: ");
    gets(input); // Vulnerable to buffer overflow
    process_packet(input);
    return 0;
}
