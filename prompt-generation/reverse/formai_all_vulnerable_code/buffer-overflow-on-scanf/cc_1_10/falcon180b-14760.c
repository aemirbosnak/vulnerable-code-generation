//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// Function to reverse a string
void reverse_string(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to send an email
void send_email(int sockfd, char *username, char *password) {
    char message[BUFFER_SIZE];
    char *domain;
    char *helo;

    // Set up email message
    sprintf(message, "HELO %s\r\n", helo = "localhost");
    send(sockfd, message, strlen(message), 0);

    sprintf(message, "AUTH LOGIN\r\n");
    send(sockfd, message, strlen(message), 0);

    sprintf(message, "%s\r\n", username);
    send(sockfd, message, strlen(message), 0);

    sprintf(message, "%s\r\n", password);
    send(sockfd, message, strlen(message), 0);

    // Reverse the username and domain for the email address
    char *at_pos = strchr(username, '@');
    if (at_pos == NULL) {
        printf("Invalid username.\n");
        return;
    }

    domain = at_pos + 1;
    *at_pos = '\0';
    reverse_string(username);

    sprintf(message, "MAIL FROM:<%s@%s>\r\n", username, domain);
    send(sockfd, message, strlen(message), 0);

    sprintf(message, "RCPT TO:<%s>\r\n", username);
    send(sockfd, message, strlen(message), 0);

    sprintf(message, "DATA\r\n");
    send(sockfd, message, strlen(message), 0);

    sprintf(message, "Subject: Test Email\r\n");
    send(sockfd, message, strlen(message), 0);

    sprintf(message, "\r\nHello, World!\r\n");
    send(sockfd, message, strlen(message), 0);

    sprintf(message, ".\r\n");
    send(sockfd, message, strlen(message), 0);

    close(sockfd);
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char username[100];
    char password[100];

    // Get user input for email address and password
    printf("Enter your email address: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket.\n");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(25);
    inet_pton(AF_INET, "smtp.gmail.com", &serv_addr.sin_addr);

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server.\n");
        return 2;
    }

    // Send email
    send_email(sockfd, username, password);

    return 0;
}