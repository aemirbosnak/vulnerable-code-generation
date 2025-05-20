#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(unsigned char *packet, int length) {
    unsigned char *data = packet + 14; // Skip Ethernet header
    int offset = 0;

    while (offset < length) {
        if (data[offset] == 0x80 && data[offset + 1] == 0x00) { // IPv4
            unsigned char *ip_header = data + offset;
            int ip_length = ((ip_header[0] & 0xF) << 2) + 4;
            offset += ip_length;

            if (offset >= length) break;

            if (data[offset] == 0x06) { // TCP
                unsigned char *tcp_header = data + offset;
                int tcp_length = ((tcp_header[12] & 0xF) << 2);
                offset += tcp_length;

                if (offset >= length) break;

                // Deliberate array bounds violation
                unsigned char *payload = data + offset;
                printf("Payload: %s\n", payload);
                printf("%d\n", payload[BUFFER_SIZE]); // Vulnerability here
            }
        } else {
            offset++;
        }
    }
}

int main() {
    unsigned char packet[BUFFER_SIZE];
    int length = 1500;

    // Simulate receiving a packet
    memset(packet, 0, BUFFER_SIZE);
    packet[0] = 0x00; packet[1] = 0x01; packet[2] = 0x02; packet[3] = 0x03; packet[4] = 0x04; packet[5] = 0x05;
    packet[6] = 0x00; packet[7] = 0x01; packet[8] = 0x02; packet[9] = 0x03; packet[10] = 0x04; packet[11] = 0x05;
    packet[12] = 0x08; packet[13] = 0x00; // Ethernet type: IP

    process_packet(packet, length);

    return 0;
}
