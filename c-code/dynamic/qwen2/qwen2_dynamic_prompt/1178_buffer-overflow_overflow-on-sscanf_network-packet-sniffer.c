#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(const char *packet) {
    char src_ip[BUFFER_SIZE];
    char dst_ip[BUFFER_SIZE];
    int port;

    // Simulate receiving a packet
    if (sscanf(packet, "Packet from %[^:]:%d to %s", src_ip, &port, dst_ip) != 3) {
        return;
    }

    // Buffer overflow vulnerability here
    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dst_ip);
    printf("Port: %d\n", port);
}

int main() {
    char packet[BUFFER_SIZE];

    // Simulate receiving a malicious packet
    strcpy(packet, "Packet from 192.168.1.1:65535 to 10.0.0.1");

    process_packet(packet);

    return 0;
}
