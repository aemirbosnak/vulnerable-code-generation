//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 25
#define BUF_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE + 1];
    int bytesreceived, byteswritten;

    // create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(EXIT_FAILURE);
    }

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // receive the server's greeting message
    if ((bytesreceived = recv(sockfd, buffer, BUF_SIZE, 0)) < 0) {
        perror("Error receiving data from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytesreceived] = '\0';
    printf("%s", buffer);

    // send the HELO command
    if ((byteswritten = send(sockfd, "HELO\r\n", strlen("HELO\r\n"), 0)) < 0) {
        perror("Error sending data to server");
        exit(EXIT_FAILURE);
    }

    // receive the server's response to the HELO command
    if ((bytesreceived = recv(sockfd, buffer, BUF_SIZE, 0)) < 0) {
        perror("Error receiving data from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytesreceived] = '\0';
    printf("%s", buffer);

    // send the MAIL FROM command
    if ((byteswritten = send(sockfd, "MAIL FROM:<sender@example.com>\r\n", strlen("MAIL FROM:<sender@example.com>\r\n"), 0)) < 0) {
        perror("Error sending data to server");
        exit(EXIT_FAILURE);
    }

    // receive the server's response to the MAIL FROM command
    if ((bytesreceived = recv(sockfd, buffer, BUF_SIZE, 0)) < 0) {
        perror("Error receiving data from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytesreceived] = '\0';
    printf("%s", buffer);

    // send the RCPT TO command
    if ((byteswritten = send(sockfd, "RCPT TO:<recipient@example.com>\r\n", strlen("RCPT TO:<recipient@example.com>\r\n"), 0)) < 0) {
        perror("Error sending data to server");
        exit(EXIT_FAILURE);
    }

    // receive the server's response to the RCPT TO command
    if ((bytesreceived = recv(sockfd, buffer, BUF_SIZE, 0)) < 0) {
        perror("Error receiving data from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytesreceived] = '\0';
    printf("%s", buffer);

    // send the DATA command
    if ((byteswritten = send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0)) < 0) {
        perror("Error sending data to server");
        exit(EXIT_FAILURE);
    }

    // receive the server's response to the DATA command
    if ((bytesreceived = recv(sockfd, buffer, BUF_SIZE, 0)) < 0) {
        perror("Error receiving data from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytesreceived] = '\0';
    printf("%s", buffer);

    // send the message body
    if ((byteswritten = send(sockfd, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test message\r\n\r\nThis is a test message.\r\n.\r\n", strlen("From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test message\r\n\r\nThis is a test message.\r\n.\r\n"), 0)) < 0) {
        perror("Error sending data to server");
        exit(EXIT_FAILURE);
    }

    // receive the server's response to the message body
    if ((bytesreceived = recv(sockfd, buffer, BUF_SIZE, 0)) < 0) {
        perror("Error receiving data from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytesreceived] = '\0';
    printf("%s", buffer);

    // send the QUIT command
    if ((byteswritten = send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0)) < 0) {
        perror("Error sending data to server");
        exit(EXIT_FAILURE);
    }

    // receive the server's response to the QUIT command
    if ((bytesreceived = recv(sockfd, buffer, BUF_SIZE, 0)) < 0) {
        perror("Error receiving data from server");
        exit(EXIT_FAILURE);
    }
    buffer[bytesreceived] = '\0';
    printf("%s", buffer);

    // close the socket
    close(sockfd);

    return 0;
}