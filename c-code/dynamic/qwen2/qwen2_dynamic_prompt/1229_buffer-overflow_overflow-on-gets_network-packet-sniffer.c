#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_packet(char *packet) {
    char buffer[10];
    gets(buffer); // Vulnerability: buffer overflow
}

int main() {
    char input[200];
    printf("Enter a packet data: ");
    fgets(input, sizeof(input), stdin);
    process_packet(input);
    return 0;
}
