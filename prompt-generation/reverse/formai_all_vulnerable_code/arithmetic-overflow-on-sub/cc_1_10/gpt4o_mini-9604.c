//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024
#define PORT 8080
#define PACKETS_TO_SEND 10

typedef struct {
    int packet_id;
    struct timespec send_time;
    struct timespec receive_time;
} Packet;

void send_packet(int sockfd, struct sockaddr_in *server_addr, int packet_id) {
    Packet packet;
    packet.packet_id = packet_id;
    clock_gettime(CLOCK_MONOTONIC, &packet.send_time);
    
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }
}

void receive_packet(int sockfd, int packet_id) {
    Packet packet;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    struct sockaddr_in from_addr;

    if (recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&from_addr, &addr_len) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    
    clock_gettime(CLOCK_MONOTONIC, &packet.receive_time);
    
    long send_time_ns = packet.send_time.tv_sec * 1e9 + packet.send_time.tv_nsec;
    long receive_time_ns = packet.receive_time.tv_sec * 1e9 + packet.receive_time.tv_nsec;
    long latency = receive_time_ns - send_time_ns;

    printf("Packet ID: %d | Latency: %ld ns\n", packet_id, latency);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    printf("Starting QoS Monitor...\n");

    // Send and receive packets
    for (int i = 0; i < PACKETS_TO_SEND; i++) {
        send_packet(sockfd, &server_addr, i + 1);
        usleep(100000); // Sleep for 100 ms before receiving response
        receive_packet(sockfd, i + 1);
    }

    close(sockfd);
    printf("QoS Monitor finished.\n");
    return EXIT_SUCCESS;
}