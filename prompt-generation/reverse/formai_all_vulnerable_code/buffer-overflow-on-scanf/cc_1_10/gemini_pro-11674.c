//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, n, recvdBytes;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    int tries = 0, timeout = 500000;  // 500ms timeout

    printf("Enter the IP address of the target host: ");
    scanf("%s", buffer);

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set the server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(buffer);
    serverAddr.sin_port = htons(80);

    // Set the socket timeout
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    while (tries < 3) {
        // Send a ping request
        n = sendto(sockfd, "ping", 4, 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
        if (n < 0) {
            perror("Error sending ping request");
            exit(1);
        }

        // Receive the ping response
        recvdBytes = recvfrom(sockfd, buffer, 1024, 0, NULL, NULL);
        if (recvdBytes < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                printf("Timeout! No response received.\n");
            } else {
                perror("Error receiving ping response");
                exit(1);
            }
        } else {
            printf("Received ping response from: %s\n", buffer);
            break;
        }

        tries++;
    }

    // Close the socket
    close(sockfd);

    return 0;
}