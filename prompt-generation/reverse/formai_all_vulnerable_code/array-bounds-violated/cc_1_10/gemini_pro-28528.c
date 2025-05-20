//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main() {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char recvline[MAXLINE + 1];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    // Set up the server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9999);  // Set the port number
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    // Send a message to the server
    char *message = "Hello server!";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Receive a response from the server
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        perror("recv error");
        exit(1);
    }
    recvline[n] = '\0';  // Null-terminate the received string

    // Print the server's response
    printf("Received: %s\n", recvline);

    // Close the socket
    close(sockfd);

    return 0;
}