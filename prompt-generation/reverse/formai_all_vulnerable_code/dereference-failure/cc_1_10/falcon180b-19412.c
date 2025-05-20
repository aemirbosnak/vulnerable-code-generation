//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define MAX_LINE 80
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_LINE];
    int n;
    int opt = TRUE;
    int addrlen = sizeof(cli_addr);
    char hostname[20];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket");
        exit(0);
    }

    // Set socket options
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    // Set up server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket");
        exit(0);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        printf("Error listening on socket");
        exit(0);
    }

    while (TRUE) {
        // Accept incoming connection
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen);
        if (newsockfd < 0) {
            printf("Error accepting connection");
            exit(0);
        }

        // Get hostname of client
        getnameinfo((struct sockaddr *)&cli_addr, sizeof(cli_addr), hostname, sizeof(hostname), NULL, 0, 0);

        // Send welcome message to client
        send(newsockfd, "Welcome to the server, ", strlen("Welcome to the server, "), 0);
        send(newsockfd, hostname, strlen(hostname), 0);

        // Receive message from client
        n = recv(newsockfd, buffer, MAX_LINE, 0);
        if (n <= 0) {
            printf("Client disconnected");
            close(newsockfd);
            continue;
        }

        // Echo message back to client
        send(newsockfd, buffer, strlen(buffer), 0);

        // Close connection
        close(newsockfd);
    }

    return 0;
}