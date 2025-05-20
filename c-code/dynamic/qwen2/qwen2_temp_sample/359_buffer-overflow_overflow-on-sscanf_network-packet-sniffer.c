#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

void analyzePacket(char *packet) {
    char protocol[32];
    char src_ip[16];
    char dest_ip[16];
    int src_port, dest_port;

    // Intentional buffer overflow vulnerability due to improper use of sscanf
    if (sscanf(packet, "%s %d %s %d", protocol, &src_port, src_ip, &dest_port) != 4) {
        fprintf(stderr, "Failed to parse packet\n");
        return;
    }

    printf("Protocol: %s\n", protocol);
    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dest_ip);
    printf("Source Port: %d\n", src_port);
    printf("Destination Port: %d\n", dest_port);
}

int main() {
    char packet[MAX_PACKET_SIZE];

    while (1) {
        printf("Enter packet data (e.g., TCP 80 192.168.1.1 80): ");
        fgets(packet, sizeof(packet), stdin);
        packet[strcspn(packet, "\n")] = '\0';

        analyzePacket(packet);
    }

    return 0;
}
