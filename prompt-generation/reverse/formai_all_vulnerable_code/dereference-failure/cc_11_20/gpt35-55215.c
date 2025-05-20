//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

#define PACKET_SIZE 1024 // Payload size in bytes
#define HEADER_SIZE sizeof(packet_header_t) // Packet header size in bytes

typedef struct {
    uint32_t sequence_number;
    uint32_t time_stamp;
} packet_header_t;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);
    double throughput = 0.0, latency = 0.0;
    uint32_t sequence_number = 0;

    srand(time(NULL)); // Seed random number generator

    // Create socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set socket options
    int send_timeout = 10000; // 10 seconds
    int recv_timeout = 10000; // 10 seconds
    struct timeval timeout;

    timeout.tv_sec = send_timeout / 1000;
    timeout.tv_usec = (send_timeout % 1000) * 1000;
    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        perror("setsockopt (send_timeout)");
        return 1;
    }

    timeout.tv_sec = recv_timeout / 1000;
    timeout.tv_usec = (recv_timeout % 1000) * 1000;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        perror("setsockopt (recv_timeout)");
        return 1;
    }

    // Set IP address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(ip_address, &server_addr.sin_addr);

    while (1) {
        uint8_t *payload = malloc(PACKET_SIZE);
        if (!payload) {
            printf("Error: Insufficient memory!\n");
            return 1;
        }

        // Generate random payload
        for (int i = 0; i < PACKET_SIZE; i++) {
            payload[i] = rand() % 256;
        }

        // Create packet header
        packet_header_t header = {
            .sequence_number = sequence_number++,
            .time_stamp = time(NULL)
        };

        // Convert packet header to network byte order
        header.sequence_number = htonl(header.sequence_number);
        header.time_stamp = htonl(header.time_stamp);

        // Combine header and payload into a single buffer
        uint8_t *packet = malloc(HEADER_SIZE + PACKET_SIZE);
        if (!packet) {
            printf("Error: Insufficient memory!\n");
            return 1;
        }

        memcpy(packet, &header, HEADER_SIZE);
        memcpy(packet + HEADER_SIZE, payload, PACKET_SIZE);

        // Send packet to server
        int bytes_sent = sendto(sock, packet, HEADER_SIZE + PACKET_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (bytes_sent < 0) {
            perror("sendto");
            return 1;
        }

        // Receive response from server
        uint8_t buffer[HEADER_SIZE];
        int bytes_received = recvfrom(sock, buffer, HEADER_SIZE, 0, NULL, NULL);
        if (bytes_received < 0) {
            perror("recvfrom");
            return 1;
        }

        // Convert packet header to host byte order
        packet_header_t response_header;
        memcpy(&response_header, buffer, HEADER_SIZE);
        response_header.sequence_number = ntohl(response_header.sequence_number);
        response_header.time_stamp = ntohl(response_header.time_stamp);

        // Calculate latency and throughput
        latency = (latency * (double)(sequence_number - 1) + difftime(time(NULL), response_header.time_stamp)) / sequence_number;
        throughput = (throughput * (double)(sequence_number - 1) + (double)bytes_sent) / sequence_number / 1024;

        free(payload);
        free(packet);

        // Print statistics every 10 packets
        if (sequence_number % 10 == 0) {
            printf("Packets sent: %d, Latency: %.1lf ms, Throughput: %.1lf KB/s\n", sequence_number, latency * 1000, throughput);
        }
    }

    return 0;
}