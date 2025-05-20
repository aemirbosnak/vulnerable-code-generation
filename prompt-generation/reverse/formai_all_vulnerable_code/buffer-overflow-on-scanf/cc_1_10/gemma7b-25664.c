//Gemma-7B DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

int main() {
    int sockfd, newsockfd, portno = 8080;
    struct sockaddr_in serv_addr, client_addr;
    char buffer[1024];

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(portno));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    listen(sockfd, 5);

    // Accept a client connection
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (newsockfd < 0) {
        perror("Error accepting client connection");
        exit(1);
    }

    // Send and receive messages
    while (1) {
        // Receive message from client
        int recv_len = recv(newsockfd, buffer, 1024, 0);
        if (recv_len > 0) {
            // Print message from client
            printf("Client: %s\n", buffer);
        } else if (recv_len == 0) {
            // Client disconnected
            printf("Client disconnected\n");
            break;
        } else {
            // Error receiving message
            perror("Error receiving message");
            break;
        }

        // Send message to client
        printf("Server: ");
        scanf("%s", buffer);
        send(newsockfd, buffer, strlen(buffer) + 1, 0);
    }

    // Close the socket
    close(sockfd);
    close(newsockfd);

    return 0;
}