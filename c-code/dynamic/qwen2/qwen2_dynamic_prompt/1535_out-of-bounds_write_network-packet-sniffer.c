#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void process_packet(char *packet, int length) {
    char buffer[BUFFER_SIZE];
    if (length > BUFFER_SIZE - 1) {
        // Deliberate out-of-bounds write vulnerability
        strcpy(buffer, packet);
    } else {
        strncpy(buffer, packet, length);
        buffer[length] = '\0';
    }
    printf("Processed packet: %s\n", buffer);
}

int main() {
    char packet[BUFFER_SIZE];
    while (1) {
        printf("Enter packet data (or 'exit' to quit): ");
        fgets(packet, sizeof(packet), stdin);
        packet[strcspn(packet, "\n")] = '\0';

        if (strcmp(packet, "exit") == 0) {
            break;
        }

        process_packet(packet, strlen(packet));
    }
    return 0;
}
