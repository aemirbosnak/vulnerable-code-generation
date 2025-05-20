//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 25
#define POP3_SERVER "pop.example.com"
#define POP3_PORT 110
#define BUFFER_SIZE 1024

void send_email(const char* from, const char* to, const char* subject, const char* body) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.0.2.1"); // Placeholder IP

    // Connect to SMTP server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        close(sock);
        return;
    }

    // Send HELO command
    snprintf(buffer, sizeof(buffer), "HELO localhost\r\n");
    send(sock, buffer, strlen(buffer), 0);

    // Send MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", from);
    send(sock, buffer, strlen(buffer), 0);
    
    // Send RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to);
    send(sock, buffer, strlen(buffer), 0);
    
    // Send DATA command
    send(sock, "DATA\r\n", 7, 0);
    
    // Send email headers and body
    snprintf(buffer, sizeof(buffer), "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, body);
    send(sock, buffer, strlen(buffer), 0);

    // Close the connection
    close(sock);
    printf("Email sent peacefully.\n");
}

void receive_email(const char* user, const char* password) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.0.2.2"); // Placeholder IP

    // Connect to POP3 server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to POP3 server failed");
        close(sock);
        return;
    }

    // Send USER command
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", user);
    send(sock, buffer, strlen(buffer), 0);
    
    // Send PASS command
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);
    
    // Send LIST command
    send(sock, "LIST\r\n", 7, 0);
    
    // Read server response
    while (recv(sock, buffer, sizeof(buffer) - 1, 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));  // Clear buffer
    }

    // Close the connection
    close(sock);
    printf("Email retrieval complete, enjoy the calm response.\n");
}

int main() {
    int choice;
    char from[100], to[100], subject[100], body[512];
    char user[100], password[100];

    printf("Welcome to the Peaceful Email Client\n");
    printf("1. Send Email\n");
    printf("2. Receive Email\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Consume the newline character


    if (choice == 1) {
        printf("Enter your email address: ");
        fgets(from, sizeof(from), stdin);
        from[strcspn(from, "\n")] = 0; // Remove newline

        printf("Enter recipient email address: ");
        fgets(to, sizeof(to), stdin);
        to[strcspn(to, "\n")] = 0;

        printf("Enter email subject: ");
        fgets(subject, sizeof(subject), stdin);
        subject[strcspn(subject, "\n")] = 0;

        printf("Enter email body: ");
        fgets(body, sizeof(body), stdin);
        body[strcspn(body, "\n")] = 0;

        send_email(from, to, subject, body);
    } else if (choice == 2) {
        printf("Enter your email username: ");
        fgets(user, sizeof(user), stdin);
        user[strcspn(user, "\n")] = 0;

        printf("Enter your email password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0;

        receive_email(user, password);
    } else {
        printf("Invalid choice. Please choose 1 or 2.\n");
    }

    return 0;
}