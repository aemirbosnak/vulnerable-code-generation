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

    // Simulate parsing a packet to extract source IP, destination IP, and protocol
    if (sscanf(packet, "IP %15s -> %15s Protocol: %d", src_ip, dst_ip, &protocol) != 3) {
        fprintf(stderr, "Error parsing packet\n");
        return;
    }

    // Vulnerability: Buffer overflow due to insufficient check on input length
    char buffer[8];
    snprintf(buffer, sizeof(buffer), "%s:%s:%d", src_ip, dst_ip, protocol);

    printf("Packet processed: %s\n", buffer);
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
