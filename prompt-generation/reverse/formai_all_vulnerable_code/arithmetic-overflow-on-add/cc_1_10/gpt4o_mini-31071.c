//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netinet/in.h>

#define PORT 8080
#define PACKET_SIZE 1024
#define NUM_PACKETS 10
#define TIMEOUT 2

void print_statistics(double loss_rate, double avg_latency, double bandwidth) {
    printf("\n--- Network Quality of Service Statistics ---\n");
    printf("Packet Loss Rate: %.2f%%\n", loss_rate);
    printf("Average Latency: %.2f ms\n", avg_latency);
    printf("Bandwidth: %.2f Kbps\n", bandwidth);
}

double get_current_time() {
    struct timeval time_now;
    gettimeofday(&time_now, NULL);
    return (double)time_now.tv_sec * 1000 + (double)time_now.tv_usec / 1000; // Convert to milliseconds
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[PACKET_SIZE];
    double latencies[NUM_PACKETS];
    int packets_sent = 0, packets_received = 0;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Start sending packets...\n");

    for (int i = 0; i < NUM_PACKETS; i++) {
        double send_time = get_current_time();
        sprintf(buffer, "Packet %d", i + 1);
        int bytes_sent = sendto(sockfd, buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&client_addr, sizeof(client_addr));
        packets_sent++;

        fd_set readfds;
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        int retval = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
        if (retval == -1) {
            perror("Select error");
        } else if (retval == 0) {
            printf("Packet %d lost\n", i + 1);
        } else {
            int len = sizeof(client_addr);
            int bytes_received = recvfrom(sockfd, buffer, PACKET_SIZE, MSG_WAITALL, (struct sockaddr *)&client_addr, &len);
            if (bytes_received >= 0) {
                double receive_time = get_current_time();
                latencies[packets_received] = receive_time - send_time;
                packets_received++;
                printf("Received response for packet %d\n", i + 1);
            }
        }
    }

    // Calculating statistics
    double loss_rate = ((double)(NUM_PACKETS - packets_received) / NUM_PACKETS) * 100;
    double avg_latency = 0;
    if (packets_received > 0) {
        for (int i = 0; i < packets_received; i++) {
            avg_latency += latencies[i];
        }
        avg_latency /= packets_received;
    }

    double bandwidth = (packets_sent - NUM_PACKETS - packets_received) * PACKET_SIZE * 8 / 1024.0; // in Kbps

    print_statistics(loss_rate, avg_latency, bandwidth);

    close(sockfd);
    return 0;
}