//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main() {
    int sockfd, portno, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    char *hostname = "localhost";
    int n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        exit(1);
    }

    // Resolve hostname
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1234);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        printf("ERROR resolving hostname\n");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR connecting\n");
        exit(1);
    }

    // Receive data
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE - 1, 0);
    if (n < 0) {
        printf("ERROR receiving data\n");
        exit(1);
    }
    buffer[n] = '\0';

    // Print received data
    printf("Received data: %s\n", buffer);

    // Send data
    char message[BUF_SIZE] = "Hello, World!";
    bzero(buffer, BUF_SIZE);
    n = send(sockfd, buffer, BUF_SIZE - 1, 0);
    if (n < 0) {
        printf("ERROR sending data\n");
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}