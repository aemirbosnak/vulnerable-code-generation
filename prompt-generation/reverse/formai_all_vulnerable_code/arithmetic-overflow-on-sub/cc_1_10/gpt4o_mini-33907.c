//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define NUM_SAMPLES 100

typedef struct {
    double latency;
    double jitter;
    double packet_loss;
} QoSMetrics;

void compute_metrics(QoSMetrics *metrics, double *latency_samples, int count) {
    double total_latency = 0.0;
    double max_latency = latency_samples[0];
    double min_latency = latency_samples[0];

    for (int i = 0; i < count; i++) {
        total_latency += latency_samples[i];
        if (latency_samples[i] > max_latency) {
            max_latency = latency_samples[i];
        }
        if (latency_samples[i] < min_latency) {
            min_latency = latency_samples[i];
        }
    }

    metrics->latency = total_latency / count;
    metrics->jitter = max_latency - min_latency; // Very simplistic jitter calculation
    metrics->packet_loss = (double)(count - NUM_SAMPLES) / NUM_SAMPLES * 100.0;  // Let's assume all should have been received
}

void ping(const char *hostname, QoSMetrics *metrics) {
    struct sockaddr_in server_addr;
    struct hostent *hostinfo;
    char buffer[BUFFER_SIZE];
    struct timeval start, end;
    double latency_samples[NUM_SAMPLES];
    int success_count = 0;

    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        perror("gethostbyname failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, hostinfo->h_addr, hostinfo->h_length);
    server_addr.sin_port = htons(PORT);

    for (int i = 0; i < NUM_SAMPLES; i++) {
        int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        gettimeofday(&start, NULL);
        int sent = sendto(sockfd, "ping", 4, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (sent < 0) {
            perror("Send failed");
            close(sockfd);
            continue; // Skip this iteration on failure
        }

        socklen_t addr_len = sizeof(server_addr);
        int recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &addr_len);
        gettimeofday(&end, NULL);
        close(sockfd);

        if (recv_len >= 0) {
            success_count++;
            latency_samples[i] = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0; // latency in ms
        } else {
            latency_samples[i] = -1; // Indicate failure
        }

        usleep(100000); // Sleep 100 ms before next ping
    }

    compute_metrics(metrics, latency_samples, NUM_SAMPLES);
}

void print_metrics(QoSMetrics metrics) {
    printf("Latency (ms): %.2f\n", metrics.latency);
    printf("Jitter (ms): %.2f\n", metrics.jitter);
    printf("Packet Loss (%%): %.2f\n", metrics.packet_loss);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    QoSMetrics metrics = {0};  // Initialize QoS metrics
    ping(argv[1], &metrics);
    print_metrics(metrics);

    return 0;
}