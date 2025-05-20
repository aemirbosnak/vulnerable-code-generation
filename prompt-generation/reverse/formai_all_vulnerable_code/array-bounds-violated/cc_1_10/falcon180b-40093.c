//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, error;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    char *host;
    char *serv;
    int i;

    // Set up server address
    bzero(&serv_addr, sizeof(serv_addr));
    portno = 8080;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d...\n", portno);

    // Accept incoming connections
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        // Send welcome message
        send(newsockfd, "Welcome to the server!\n", strlen("Welcome to the server!\n"), 0);

        // Receive data from client
        bzero(buffer, 1024);
        while (1) {
            i = recv(newsockfd, buffer, 1024, 0);
            if (i <= 0) {
                printf("Client disconnected\n");
                break;
            }
            buffer[i] = '\0';
            printf("Received message: %s\n", buffer);
        }

        // Close connection
        close(newsockfd);
    }

    return 0;
}