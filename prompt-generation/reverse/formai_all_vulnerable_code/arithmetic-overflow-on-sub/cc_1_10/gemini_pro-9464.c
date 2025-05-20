//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

// Colors for cheerful output
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define MAGENTA "\e[35m"
#define CYAN "\e[36m"
#define RESET "\e[0m"

// QoS monitoring parameters
#define SAMPLE_RATE 1000 // milliseconds
#define SAMPLE_COUNT 10

// QoS metrics
typedef struct QoS_Metrics {
    double jitter;
    double latency;
    double packet_loss;
} QoS_Metrics;

// Thread function for QoS monitoring
void* monitor_qos(void* arg) {
    int sockfd = *(int*)arg;
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);
    char buf[1024];
    struct timeval start_time, end_time;
    double latencies[SAMPLE_COUNT];
    int lost_packets = 0;
    int i, j;

    // Connect to the QoS monitoring server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    if (connect(sockfd, (struct sockaddr*)&server_addr, addr_len) < 0) {
        perror("connect() failed");
        exit(1);
    }

    // Start QoS monitoring loop
    while (1) {
        // Send a QoS monitoring request
        if (send(sockfd, "ping", 4, 0) < 0) {
            perror("send() failed");
            exit(1);
        }

        // Measure the latency
        gettimeofday(&start_time, NULL);
        if (recv(sockfd, buf, 1024, 0) < 0) {
            perror("recv() failed");
            lost_packets++;
            continue;
        }
        gettimeofday(&end_time, NULL);
        latencies[i++] = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);

        // Sample rate control
        if (i >= SAMPLE_COUNT) {
            i = 0;
        }

        // Calculate jitter and latency
        double jitter = 0, latency = 0;
        for (j = 0; j < SAMPLE_COUNT; j++) {
            jitter += abs(latencies[j] - latency);
            latency += latencies[j];
        }
        jitter /= SAMPLE_COUNT;
        latency /= SAMPLE_COUNT;

        // Calculate packet loss
        double packet_loss = (double)lost_packets / (SAMPLE_COUNT + lost_packets) * 100;

        // Print QoS metrics
        printf(YELLOW "\nQoS Metrics:\n" RESET);
        printf("  Jitter: %.2f ms\n", jitter);
        printf("  Latency: %.2f ms\n", latency);
        printf("  Packet loss: %.2f%%\n\n", packet_loss);

        // Sleep for the sample rate
        usleep(SAMPLE_RATE * 1000);
    }

    close(sockfd);
    pthread_exit(NULL);
}

int main() {
    int sockfd;
    pthread_t thread;

    // Create a socket for QoS monitoring
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(1);
    }

    // Create a thread for QoS monitoring
    if (pthread_create(&thread, NULL, monitor_qos, &sockfd) != 0) {
        perror("pthread_create() failed");
        exit(1);
    }

    // Join the QoS monitoring thread
    if (pthread_join(thread, NULL) != 0) {
        perror("pthread_join() failed");
        exit(1);
    }

    return 0;
}