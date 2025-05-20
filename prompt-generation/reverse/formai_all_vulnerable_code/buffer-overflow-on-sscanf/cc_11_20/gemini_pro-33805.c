//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main() {
    // Declare the socket file descriptor.
    int sockfd;

    // Create a socket.
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address.
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110);  // POP3 port
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Receive the initial greeting from the server.
    char buffer[MAXLINE];
    if (recv(sockfd, buffer, MAXLINE, 0) <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Send the USER command.
    sprintf(buffer, "USER username\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) <= 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server.
    if (recv(sockfd, buffer, MAXLINE, 0) <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Send the PASS command.
    sprintf(buffer, "PASS password\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) <= 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server.
    if (recv(sockfd, buffer, MAXLINE, 0) <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Send the LIST command.
    sprintf(buffer, "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) <= 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server.
    int num_messages;
    if (recv(sockfd, buffer, MAXLINE, 0) <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Parse the response to get the number of messages.
    sscanf(buffer, "+OK %d messages\r\n", &num_messages);

    // Send the QUIT command.
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) <= 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Close the socket.
    close(sockfd);

    return 0;
}