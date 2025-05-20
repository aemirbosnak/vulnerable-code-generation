//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65536

// Struct to store network statistics
typedef struct {
    int total_packets_sent;
    int total_packets_received;
    int total_bytes_sent;
    int total_bytes_received;
    double average_packet_size_sent;
    double average_packet_size_received;
    double packet_loss_ratio;
} NetworkStats;

// Function to calculate network stats
void calculateNetworkStats(char* ip, int port) {
    NetworkStats stats = {0};
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char packet[MAX_PACKET_SIZE] = {0};

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        perror("Error setting server address");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Start sending and receiving packets
    while (1) {
        // Generate random packet of random size between 1 and MAX_PACKET_SIZE
        int packet_size = rand() % MAX_PACKET_SIZE + 1;
        for (int i = 0; i < packet_size; i++) {
            packet[i] = rand() % 256;
        }

        // Send packet
        n = send(sockfd, packet, packet_size, 0);
        if (n < 0) {
            perror("Error sending packet");
            exit(1);
        }

        // Update stats
        stats.total_packets_sent++;
        stats.total_bytes_sent += n;
        stats.average_packet_size_sent = ((stats.average_packet_size_sent * (stats.total_packets_sent - 1)) + n) / stats.total_packets_sent;

        // Receive packet
        n = recv(sockfd, packet, sizeof(packet), 0);
        if (n < 0) {
            perror("Error receiving packet");
            exit(1);
        } else if (n == 0) {
            // Connection closed by server
            break;
        }

        // Update stats
        stats.total_packets_received++;
        stats.total_bytes_received += n;
        stats.average_packet_size_received = ((stats.average_packet_size_received * (stats.total_packets_received - 1)) + n) / stats.total_packets_received;
    }

    // Calculate packet loss ratio
    stats.packet_loss_ratio = ((double)(stats.total_packets_sent - stats.total_packets_received) / stats.total_packets_sent) * 100.0;

    // Print results
    printf("Network Statistics:\n");
    printf("IP Address: %s\n", ip);
    printf("Port: %d\n", port);
    printf("Total Packets Sent: %d\n", stats.total_packets_sent);
    printf("Total Packets Received: %d\n", stats.total_packets_received);
    printf("Total Bytes Sent: %d\n", stats.total_bytes_sent);
    printf("Total Bytes Received: %d\n", stats.total_bytes_received);
    printf("Average Packet Size Sent: %.2f bytes\n", stats.average_packet_size_sent);
    printf("Average Packet Size Received: %.2f bytes\n", stats.average_packet_size_received);
    printf("Packet Loss Ratio: %.2f%%\n", stats.packet_loss_ratio);

    // Close socket
    close(sockfd);
}

int main() {
    // Example usage
    char* ip = "127.0.0.1";
    int port = 8080;
    calculateNetworkStats(ip, port);
    return 0;
}