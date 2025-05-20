//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_LEN 1024
#define PORT 110

// Function to display the main menu
void displayMenu() {
    printf("\n\t*** Simple C Email Client ***\n");
    printf("\t1. Send Email\n");
    printf("\t2. Receive Emails\n");
    printf("\t3. Exit\n");
    printf("\tSelect an option: ");
}

// Function to send email
void sendEmail(const char *server, const char *username, const char *password) {
    char recipient[MAX_LEN], subject[MAX_LEN], body[MAX_LEN];
    int sock;
    struct sockaddr_in serverAddr;
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, server, &serverAddr.sin_addr);

    // Connect to the email server
    if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        return;
    }

    // Authentication
    send(sock, username, strlen(username), 0);
    send(sock, password, strlen(password), 0);
    
    // Get email details
    printf("\nEnter recipient: ");
    fgets(recipient, MAX_LEN, stdin);
    recipient[strcspn(recipient, "\n")] = 0;

    printf("Enter subject: ");
    fgets(subject, MAX_LEN, stdin);
    subject[strcspn(subject, "\n")] = 0;

    printf("Enter body: ");
    fgets(body, MAX_LEN, stdin);
    body[strcspn(body, "\n")] = 0;

    // Sending email (simplified)
    send(sock, recipient, strlen(recipient), 0);
    send(sock, subject, strlen(subject), 0);
    send(sock, body, strlen(body), 0);

    printf("Email sent to %s successfully!\n", recipient);
    close(sock);
}

// Function to receive emails
void receiveEmails(const char *server, const char *username, const char *password) {
    int sock;
    struct sockaddr_in serverAddr;
    char buffer[MAX_LEN];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, server, &serverAddr.sin_addr);

    // Connect to the email server
    if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        return;
    }

    // Authentication
    send(sock, username, strlen(username), 0);
    send(sock, password, strlen(password), 0);

    // Receiving emails (simplified)
    printf("\nFetching emails...\n");
    while (recv(sock, buffer, sizeof(buffer)-1, 0) > 0) {
        printf("%s\n", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    printf("All messages received!\n");
    close(sock);
}

int main() {
    char server[MAX_LEN], username[MAX_LEN], password[MAX_LEN];
    int choice;

    // Server and credentials input
    printf("Enter email server: ");
    fgets(server, MAX_LEN, stdin);
    server[strcspn(server, "\n")] = 0;

    printf("Enter your username: ");
    fgets(username, MAX_LEN, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter your password: ");
    fgets(password, MAX_LEN, stdin);
    password[strcspn(password, "\n")] = 0;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                sendEmail(server, username, password);
                break;
            case 2:
                receiveEmails(server, username, password);
                break;
            case 3:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}