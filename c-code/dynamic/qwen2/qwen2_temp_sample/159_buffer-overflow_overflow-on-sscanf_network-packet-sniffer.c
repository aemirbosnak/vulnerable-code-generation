#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

void process_packet(char *packet) {
    char ip[16];
    int port;

    // Simulate receiving a packet
    strncpy(packet, "192.168.1.1:80", MAX_PACKET_SIZE);

    // Vulnerable sscanf call
    if (sscanf(packet, "%[^:]:%d", ip, &port) != 2) {
        fprintf(stderr, "Failed to parse packet\n");
        return;
    }

    printf("IP: %s, Port: %d\n", ip, port);
}

int main() {
    char packet[MAX_PACKET_SIZE];

    // Simulate reading a packet from a network interface
    fgets(packet, sizeof(packet), stdin);

    process_packet(packet);

    return 0;
}
