//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    char *message = "Welcome to the server!";
    int addrlen = sizeof(cli_addr);
    int opt = 1;
    int len;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(12345);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 12345...\n");

    // Accept a connection
    addrlen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
    if (newsockfd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted...\n");

    // Send a message to the client
    send(newsockfd, message, strlen(message), 0);

    // Receive a message from the client
    len = recv(newsockfd, buffer, BUF_SIZE, 0);
    if (len < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    buffer[len] = '\0';
    printf("Received message: %s\n", buffer);

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}