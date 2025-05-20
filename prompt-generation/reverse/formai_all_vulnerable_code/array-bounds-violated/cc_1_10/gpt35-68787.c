//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>

#define BUFFER_SIZE 1024

volatile int running = 1;

void handle_sigint(int sig) {
    running = 0;
}

int main() {

    // Create socket file descriptor
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8888);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket with server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Handle SIGINT signal
    signal(SIGINT, handle_sigint);

    // Start listening for incoming datagrams
    char buffer[BUFFER_SIZE];
    struct sockaddr_in clientaddr;
    int len, n;
    while (running) {
        len = sizeof(clientaddr);
        n = recvfrom(sockfd, (char *)buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&clientaddr, &len);
        buffer[n] = '\0';

        // Convert received signal strength to dBm
        int rssi = (int)buffer[1];
        int dbm = -((rssi / 2) - 127);

        // Print client IP address and signal strength
        printf("Client %s:%d - Signal strength: %d dBm\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port), dbm);
    }

    // Close socket
    close(sockfd);

    return 0;
}