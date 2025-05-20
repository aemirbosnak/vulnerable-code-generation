//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Data structure to store QoS metrics
typedef struct qos_metrics {
    double jitter;
    double latency;
    double packet_loss;
    double bandwidth;
} qos_metrics_t;

// Function to calculate the jitter
double calculate_jitter(struct timeval *timestamps, int num_timestamps) {
    double avg_jitter = 0.0;
    for (int i = 1; i < num_timestamps; i++) {
        avg_jitter += timestamps[i].tv_usec - timestamps[i - 1].tv_usec;
    }
    avg_jitter /= num_timestamps - 1;
    return avg_jitter;
}

// Function to calculate the latency
double calculate_latency(struct timeval *start_time, struct timeval *end_time) {
    double latency = (end_time->tv_sec - start_time->tv_sec) * 1000.0 +
                     (end_time->tv_usec - start_time->tv_usec) / 1000.0;
    return latency;
}

// Function to calculate the packet loss
double calculate_packet_loss(int num_packets_sent, int num_packets_received) {
    double packet_loss = (1.0 - (double)num_packets_received / num_packets_sent) * 100.0;
    return packet_loss;
}

// Function to calculate the bandwidth
double calculate_bandwidth(int num_bytes_sent, struct timeval *start_time, struct timeval *end_time) {
    double bandwidth = (double)num_bytes_sent / ((end_time->tv_sec - start_time->tv_sec) + (end_time->tv_usec - start_time->tv_usec) / 1000000.0);
    return bandwidth;
}

// Function to send and receive data
int send_and_receive_data(int sockfd, char *buffer, int buffer_size, struct timeval *timestamps, int num_timestamps) {
    int num_bytes_sent = send(sockfd, buffer, buffer_size, 0);
    if (num_bytes_sent < 0) {
        perror("Error sending data");
        return -1;
    }
    int num_bytes_received = recv(sockfd, buffer, buffer_size, 0);
    if (num_bytes_received < 0) {
        perror("Error receiving data");
        return -1;
    }
    timestamps[num_timestamps].tv_sec = time(NULL);
    timestamps[num_timestamps].tv_usec = gettimeofday(&timestamps[num_timestamps], NULL);
    return num_bytes_received;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error resolving hostname %s\n", hostname);
        return 1;
    }

    // Create the socket address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Send and receive data
    char buffer[1024];
    struct timeval timestamps[100];
    int num_packets_sent = 0;
    int num_packets_received = 0;
    while (1) {
        // Send data
        int num_bytes_sent = send_and_receive_data(sockfd, buffer, sizeof(buffer), timestamps, num_packets_sent);
        if (num_bytes_sent < 0) {
            break;
        }
        num_packets_sent++;

        // Receive data
        int num_bytes_received = send_and_receive_data(sockfd, buffer, sizeof(buffer), timestamps, num_packets_received);
        if (num_bytes_received < 0) {
            break;
        }
        num_packets_received++;
    }

    // Calculate the QoS metrics
    qos_metrics_t qos_metrics;
    qos_metrics.jitter = calculate_jitter(timestamps, num_packets_received);
    qos_metrics.latency = calculate_latency(&timestamps[0], &timestamps[num_packets_received - 1]);
    qos_metrics.packet_loss = calculate_packet_loss(num_packets_sent, num_packets_received);
    qos_metrics.bandwidth = calculate_bandwidth(sizeof(buffer) * num_packets_sent, &timestamps[0], &timestamps[num_packets_received - 1]);

    // Print the QoS metrics
    printf("Jitter: %.3f ms\n", qos_metrics.jitter);
    printf("Latency: %.3f ms\n", qos_metrics.latency);
    printf("Packet loss: %.3f%%\n", qos_metrics.packet_loss);
    printf("Bandwidth: %.3f Mbps\n", qos_metrics.bandwidth);

    // Close the socket
    close(sockfd);

    return 0;
}