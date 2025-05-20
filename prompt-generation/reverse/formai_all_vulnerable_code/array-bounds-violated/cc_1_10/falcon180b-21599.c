//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int n;
    int portno = 8080;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    puts("Socket created");

    // Set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind to port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    puts("Bound to port");

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    puts("Listening for connections");

    // Accept incoming connection
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
    if (newsockfd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    puts("Connection accepted");

    // Send welcome message to client
    send(newsockfd, "Welcome to the server\n", 21, 0);

    // Receive message from client
    bzero(buffer, 1024);
    n = recv(newsockfd, buffer, 1024, 0);

    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    buffer[n] = '\0';
    printf("Received message: %s\n", buffer);

    // Close socket
    close(newsockfd);
    close(sockfd);

    return 0;
}