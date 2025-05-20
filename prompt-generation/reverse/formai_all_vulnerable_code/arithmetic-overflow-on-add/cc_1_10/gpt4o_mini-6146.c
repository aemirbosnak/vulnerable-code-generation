//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PACKET_COUNT 100
#define BUFFER_SIZE 1024
#define DEST_IP "8.8.8.8" // Google Public DNS
#define DEST_PORT 53 // DNS port

// Function prototypes
void measure_quality();
void simulate_packet_loss(int *packet_loss_count);
double calculate_latency(struct timespec start, struct timespec end);
void display_results(int total_packets, int lost_packets, double avg_latency);

int main() {
    printf("~~~~~~~~~~~ Welcome to the Luminous QoS Monitor! ~~~~~~~~~~~\n");
    printf("Preparing to cast a glance into the realm of your network...\n");
    sleep(2);
    measure_quality();
    return 0;
}

void measure_quality() {
    int sockfd;
    struct sockaddr_in dest_addr;
    char buffer[BUFFER_SIZE];
    struct timespec start, end;
    int packet_loss_count = 0;
    double latencies[PACKET_COUNT] = {0};
    int sent_packets = 0;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Oh dear! Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(DEST_PORT);
    inet_pton(AF_INET, DEST_IP, &dest_addr.sin_addr);

    printf("Sending %d packets to %s:%d...\n", PACKET_COUNT, DEST_IP, DEST_PORT);
    sleep(1);

    for (int i = 0; i < PACKET_COUNT; i++) {
        // Establish the starting moment
        clock_gettime(CLOCK_MONOTONIC, &start);
        int send_status = sendto(sockfd, buffer, BUFFER_SIZE, 0, (const struct sockaddr *)&dest_addr, sizeof(dest_addr));
        
        if (send_status < 0) {
            perror("An unfortunate mishap occurred while sending...");
            continue;
        }

        // Setting a timeout for receiving
        fd_set read_fds;
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);
        
        int select_status = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);
        clock_gettime(CLOCK_MONOTONIC, &end);

        if (select_status > 0) {
            // Packet received
            latencies[sent_packets] = calculate_latency(start, end);
            sent_packets++;
        } else {
            // Packet lost
            printf("Packet %d lost in the ether...\n", i + 1);
            packet_loss_count++;
        }
        
        usleep(100000); // Wait for a moment
    }

    close(sockfd);

    double avg_latency = 0;
    for (int i = 0; i < sent_packets; i++) {
        avg_latency += latencies[i];
    }
    
    if (sent_packets > 0) {
        avg_latency /= sent_packets;
    } else {
        avg_latency = 0; // Avoid division by zero
    }

    display_results(PACKET_COUNT, packet_loss_count, avg_latency);
}

double calculate_latency(struct timespec start, struct timespec end) {
    double start_sec = start.tv_sec + (start.tv_nsec / 1e9);
    double end_sec = end.tv_sec + (end.tv_nsec / 1e9);
    return (end_sec - start_sec) * 1000; // Return latency in milliseconds
}

void display_results(int total_packets, int lost_packets, double avg_latency) {
    int received_packets = total_packets - lost_packets;
    printf("\n~~~ Quality of Service Report ~~~\n");
    printf("Total Packets Sent: %d\n", total_packets);
    printf("Packets Received: %d\n", received_packets);
    printf("Packets Lost: %d\n", lost_packets);
    printf("Average Latency: %.2f ms\n", avg_latency);
    printf("~~~~~~~~~~~~~ End of Report ~~~~~~~~~~~~~\n");
}