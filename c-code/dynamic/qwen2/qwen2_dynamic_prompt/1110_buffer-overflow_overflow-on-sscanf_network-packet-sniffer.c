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
        return;
    }

    // Buffer overflow vulnerability here
    char output[100];
    snprintf(output, sizeof(output), "Source: %s:%d, Destination: %s:%d\n", src_ip, src_port, dst_ip, dst_port);

    printf("%s", output);
}

int main() {
    char packet[BUFFER_SIZE];

    while (1) {
        printf("Enter packet data: ");
        fgets(packet, sizeof(packet), stdin);
        process_packet(packet);
    }

    return 0;
}
