//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_ATTEMPTS 4
#define TIMEOUT 1 // 1 second timeout for each ping
#define BUFFER_SIZE 1024

// Function prototype
void ping(const char *address, int attempts, int current_attempt);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip-address-or-hostname>\n", argv[0]);
        return 1;
    }

    ping(argv[1], MAX_ATTEMPTS, 0);
    return 0;
}

// Recursive ping function
void ping(const char *address, int attempts, int current_attempt) {
    if (current_attempt >= attempts) {
        printf("All ping attempts completed.\n");
        return;
    }

    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct timeval timeout;

    // Create a socket for ping
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set timeout for the socket
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    // Prepare the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, address, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address/hostname: %s\n", address);
        close(sockfd);
        return;
    }

    // Send ICMP Echo Request
    sprintf(buffer, "PING %s: Attempt %d", address, current_attempt + 1);
    if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) <= 0) {
        perror("Error sending ping");
    } else {
        printf("Ping attempt %d sent to %s\n", current_attempt + 1, address);
    }

    // Prepare to receive the response
    socklen_t len = sizeof(server_addr);
    int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &len);
    
    if (n < 0) {
        printf("Ping attempt %d to %s timed out.\n", current_attempt + 1, address);
    } else {
        buffer[n] = '\0'; // Null terminate the received data
        printf("Ping attempt %d successful: Received response: %s\n", current_attempt + 1, buffer);
    }

    close(sockfd);

    // Recursive call to continue pinging
    ping(address, attempts, current_attempt + 1);
}