//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    int addrlen;
    int n;

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("socket failed\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Bind failed\n");
        exit(0);
    }

    // Listen
    if (listen(sockfd, 5) < 0) {
        printf("Listen failed\n");
        exit(0);
    }

    while (1) {
        // Accept a connection
        addrlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
        if (newsockfd < 0) {
            printf("Accept failed\n");
            exit(0);
        }

        printf("New connection\n");

        // Send welcome message to client
        send(newsockfd, "Welcome to the server\n", strlen("Welcome to the server\n"), 0);

        // Receive data from client
        bzero(buffer, BUF_SIZE);
        n = recv(newsockfd, buffer, BUF_SIZE, 0);
        if (n < 0) {
            printf("Receive failed\n");
            exit(0);
        }

        printf("Received data: %s\n", buffer);

        // Send data back to client
        send(newsockfd, buffer, strlen(buffer), 0);

        // Close connection
        close(newsockfd);
    }

    return 0;
}