//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check for valid arguments
    if (argc != 3) {
        printf("Please provide the server IP address and port number as arguments.\n");
        exit(1);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket.\n");
        exit(1);
    }

    // Set up server address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("Invalid server address.\n");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server.\n");
        exit(1);
    }
    printf("Connected to server.\n");

    // Send SMTP commands
    char buffer[1024];
    int n;

    // Wait for the server to send its greeting message
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Send HELO command
    char *helo = "HELO client\r\n";
    n = send(sockfd, helo, strlen(helo), 0);
    if (n < 0) {
        printf("Error sending message.\n");
        exit(1);
    }

    // Wait for the server to respond to HELO
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Send MAIL FROM command
    char *from = "MAIL FROM: <sender@example.com>\r\n";
    n = send(sockfd, from, strlen(from), 0);
    if (n < 0) {
        printf("Error sending message.\n");
        exit(1);
    }

    // Wait for the server to respond to MAIL FROM
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Send RCPT TO command
    char *to = "RCPT TO: <recipient@example.com>\r\n";
    n = send(sockfd, to, strlen(to), 0);
    if (n < 0) {
        printf("Error sending message.\n");
        exit(1);
    }

    // Wait for the server to respond to RCPT TO
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Send DATA command
    char *data = "DATA\r\n";
    n = send(sockfd, data, strlen(data), 0);
    if (n < 0) {
        printf("Error sending message.\n");
        exit(1);
    }

    // Wait for the server to respond to DATA
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Send message body
    char *body = "Subject: Example email\r\n\r\nThis is an example email from a SMTP client.\r\n.\r\n";
    n = send(sockfd, body, strlen(body), 0);
    if (n < 0) {
        printf("Error sending message.\n");
        exit(1);
    }

    // Wait for the server to respond to the message
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Send QUIT command
    char *quit = "QUIT\r\n";
    n = send(sockfd, quit, strlen(quit), 0);
    if (n < 0) {
        printf("Error sending message.\n");
        exit(1);
    }

    // Wait for the server to respond to QUIT
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        printf("Error reading from server.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}