//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10
#define PORT 8080

volatile sig_atomic_t running = 1;

void handle_sigint(int sig) {
    running = 0;
}

void display_quality(float jitter, float packet_loss, float latency) {
    printf("\n-----------------------------------\n");
    printf("           Network QoS Monitor      \n");
    printf("-----------------------------------\n");
    printf("Jitter: %.2f ms\n", jitter);
    printf("Packet Loss: %.2f %%\n", packet_loss);
    printf("Latency: %.2f ms\n", latency);
    printf("-----------------------------------\n");
}

float calculate_jitter(float prev_time, float current_time) {
    return (current_time - prev_time) * 1000; // Convert to milliseconds
}

float calculate_packet_loss(int sent, int received) {
    return ((float)(sent - received) / sent) * 100; // Packet Loss Percentage
}

float calculate_latency(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000.0; // ms
}

int main() {
    signal(SIGINT, handle_sigint);
    
    int sockfd, newsockfd, portno;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    // Creating socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    portno = PORT;
    serv_addr.sin_family = AF_INET; // IPv4
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Any IP
    serv_addr.sin_port = htons(portno); // Port

    // Binding socket
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    int sent_packets = 0;
    int received_packets = 0;
    float jitter = 0.0, packet_loss, latency;

    struct timespec start_time, end_time, prev_time;
    clock_gettime(CLOCK_MONOTONIC, &prev_time);

    printf("Network QoS Monitor running on port %d...\n", PORT);
    while (running) {
        clilen = sizeof(cli_addr);
        memset(buffer, 0, BUFFER_SIZE);
        
        // Simulating packet sending
        sprintf(buffer, "Ping!");
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *) &cli_addr, clilen);
        sent_packets++;
        
        // Waiting for response
        if (recvfrom(sockfd, buffer, BUFFER_SIZE - 1, MSG_DONTWAIT, (struct sockaddr *) &cli_addr, &clilen) > 0) {
            received_packets++;
            clock_gettime(CLOCK_MONOTONIC, &end_time);
            latency = calculate_latency(prev_time, end_time);
            jitter += calculate_jitter(prev_time.tv_sec + prev_time.tv_nsec / 1000000000.0, end_time.tv_sec + end_time.tv_nsec / 1000000000.0);
            prev_time = end_time;

            // Display quality every 5 seconds
            if (sent_packets % 5 == 0) {
                packet_loss = calculate_packet_loss(sent_packets, received_packets);
                display_quality(jitter / 5, packet_loss, latency);
                jitter = 0.0; // Reset jitter
            }
        }

        usleep(100000); // Sleep for 100 ms
    }

    close(sockfd);
    printf("\nNetwork QoS Monitor stopped.\n");
    return 0;
}