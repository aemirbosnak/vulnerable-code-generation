//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *message;
    int n;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, "smtp.example.com", &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send HELO command
    send(sockfd, "HELO client.example.com\r\n", strlen("HELO client.example.com\r\n"), 0);

    // Send MAIL FROM command
    message = "MAIL FROM: sender@example.com\r\n";
    send(sockfd, message, strlen(message), 0);

    // Send RCPT TO command
    message = "RCPT TO: recipient@example.com\r\n";
    send(sockfd, message, strlen(message), 0);

    // Send DATA command
    message = "DATA\r\n";
    send(sockfd, message, strlen(message), 0);

    // Send message body
    strcpy(buffer, "Subject: Test Message\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, "This is a test message.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Send "." to end message
    strcpy(buffer, ".\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Read server response
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("Server response: %s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}