//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Get server information
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Set up server address struct
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    printf("Connected!\n");

    char buffer[MAX_BUFFER];
    int n;

    // Send HELO message
    printf("Sending HELO message...\n");
    snprintf(buffer, MAX_BUFFER, "HELO\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    // Wait for response
    memset(buffer, 0, MAX_BUFFER);
    n = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (n < 0) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Server response to HELO: %s", buffer);

    // Send MAIL FROM message
    printf("Sending MAIL FROM message...\n");
    snprintf(buffer, MAX_BUFFER, "MAIL FROM:<sender@example.com>\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    // Wait for response
    memset(buffer, 0, MAX_BUFFER);
    n = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (n < 0) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Server response to MAIL FROM: %s", buffer);

    // Send RCPT TO message
    printf("Sending RCPT TO message...\n");
    snprintf(buffer, MAX_BUFFER, "RCPT TO:<recipient@example.com>\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    // Wait for response
    memset(buffer, 0, MAX_BUFFER);
    n = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (n < 0) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Server response to RCPT TO: %s", buffer);

    // Send DATA message
    printf("Sending DATA message...\n");
    snprintf(buffer, MAX_BUFFER, "DATA\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    // Wait for response
    memset(buffer, 0, MAX_BUFFER);
    n = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (n < 0) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Server response to DATA: %s", buffer);

    // Send message body
    printf("Sending message body...\n");
    snprintf(buffer, MAX_BUFFER, "Message body goes here.\r\n.\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    // Wait for response
    memset(buffer, 0, MAX_BUFFER);
    n = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (n < 0) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Server response to message body: %s", buffer);

    // Send QUIT message
    printf("Sending QUIT message...\n");
    snprintf(buffer, MAX_BUFFER, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    // Wait for response
    memset(buffer, 0, MAX_BUFFER);
    n = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (n < 0) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }
    printf("Server response to QUIT: %s", buffer);

    // Close socket
    close(sockfd);

    printf("Disconnected!\n");

    return EXIT_SUCCESS;
}