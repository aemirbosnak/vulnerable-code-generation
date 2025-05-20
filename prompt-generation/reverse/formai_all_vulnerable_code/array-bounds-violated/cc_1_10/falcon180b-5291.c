//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 100

int main() {
    int sockfd, newsockfd, clilen, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind to port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    puts("Server is listening on port 8080");

    // Accept a connection
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    puts("Connection accepted");

    // Receive data from client
    sd = read(newsockfd, buffer, MAX);
    if (sd < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buffer[sd] = '\0';
    puts("Received data: ");
    puts(buffer);

    // Send data to client
    send(newsockfd, "Data received", strlen("Data received"), 0);

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}