//Gemma-7B DATASET v1.0 Category: Socket programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>

int main() {

    int sockfd, newsockfd, portno = 8080, yes = 1;
    char buffer[1024];

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(portno));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Listen for connections
    listen(sockfd, 5);

    // Accept connection
    newsockfd = accept(sockfd, NULL, NULL);
    if (newsockfd < 0) {
        perror("Error accepting connection");
        exit(1);
    }

    // Send and receive messages
    while (yes) {
        // Receive message
        memset(buffer, 0, 1024);
        int recv_len = recv(newsockfd, buffer, 1024, 0);
        if (recv_len < 0) {
            perror("Error receiving message");
            exit(1);
        }

        // Print message
        printf("Received: %s\n", buffer);

        // Send message
        printf("Enter your message: ");
        scanf("%s", buffer);
        send(newsockfd, buffer, strlen(buffer) + 1, 0);

        // Check if the client wants to quit
        if (strcmp(buffer, "quit") == 0) {
            yes = 0;
        }
    }

    // Close connections
    close(newsockfd);
    close(sockfd);

    return 0;
}