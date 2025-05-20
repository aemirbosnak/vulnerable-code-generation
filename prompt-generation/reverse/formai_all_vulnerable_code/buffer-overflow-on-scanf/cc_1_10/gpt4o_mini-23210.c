//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SMTP_PORT 25
#define IMAP_PORT 143
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_email(const char *to, const char *subject, const char *body) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) error("Error creating socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Error connecting to email server");

    recv(sock, buffer, BUFFER_SIZE, 0);

    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", SERVER_IP);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    snprintf(buffer, sizeof(buffer), "MAIL FROM:<your_email@example.com>\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    close(sock);
}

void receive_email() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) error("Error creating socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Error connecting to email server");

    recv(sock, buffer, BUFFER_SIZE, 0);

    send(sock, "a001 LOGIN your_email@example.com your_password\r\n", 49, 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    send(sock, "a002 SELECT INBOX\r\n", 20, 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    send(sock, "a003 FETCH 1 BODY[]\r\n", 22, 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Email Body:\n%s\n", buffer);

    close(sock);
}

int main() {
    int choice;
    char to[100], subject[100], body[1000];

    while (1) {
        printf("Email Client Menu:\n");
        printf("1. Send Email\n");
        printf("2. Receive Email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter recipient email: ");
                scanf("%s", to);
                printf("Enter subject: ");
                getchar();  // to clear the newline character after choice
                fgets(subject, sizeof(subject), stdin);
                subject[strcspn(subject, "\n")] = 0; // remove newline
                printf("Enter message body: ");
                fgets(body, sizeof(body), stdin);
                body[strcspn(body, "\n")] = 0; // remove newline
                send_email(to, subject, body);
                break;
            case 2:
                receive_email();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}