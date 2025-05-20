#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(unsigned char *packet, int length) {
    unsigned char *data = packet + 14; // Skip Ethernet header
    int data_length = length - 14;

    if (data_length < 20) return; // Minimum IP header length

    unsigned char *ip_header = data;
    unsigned short ip_version = (ip_header[0] & 0xF0) >> 4;
    unsigned short ip_header_length = ((ip_header[0] & 0x0F) << 2) + 20;

    if (ip_version != 4 || ip_header_length > data_length) return;

    unsigned char *tcp_header = ip_header + ip_header_length;
    unsigned short tcp_header_length = ((tcp_header[12] & 0xF0) >> 2);

    if (tcp_header_length < 20) return;

    unsigned int source_ip = *(unsigned int *)(ip_header + 12);
    unsigned int destination_ip = *(unsigned int *)(ip_header + 16);
    unsigned short source_port = ntohs(*(unsigned short *)(tcp_header));
    unsigned short destination_port = ntohs(*(unsigned short *)(tcp_header + 2));

    printf("Source IP: %d.%d.%d.%d\n", (source_ip >> 24) & 0xFF, (source_ip >> 16) & 0xFF, (source_ip >> 8) & 0xFF, source_ip & 0xFF);
    printf("Destination IP: %d.%d.%d.%d\n", (destination_ip >> 24) & 0xFF, (destination_ip >> 16) & 0xFF, (destination_ip >> 8) & 0xFF, destination_ip & 0xFF);
    printf("Source Port: %d\n", source_port);
    printf("Destination Port: %d\n", destination_port);
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    int length = read(0, buffer, BUFFER_SIZE); // Simulate reading from a socket

    if (length <= 0) {
        fprintf(stderr, "Error reading packet\n");
        return 1;
    }

    process_packet(buffer, length);

    return 0;
}
