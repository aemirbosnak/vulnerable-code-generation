#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(char *packet) {
    char src_ip[BUFFER_SIZE], dst_ip[BUFFER_SIZE];
    int src_port, dst_port;

    // Simulate parsing a packet
    if (sscanf(packet, "IP %[^ ] %d -> IP %[^ ] %d", src_ip, &src_port, dst_ip, &dst_port) != 4) {
        printf("Packet format error\n");
        return;
    }

    // Buffer overflow vulnerability here
    char vulnerable_buffer[64];
    snprintf(vulnerable_buffer, sizeof(vulnerable_buffer), "%s:%d -> %s:%d", src_ip, src_port, dst_ip, dst_port);

    printf("Parsed packet: %s\n", vulnerable_buffer);
}

int main() {
    char packet[BUFFER_SIZE];

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
