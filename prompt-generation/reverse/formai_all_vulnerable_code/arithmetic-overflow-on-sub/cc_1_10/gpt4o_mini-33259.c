//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdbool.h>

#define BUFFER_SIZE 256
#define MAX_IP_ADDRESSES 10
#define MONITOR_DURATION 60

typedef struct {
    char ip_address[INET_ADDRSTRLEN];
    double latency; // in milliseconds
    double packet_loss; // percentage
} QoS_Status;

void print_usage() {
    printf("Usage: qos_monitor <host> <port>\n");
    printf("Example: qos_monitor google.com 80\n");
}

double calculate_latency(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1e6;
}

void monitor_qos(const char *host, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    QoS_Status qos_status;
    struct timespec start, end;
    int sent_packets = 0, lost_packets = 0;

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    strcpy(qos_status.ip_address, inet_ntoa(server_addr.sin_addr));

    printf("Monitoring QoS for host: %s (%s) on port: %d\n", host, qos_status.ip_address, port);
    
    time_t start_time = time(NULL);
    
    while (time(NULL) - start_time < MONITOR_DURATION) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            perror("ERROR creating socket");
            return;
        }

        // Send a message to the server
        snprintf(buffer, BUFFER_SIZE, "PING");
        if (sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("ERROR sending to socket");
            lost_packets++;
        } else {
            sent_packets++;
            socklen_t addr_len = sizeof(server_addr);
            if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&server_addr, &addr_len) < 0) {
                perror("ERROR receiving from socket");
                lost_packets++;
            }
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        close(sockfd);

        // Calculate and print the latency
        double latency = calculate_latency(start, end);
        qos_status.latency = latency;
        printf("Ping to %s - Latency: %.2f ms, Sent: %d, Lost: %d\n", qos_status.ip_address, qos_status.latency, sent_packets, lost_packets);
        
        sleep(1);
    }

    qos_status.packet_loss = ((double)lost_packets / (double)sent_packets) * 100.0;
    printf("\nSummary for IP: %s\n", qos_status.ip_address);
    printf("Total Sent: %d, Total Lost: %d, Packet Loss: %.2f%%\n", sent_packets, lost_packets, qos_status.packet_loss);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    const char *host = argv[1];
    int port = atoi(argv[2]);

    monitor_qos(host, port);

    return 0;
}