//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_EMAIL_LENGTH 1024
#define MAX_MESSAGE_LENGTH 2048
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 2048

// Function to display the menu
void display_menu() {
    printf("\n=== Email Client ===\n");
    printf("1. Send an Email\n");
    printf("2. Receive Email\n");
    printf("3. Exit\n");
    printf("====================\n");
    printf("Choose an option: ");
}

// Function to send email
void send_email(int sockfd) {
    char recipient[MAX_EMAIL_LENGTH], subject[MAX_EMAIL_LENGTH], body[MAX_MESSAGE_LENGTH];
    printf("\nEnter recipient email: ");
    getchar(); // Clear newline left by previous input
    fgets(recipient, MAX_EMAIL_LENGTH, stdin);
    recipient[strcspn(recipient, "\n")] = 0; // Remove newline character

    printf("Enter subject: ");
    fgets(subject, MAX_EMAIL_LENGTH, stdin);
    subject[strcspn(subject, "\n")] = 0;

    printf("Enter message body: ");
    fgets(body, MAX_MESSAGE_LENGTH, stdin);
    body[strcspn(body, "\n")] = 0;

    // Create email format
    char email[MAX_EMAIL_LENGTH + MAX_MESSAGE_LENGTH + 100];
    snprintf(email, sizeof(email), "TO: %s\nSUBJECT: %s\n\n%s", recipient, subject, body);

    // Send email
    send(sockfd, email, strlen(email), 0);
    printf("Email sent to %s!\n", recipient);
}

// Function to receive email
void receive_email(int sockfd) {
    char buffer[BUFFER_SIZE];
    printf("\nFetching emails...\n");
    
    // Attempt to receive email
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received <= 0) {
        printf("No new emails.\n");
        return;
    }
    
    buffer[bytes_received] = '\0'; // Null terminate
    printf("Received Email:\n%s\n", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    // Convert IPv4 address from text to binary
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                send_email(sockfd);
                break;
            case 2:
                receive_email(sockfd);
                break;
            case 3:
                close(sockfd);
                printf("Exiting Email Client. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}