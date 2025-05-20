#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PACKET_SIZE 1024

void process_packet(char *packet) {
    char buffer[128];
    printf("Received packet: %s\n", packet);
    // Vulnerability: Buffer overflow due to insufficient bounds checking
    scanf("%127s", buffer); // Overflows if packet is longer than 127 characters
}

int main() {
    char packet[MAX_PACKET_SIZE];

    while (1) {
        printf("Enter packet data (or 'exit' to quit): ");
        fgets(packet, sizeof(packet), stdin);

        if (strcmp(packet, "exit\n") == 0) {
            break;
        }

        process_packet(packet);
    }

    return 0;
}
