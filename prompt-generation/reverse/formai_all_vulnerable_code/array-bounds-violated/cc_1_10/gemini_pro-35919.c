//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Specify the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send a message to the server
    char *msg = "Hello, server!";
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive a message from the server
    char buffer[1024];
    int n;
    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    buffer[n] = '\0';
    printf("Received from server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}