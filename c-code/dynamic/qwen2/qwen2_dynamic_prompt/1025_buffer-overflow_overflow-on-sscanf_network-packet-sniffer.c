#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void process_packet(char *packet) {
    char buffer[BUFFER_SIZE];
    if (sscanf(packet, "%s", buffer) == 1) {
        printf("Received: %s\n", buffer);
    } else {
        printf("Failed to parse packet.\n");
    }
}

int main() {
    char input[200];
    while (1) {
        printf("Enter packet data: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        process_packet(input);
    }
    return 0;
}
