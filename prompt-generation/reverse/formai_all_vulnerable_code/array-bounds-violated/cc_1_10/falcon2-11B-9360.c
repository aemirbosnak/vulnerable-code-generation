//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to an address and port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listening");
        exit(EXIT_FAILURE);
    }

    // Accept a connection, blocking if one is not already there
    portno = 0;
    bzero(&serv_addr, sizeof(serv_addr));
    if ((n = accept(sockfd, (struct sockaddr *) &serv_addr, (socklen_t *) &portno)) < 0) {
        perror("ERROR on accepting");
        exit(EXIT_FAILURE);
    }

    // Receive the message from the server
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE - 1, 0);
    if (n < 0) {
        perror("ERROR receiving data");
        exit(EXIT_FAILURE);
    }
    buffer[n] = '\0';

    // Print the received message
    printf("Received message: %s\n", buffer);

    // Clean up
    close(sockfd);
    return 0;
}