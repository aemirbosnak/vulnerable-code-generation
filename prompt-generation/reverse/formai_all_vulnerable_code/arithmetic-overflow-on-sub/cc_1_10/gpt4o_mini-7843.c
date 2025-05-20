//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PACKET_SIZE 64
#define SERVER_PORT 8080
#define MONITOR_DURATION 30
#define TOTAL_PACKETS 100

void print_header() {
    printf("\n");
    printf("========================================\n");
    printf("         Network QoS Monitor           \n");
    printf("========================================\n");
    printf("Monitoring the network for %d seconds...\n", MONITOR_DURATION);
    printf("========================================\n");
    printf("Packet Size: %d bytes\n", PACKET_SIZE);
    printf("Server Port: %d\n", SERVER_PORT);
    printf("========================================\n\n");
}

void print_statistics(int sent, int received, double latency_sum) {
    double average_latency = latency_sum / received;
    double packet_loss = ((double)(sent - received) / sent) * 100;

    printf("========================================\n");
    printf("           QoS Statistics               \n");
    printf("========================================\n");
    printf("Packets Sent:      %d\n", sent);
    printf("Packets Received:  %d\n", received);
    printf("Average Latency:   %.2f ms\n", average_latency);
    printf("Packet Loss Rate:  %.2f%%\n", packet_loss);
    printf("========================================\n");
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char send_buffer[PACKET_SIZE];
    char recv_buffer[PACKET_SIZE];
    int sent_packets = 0, received_packets = 0;
    double total_latency = 0;
    clock_t start_time = clock();

    print_header();

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost for testing
    servaddr.sin_port = htons(SERVER_PORT);

    while ((((double)(clock() - start_time) / CLOCKS_PER_SEC) < MONITOR_DURATION) && (sent_packets < TOTAL_PACKETS)) {
        // Send packet
        sprintf(send_buffer, "Ping %d", sent_packets + 1);
        sent_packets++;

        clock_t send_time = clock();
        sendto(sockfd, send_buffer, strlen(send_buffer), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));

        // Receive response
        socklen_t len = sizeof(servaddr);
        if (recvfrom(sockfd, recv_buffer, PACKET_SIZE, 0, (struct sockaddr*)&servaddr, &len) >= 0) {
            clock_t receive_time = clock();
            received_packets++;
            double latency = ((double)(receive_time - send_time) / CLOCKS_PER_SEC) * 1000; // Convert to milliseconds
            total_latency += latency;

            printf("Received: %s (Latency: %.2f ms)\n", recv_buffer, latency);
        } else {
            printf("Packet %d lost.\n", sent_packets);
        }

        usleep(500000); // Wait for 0.5 second before sending next packet
    }

    print_statistics(sent_packets, received_packets, total_latency);

    close(sockfd);
    return 0;
}