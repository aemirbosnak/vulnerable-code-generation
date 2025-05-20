//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: standalone
// C Network Packet Monitoring Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>

// Structure for storing packet information
struct packet_info {
    struct sockaddr_in source_addr;
    struct sockaddr_in dest_addr;
    unsigned char protocol;
    unsigned char *data;
    size_t data_len;
};

// Function to print packet information
void print_packet(struct packet_info *packet) {
    printf("Source address: %s:%d\n", inet_ntoa(packet->source_addr.sin_addr), ntohs(packet->source_addr.sin_port));
    printf("Destination address: %s:%d\n", inet_ntoa(packet->dest_addr.sin_addr), ntohs(packet->dest_addr.sin_port));
    printf("Protocol: %d\n", packet->protocol);
    printf("Data: %s\n", packet->data);
}

// Function to capture packets from a socket
void capture_packets(int sock) {
    struct sockaddr_in source_addr;
    socklen_t source_len = sizeof(source_addr);
    struct sockaddr_in dest_addr;
    socklen_t dest_len = sizeof(dest_addr);
    unsigned char buffer[1500];
    ssize_t bytes_read;
    struct packet_info packet;

    while (1) {
        // Receive packet from socket
        bytes_read = recvfrom(sock, buffer, 1500, 0, (struct sockaddr *)&source_addr, &source_len);
        if (bytes_read == -1) {
            perror("recvfrom");
            exit(1);
        }

        // Get protocol and source/destination addresses
        packet.protocol = buffer[9];
        memcpy(&packet.source_addr, &source_addr, sizeof(struct sockaddr_in));
        memcpy(&packet.dest_addr, &dest_addr, sizeof(struct sockaddr_in));

        // Get data from packet
        packet.data_len = bytes_read - 40;
        packet.data = buffer + 40;

        // Print packet information
        print_packet(&packet);
    }
}

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in address;

    // Create socket
    sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Set address and bind
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = 0;
    if (bind(sock, (struct sockaddr *)&address, sizeof(struct sockaddr_in)) == -1) {
        perror("bind");
        exit(1);
    }

    // Capture packets
    capture_packets(sock);

    return 0;
}