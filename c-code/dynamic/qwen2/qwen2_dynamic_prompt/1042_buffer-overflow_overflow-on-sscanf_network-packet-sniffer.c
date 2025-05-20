#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(char *packet) {
    char source_ip[BUFFER_SIZE];
    int port;

    // Simulate receiving a packet
    strcpy(packet, "192.168.1.1:80 HTTP/1.1\r\n");

    // Vulnerable sscanf call
    if (sscanf(packet, "%[^:]:%d", source_ip, &port) != 2) {
        printf("Failed to parse packet.\n");
        return;
    }

    // Print parsed information
    printf("Source IP: %s\n", source_ip);
    printf("Port: %d\n", port);
}

int main() {
    char packet[BUFFER_SIZE];

    // Simulate receiving packets
    while (1) {
        process_packet(packet);
    }

    return 0;
}
