//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_ADDR "smtp.gmail.com"
#define PORT 587

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    char sender[50], recipient[50], subject[1024], message[4096];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set the server address and port number
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_ADDR, &serv_addr.sin_addr) <= 0) {
        printf("Error setting server address\n");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send the HELO command
    sprintf(buffer, "HELO %s\r\n", SERVER_ADDR);
    send(sockfd, buffer, strlen(buffer), 0);

    // Set the sender and recipient email addresses
    printf("Enter sender email address: ");
    scanf("%s", sender);
    printf("Enter recipient email address: ");
    scanf("%s", recipient);

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", sender);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Set the email subject
    printf("Enter email subject: ");
    scanf("%s", subject);

    // Set the email message
    printf("Enter email message: ");
    scanf(" %[^\n]s", message);

    // Send the email headers and body
    sprintf(buffer, "From: <%s>\r\n", sender);
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "To: <%s>\r\n", recipient);
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "Subject: %s\r\n\r\n", subject);
    send(sockfd, buffer, strlen(buffer), 0);
    send(sockfd, message, strlen(message), 0);

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Close the socket and exit
    close(sockfd);
    return 0;
}