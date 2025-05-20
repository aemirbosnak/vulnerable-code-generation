//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SMTP_PORT 587
#define IMAP_PORT 993

typedef struct {
    char username[100];
    char password[100];
    char smtp_server[100];
    char imap_server[100];
} EmailAccount;

void clear_buffer(char* buffer) {
    memset(buffer, 0, BUFFER_SIZE);
}

void send_email(EmailAccount* account, const char* to, const char* subject, const char* body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set server address
    struct hostent *host = gethostbyname(account->smtp_server);
    if (host == NULL) {
        perror("No such host");
        return;
    }
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(SMTP_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return;
    }

    // Implement a simple SMTP protocol for sending email
    clear_buffer(buffer);
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", account->smtp_server);
    send(sockfd, buffer, strlen(buffer), 0);
    clear_buffer(buffer);
    
    snprintf(buffer, sizeof(buffer), "AUTH LOGIN\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    clear_buffer(buffer);

    snprintf(buffer, sizeof(buffer), "%s\r\n", account->username);
    send(sockfd, buffer, strlen(buffer), 0);
    clear_buffer(buffer);

    snprintf(buffer, sizeof(buffer), "%s\r\n", account->password);
    send(sockfd, buffer, strlen(buffer), 0);
    clear_buffer(buffer);

    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", account->username);
    send(sockfd, buffer, strlen(buffer), 0);
    clear_buffer(buffer);

    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);
    clear_buffer(buffer);
    
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    clear_buffer(buffer);

    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sockfd, buffer, strlen(buffer), 0);
    clear_buffer(buffer);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    close(sockfd);
    printf("Email sent successfully!\n");
}

void check_inbox(EmailAccount* account) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    // Set server address
    struct hostent *host = gethostbyname(account->imap_server);
    if (host == NULL) {
        perror("No such host");
        return;
    }
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(IMAP_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return;
    }

    // A simple IMAP protocol to fetch emails (pseudo implementation)
    clear_buffer(buffer);
    snprintf(buffer, sizeof(buffer), "LOGIN %s %s\r\n", account->username, account->password);
    send(sockfd, buffer, strlen(buffer), 0);
    clear_buffer(buffer);

    snprintf(buffer, sizeof(buffer), "SELECT INBOX\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    clear_buffer(buffer);

    // Here you would parse response and print emails (omitted for brevity)
    
    close(sockfd);
    printf("Inbox checked successfully!\n");
}

int main() {
    EmailAccount my_account = {
        .username = "your_email@example.com",
        .password = "your_password",
        .smtp_server = "smtp.example.com",
        .imap_server = "imap.example.com"
    };

    char choice;
    printf("Choose: (s)end email, (c)heck inbox: ");
    scanf(" %c", &choice);

    if (choice == 's') {
        send_email(&my_account, "recipient@example.com", "Test Subject", "Hello, this is a test email!");
    } else if (choice == 'c') {
        check_inbox(&my_account);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}