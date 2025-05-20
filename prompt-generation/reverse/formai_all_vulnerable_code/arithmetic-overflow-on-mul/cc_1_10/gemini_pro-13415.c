//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define SERVER_PORT 5000
#define CLIENT_PORT 6000
#define BUFFER_SIZE 1024
#define NUM_THREADS 4

// QoS parameters
#define MIN_BANDWIDTH 1000000  // 1 Mbps
#define MAX_BANDWIDTH 10000000 // 10 Mbps
#define MIN_LATENCY 50         // 50 milliseconds
#define MAX_LATENCY 100        // 100 milliseconds
#define MIN_PACKET_LOSS 0.05   // 5%
#define MAX_PACKET_LOSS 0.1    // 10%

// Data structure to store QoS metrics
typedef struct {
    int bandwidth;
    int latency;
    float packet_loss;
} QoS;

// Initialize QoS parameters
QoS qos = {
    .bandwidth = 0,
    .latency = 0,
    .packet_loss = 0.0
};

// Thread function to measure bandwidth
void *bandwidth_thread(void *arg) {
    int sockfd = (int)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    // Send data to the server
    for (int i = 0; i < 1000; i++) {
        send(sockfd, buffer, BUFFER_SIZE, 0);
        bytes_received += BUFFER_SIZE;
    }

    // Calculate bandwidth
    qos.bandwidth = bytes_received * 8 / 1000000;

    return NULL;
}

// Thread function to measure latency
void *latency_thread(void *arg) {
    int sockfd = (int)arg;
    char buffer[BUFFER_SIZE];
    struct timeval start, end;

    // Send data to the server
    send(sockfd, buffer, BUFFER_SIZE, 0);

    // Measure latency
    gettimeofday(&start, NULL);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    gettimeofday(&end, NULL);

    qos.latency = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;

    return NULL;
}

// Thread function to measure packet loss
void *packet_loss_thread(void *arg) {
    int sockfd = (int)arg;
    char buffer[BUFFER_SIZE];
    int packets_sent = 0;
    int packets_received = 0;

    // Send data to the server
    for (int i = 0; i < 1000; i++) {
        send(sockfd, buffer, BUFFER_SIZE, 0);
        packets_sent++;
    }

    // Measure packet loss
    for (int i = 0; i < 1000; i++) {
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
            packets_received++;
        }
    }

    qos.packet_loss = (float)(packets_sent - packets_received) / packets_sent;

    return NULL;
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the socket to the client port
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(CLIENT_PORT),
        .sin_addr = { .s_addr = INADDR_ANY }
    };

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(SERVER_PORT),
        .sin_addr = { .s_addr = inet_addr("127.0.0.1") }
    };

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Create threads to measure QoS parameters
    pthread_t threads[NUM_THREADS];
    pthread_create(&threads[0], NULL, bandwidth_thread, (void *)sockfd);
    pthread_create(&threads[1], NULL, latency_thread, (void *)sockfd);
    pthread_create(&threads[2], NULL, packet_loss_thread, (void *)sockfd);

    // Wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print QoS metrics
    printf("Bandwidth: %d Mbps\n", qos.bandwidth);
    printf("Latency: %d milliseconds\n", qos.latency);
    printf("Packet loss: %.2f%%\n", qos.packet_loss * 100);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}