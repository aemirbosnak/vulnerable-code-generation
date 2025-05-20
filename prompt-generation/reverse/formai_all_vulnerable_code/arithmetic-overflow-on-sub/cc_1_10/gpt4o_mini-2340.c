//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define NUM_PINGS 5

void print_usage() {
    printf("Usage: ./qos_monitor <hostname>\n");
}

double calculate_latency(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
}

int ping(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sockfd, numbytes;
    char send_buf[PACKET_SIZE] = "PING";
    char recv_buf[PACKET_SIZE];
    struct timespec start, end;

    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(80);  // Use HTTP as a target

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return -1;
    }

    // Set timeout for the socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

    // Send PING messages and receive responses
    for (int i = 0; i < NUM_PINGS; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &start);
        
        numbytes = sendto(sockfd, send_buf, sizeof(send_buf), 0, 
                          (struct sockaddr *)&server_addr, sizeof(server_addr));

        if (numbytes == -1) {
            fprintf(stderr, "Error sending packet: %s\n", strerror(errno));
            close(sockfd);
            return -1;
        }

        socklen_t addr_len = sizeof(server_addr);
        numbytes = recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0,
                            (struct sockaddr *)&server_addr, &addr_len);

        clock_gettime(CLOCK_MONOTONIC, &end);
        
        if (numbytes < 0) {
            fprintf(stderr, "Request timed out\n");
        } else {
            double latency = calculate_latency(start, end);
            printf("Response from %s: time=%.2f ms\n", hostname, latency);
        }
    }

    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    
    printf("Pinging %s...\n", hostname);
    int result = ping(hostname);
    
    if (result != 0) {
        fprintf(stderr, "Ping failed.\n");
    } else {
        printf("Ping complete.\n");
    }

    return EXIT_SUCCESS;
}