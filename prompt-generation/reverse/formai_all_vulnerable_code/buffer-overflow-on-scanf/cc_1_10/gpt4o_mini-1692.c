//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void send_email(int sockfd);
void read_email(int sockfd);
void clear_buffer(char *buffer, size_t size);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char choice;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Setting server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Welcome to Simple Email Client!\n");
    while (1) {
        printf("\nOptions:\n");
        printf("1. Send Email\n");
        printf("2. Read Email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                send_email(sockfd);
                break;
            case '2':
                read_email(sockfd);
                break;
            case '3':
                close(sockfd);
                printf("Exiting Email Client\n");
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    // Close the socket
    close(sockfd);
    return 0;
}

void send_email(int sockfd) {
    char email[BUFFER_SIZE];
    
    // Clear the buffer
    clear_buffer(email, BUFFER_SIZE);
    
    printf("Enter email content: ");
    getchar(); // to consume newline left by previous scanf
    fgets(email, BUFFER_SIZE, stdin);
    
    // Send email content to server
    send(sockfd, email, strlen(email), 0);
    printf("Email sent!\n");
}

void read_email(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Request to read emails
    send(sockfd, "READ", strlen("READ"), 0);
    
    // Receive emails from server
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0'; // Null terminate the buffer
        printf("Received Emails:\n%s\n", buffer);
    } else {
        printf("No new emails or failed to retrieve emails.\n");
    }
}

void clear_buffer(char *buffer, size_t size) {
    memset(buffer, 0, size);
}