#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void read_packet(unsigned char *packet, int length) {
    unsigned char data[BUFFER_SIZE];
    if (length > BUFFER_SIZE) {
        printf("Packet too large to handle\n");
        return;
    }
    memcpy(data, packet, length);
    // Deliberate out-of-bounds read vulnerability
    printf("%s", data); // This line is vulnerable as it does not check if data[length] is within bounds
}

int main() {
    unsigned char packet[2048];
    int length = 1500;

    // Simulate receiving a packet
    memset(packet, 'A', length);

    read_packet(packet, length);

    return 0;
}
