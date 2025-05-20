//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 64
#define MAX_TRIES 5
#define TIMEOUT_SEC 2

// Function to calculate the time difference between two timeval structures
long calculate_time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
}

// Function to ping a host
int ping_host(const char *host) {
    struct sockaddr_in server_addr;
    struct timeval start, end;
    char buffer[BUFFER_SIZE];
    int sockfd;
    socklen_t addr_len = sizeof(server_addr);

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Get server address
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Could not resolve host: %s\n", host);
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Prepare server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(8080); // Using arbitrary port

    // Attempt to send a ping message and receive a reply
    gettimeofday(&start, NULL);
    if (sendto(sockfd, buffer, BUFFER_SIZE, 0, 
               (struct sockaddr *) &server_addr, addr_len) < 0) {
        perror("Send failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, 
                 (struct sockaddr *) &server_addr, &addr_len) < 0) {
        perror("Receive failed or timeout");
        close(sockfd);
        return -1;
    }
    
    gettimeofday(&end, NULL);
    close(sockfd);
    return calculate_time_diff(start, end);
}

int main() {
    char host[100];
    int tries, latency;

    printf("Enter host to ping (e.g., google.com): ");
    scanf("%s", host);
    
    printf("Pinging %s...\n", host);

    for (tries = 1; tries <= MAX_TRIES; tries++) {
        latency = ping_host(host);
        
        if (latency < 0) {
            printf("Request timed out or failed.\n");
        } else {
            printf("Ping %d: Time = %d ms\n", tries, latency);
        }

        sleep(1); // Wait for 1 second before the next ping
    }

    printf("Finished pinging %s after %d tries.\n", host, MAX_TRIES);
    return 0;
}