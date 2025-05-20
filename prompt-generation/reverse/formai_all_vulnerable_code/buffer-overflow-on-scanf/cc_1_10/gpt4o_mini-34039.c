//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define SMTP_PORT 587
#define SMTP_SERVER "smtp.example.com"
#define USERNAME "your_email@example.com"
#define PASSWORD "your_password"

// Function to send an email
void send_email(const char *recipient, const char *subject, const char *body) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return;
    }
    
    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, SMTP_SERVER, &server_addr.sin_addr);

    // Connect to the SMTP server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        close(sock);
        return;
    }

    // Handshake with SMTP server
    recv(sock, buffer, BUFFER_SIZE, 0);
    sprintf(message, "EHLO localhost\r\n");
    send(sock, message, strlen(message), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    // Login
    sprintf(message, "AUTH LOGIN\r\n");
    send(sock, message, strlen(message), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    sprintf(message, "%s\r\n", USERNAME); // Base64 encode it for production
    send(sock, message, strlen(message), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    sprintf(message, "%s\r\n", PASSWORD); // Base64 encode it for production
    send(sock, message, strlen(message), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    // Send email
    sprintf(message, "MAIL FROM:<%s>\r\n", USERNAME);
    send(sock, message, strlen(message), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    sprintf(message, "RCPT TO:<%s>\r\n", recipient);
    send(sock, message, strlen(message), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    sprintf(message, "DATA\r\n");
    send(sock, message, strlen(message), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    sprintf(message, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sock, message, strlen(message), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    sprintf(message, "QUIT\r\n");
    send(sock, message, strlen(message), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    close(sock);
    printf("Email sent to %s successfully!\n", recipient);
}

// Function to display menu
void display_menu() {
    printf("Welcome to the Simple Email Client!\n");
    printf("1. Send Email\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    int choice;
    char recipient[256], subject[256], body[1024];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter recipient email: ");
                fgets(recipient, sizeof(recipient), stdin);
                strtok(recipient, "\n"); // Remove newline

                printf("Enter subject: ");
                fgets(subject, sizeof(subject), stdin);
                strtok(subject, "\n"); // Remove newline

                printf("Enter body (end with a single line with just a dot):\n");
                char *body_ptr = body;
                while (1) {
                    fgets(body_ptr, sizeof(body) - (body_ptr - body), stdin);
                    if (strcmp(body_ptr, ".\n") == 0) break;
                    body_ptr += strlen(body_ptr);
                }
                *body_ptr = '\0'; // Null-terminate the body

                send_email(recipient, subject, body);
                break;
            case 2:
                printf("Exiting the email client.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}