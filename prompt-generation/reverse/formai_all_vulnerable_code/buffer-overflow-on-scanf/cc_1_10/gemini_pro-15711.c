//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFF_SIZE 1024

// Client-side code
void client() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        perror("invalid address");
        exit(EXIT_FAILURE);
    }

    // Establish connection
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Communicate with server
    char buffer[BUFF_SIZE];
    while (1) {
        printf("Enter message: ");
        fgets(buffer, BUFF_SIZE, stdin);

        // Send message
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("message send failed");
            exit(EXIT_FAILURE);
        }

        // Receive response
        memset(buffer, 0, BUFF_SIZE);
        if (recv(sockfd, buffer, BUFF_SIZE, 0) < 0) {
            perror("message receive failed");
            exit(EXIT_FAILURE);
        }

        // Print response
        printf("Server response: %s\n", buffer);
        
        // Check for exit command
        if (strcmp(buffer, "!exit") == 0) {
            printf("Exiting...\n");
            break;
        }
    }

    // Close connection
    close(sockfd);
}

// Server-side code
void server() {
    int sockfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("socket bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    while (1) {
        clilen = sizeof(cliaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Communicate with client
        char buffer[BUFF_SIZE];
        while (1) {
            // Receive message
            memset(buffer, 0, BUFF_SIZE);
            if (recv(newsockfd, buffer, BUFF_SIZE, 0) < 0) {
                perror("message receive failed");
                exit(EXIT_FAILURE);
            }

            // Process message
            if (strcmp(buffer, "!exit") == 0) {
                printf("Client disconnected.\n");
                break;
            }

            // Send response
            memset(buffer, 0, BUFF_SIZE);
            sprintf(buffer, "Message received: %s", buffer);
            if (send(newsockfd, buffer, strlen(buffer), 0) < 0) {
                perror("message send failed");
                exit(EXIT_FAILURE);
            }
        }

        // Close client connection
        close(newsockfd);
    }

    // Close server socket
    close(sockfd);
}

int main() {
    int choice;
    printf("1. Client\n2. Server\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            client();
            break;
        case 2:
            server();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}