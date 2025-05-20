//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: ultraprecise
// smtp_client.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n, i;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUF_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip address>\n", argv[0]);
        exit(1);
    }

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(1);
    }

    // setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton() failed");
        exit(1);
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }

    // send hello message
    char *hello = "HELO <hostname>\r\n";
    if (send(sockfd, hello, strlen(hello), 0) < 0) {
        perror("send() failed");
        exit(1);
    }

    // receive response
    n = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    if (n < 0) {
        perror("recv() failed");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Response: %s\n", buffer);

    // send mail from
    char *from = "MAIL FROM: <sender@example.com>\r\n";
    if (send(sockfd, from, strlen(from), 0) < 0) {
        perror("send() failed");
        exit(1);
    }

    // receive response
    n = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    if (n < 0) {
        perror("recv() failed");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Response: %s\n", buffer);

    // send rcpt to
    char *to = "RCPT TO: <recipient@example.com>\r\n";
    if (send(sockfd, to, strlen(to), 0) < 0) {
        perror("send() failed");
        exit(1);
    }

    // receive response
    n = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    if (n < 0) {
        perror("recv() failed");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Response: %s\n", buffer);

    // send data
    char *data = "DATA\r\n";
    if (send(sockfd, data, strlen(data), 0) < 0) {
        perror("send() failed");
        exit(1);
    }

    // receive response
    n = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    if (n < 0) {
        perror("recv() failed");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Response: %s\n", buffer);

    // send message
    char *message = "From: <sender@example.com>\r\n"
                    "To: <recipient@example.com>\r\n"
                    "Subject: Test message\r\n"
                    "\r\n"
                    "This is a test message.\r\n"
                    ".\r\n";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send() failed");
        exit(1);
    }

    // receive response
    n = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    if (n < 0) {
        perror("recv() failed");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Response: %s\n", buffer);

    // send quit
    char *quit = "QUIT\r\n";
    if (send(sockfd, quit, strlen(quit), 0) < 0) {
        perror("send() failed");
        exit(1);
    }

    // receive response
    n = recv(sockfd, buffer, MAX_BUF_SIZE, 0);
    if (n < 0) {
        perror("recv() failed");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Response: %s\n", buffer);

    // close socket
    close(sockfd);

    return 0;
}