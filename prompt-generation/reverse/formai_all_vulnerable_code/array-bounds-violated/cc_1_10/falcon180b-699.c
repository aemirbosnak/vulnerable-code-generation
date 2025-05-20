//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX 100

int main() {
    int sockfd, newsockfd, len, n;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error in creating socket\n");
        exit(0);
    }

    // Set options on the socket
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Initialize server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket to an address and port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error in binding\n");
        exit(0);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        printf("Error in listening\n");
        exit(0);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept a new connection
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
        if (newsockfd < 0) {
            printf("Error in accepting\n");
            exit(0);
        }

        printf("New connection accepted\n");

        // Send welcome message to client
        send(newsockfd, "Welcome to the server!", strlen("Welcome to the server!"), 0);

        // Receive message from client
        n = recv(newsockfd, buffer, MAX, 0);
        if (n < 0) {
            printf("Error in receiving\n");
            exit(0);
        }

        buffer[n] = '\0';
        printf("Received message: %s\n", buffer);

        // Send response back to client
        sprintf(buffer, "You sent the message: %s", buffer);
        send(newsockfd, buffer, strlen(buffer), 0);

        // Close the connection
        close(newsockfd);
    }

    return 0;
}