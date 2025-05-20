//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void display_menu() {
    printf("\n--- Grateful Email Client ---\n");
    printf("1. Send an Email\n");
    printf("2. Receive Emails\n");
    printf("3. Exit\n");
    printf("----------------------------\n");
}

void send_email(const char *smtp_server, const char *from_email, const char *to_email, const char *subject, const char *body) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    
    printf("Connecting to SMTP server: %s...\n", smtp_server);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(25);
    server.sin_addr.s_addr = inet_addr(smtp_server);
    
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed!");
        return;
    }

    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "MAIL FROM:<%s>\r\n", from_email);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "RCPT TO:<%s>\r\n", to_email);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    close(sock);
    printf("Email sent successfully! Thank you for choosing us!\n");
}

void receive_emails(const char *imap_server, const char *email, const char *password) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    printf("Connecting to IMAP server: %s...\n", imap_server);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(143);
    server.sin_addr.s_addr = inet_addr(imap_server);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed!");
        return;
    }

    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "A001 LOGIN %s %s\r\n", email, password);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "A002 SELECT INBOX\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    sprintf(buffer, "A003 FETCH 1:* (FLAGS SUBJECT)\r\n");
    send(sock, buffer, strlen(buffer), 0);
    while (recv(sock, buffer, BUFFER_SIZE, 0) > 0) {
        printf("%s", buffer);
        if (strstr(buffer, "A003") != NULL) break; // Break after we get all emails
    }

    sprintf(buffer, "A004 LOGOUT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    close(sock);
    printf("All emails retrieved! Thank you for using our service!\n");
}

int main() {
    int choice;
    char smtp_server[100], imap_server[100], from_email[100], to_email[100], subject[100], body[500], email[100], password[100];

    printf("Welcome to the Grateful Email Client!\n");
    printf("Please enter your SMTP server address: ");
    scanf("%s", smtp_server);
    
    printf("Please enter your IMAP server address: ");
    scanf("%s", imap_server);
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your email: ");
                scanf("%s", from_email);
                printf("Enter recipient email: ");
                scanf("%s", to_email);
                printf("Enter subject: ");
                scanf(" %[^\n]", subject);
                printf("Enter email body: ");
                scanf(" %[^\n]", body);
                send_email(smtp_server, from_email, to_email, subject, body);
                break;
            case 2:
                printf("Enter your email: ");
                scanf("%s", email);
                printf("Enter your password: ");
                scanf("%s", password);
                receive_emails(imap_server, email, password);
                break;
            case 3:
                printf("Thank you for using the Grateful Email Client! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
        }
    }

    return 0;
}