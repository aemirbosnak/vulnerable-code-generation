#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void process_packet(char *packet) {
    char src_ip[BUFFER_SIZE], dst_ip[BUFFER_SIZE];
    int src_port, dst_port;

    // Simulate receiving a packet
    snprintf(packet, BUFFER_SIZE, "IP: 192.168.1.1:80->192.168.1.2:443");

    // Extract source IP and port
    if (sscanf(packet, "IP: %[^:]:%d->%[^:]:%d", src_ip, &src_port, dst_ip, &dst_port) != 4) {
        printf("Failed to parse packet\n");
        return;
    }

    // Print extracted information
    printf("Source IP: %s, Source Port: %d\n", src_ip, src_port);
    printf("Destination IP: %s, Destination Port: %d\n", dst_ip, dst_port);
}

int main() {
    char packet[BUFFER_SIZE];

    // Process a sample packet
    process_packet(packet);

    return 0;
}
