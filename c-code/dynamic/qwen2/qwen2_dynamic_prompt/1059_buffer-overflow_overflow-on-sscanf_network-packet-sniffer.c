#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

void process_packet(char *packet) {
    char src_ip[16], dst_ip[16];
    int protocol;

    if (sscanf(packet, "IP %15s -> %15s Protocol: %d", src_ip, dst_ip, &protocol) != 3) {
        printf("Error parsing packet\n");
        return;
    }

    // Vulnerability: Buffer overflow due to lack of bounds checking
    char buffer[MAX_PACKET_SIZE];
    strcpy(buffer, packet);

    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dst_ip);
    printf("Protocol: %d\n", protocol);
}

int main() {
    char packet[MAX_PACKET_SIZE];

    while (1) {
        printf("Enter packet data (or 'exit' to quit): ");
        fgets(packet, sizeof(packet), stdin);

        if (strncmp(packet, "exit", 4) == 0) {
            break;
        }

        process_packet(packet);
    }

    return 0;
}
