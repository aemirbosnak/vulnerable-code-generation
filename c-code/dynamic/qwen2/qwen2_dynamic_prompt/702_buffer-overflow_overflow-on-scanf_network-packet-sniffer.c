#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void process_packet(char *packet) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, packet);
}

int main() {
    char input[200];
    printf("Enter a network packet: ");
    scanf("%s", input); // Vulnerability here: no bounds checking
    process_packet(input);
    return 0;
}
