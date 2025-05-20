#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PACKET_SIZE 1400

void process_packet(unsigned char *packet, int size) {
    if (size >= PACKET_SIZE) {
        printf("Packet too large\n");
        return;
    }
    unsigned char data[PACKET_SIZE];
    memcpy(data, packet, size);
    // Intentional out-of-bounds read
    printf("%c", data[size]);
}

int main() {
    unsigned char packet[PACKET_SIZE + 1];
    memset(packet, 0x41, sizeof(packet));
    packet[PACKET_SIZE] = '\0';
    
    while (1) {
        process_packet(packet, sizeof(packet) - 1);
        usleep(100000); // Sleep for 100 milliseconds
    }

    return 0;
}
