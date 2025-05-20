//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void send_email(int sockfd) {
    char buffer[BUFFER_SIZE];
    char recipient[50], subject[100], message[500];
    
    printf("Enter recipient email: ");
    fgets(recipient, sizeof(recipient), stdin);
    recipient[strcspn(recipient, "\n")] = 0;  // Remove newline

    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0;  // Remove newline
    
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;  // Remove newline

    snprintf(buffer, sizeof(buffer), "To: %s\nSubject: %s\n\n%s", recipient, subject, message);
    send(sockfd, buffer, strlen(buffer), 0);
    
    printf("Email sent to %s!\n", recipient);
}

void receive_email(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Receive failed");
        return;
    }
    buffer[bytes_received] = '\0';  // Null-terminate the received string

    printf("\nReceived Email:\n%s\n", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    int choice;
    while (1) {
        printf("\n1. Send Email\n2. Receive Email\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the input buffer
        
        switch (choice) {
            case 1:
                send_email(sockfd);
                break;
            case 2:
                receive_email(sockfd);
                break;
            case 3:
                printf("Exiting...\n");
                close(sockfd);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    close(sockfd);
    return 0;
}