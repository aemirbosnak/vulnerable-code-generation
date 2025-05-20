//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send HELO command
    send(sockfd, "HELO localhost\r\n", strlen("HELO localhost\r\n"), 0);

    // Send MAIL FROM command
    send(sockfd, "MAIL FROM: <sender@example.com>\r\n", strlen("MAIL FROM: <sender@example.com>\r\n"), 0);

    // Send RCPT TO command
    send(sockfd, "RCPT TO: <recipient@example.com>\r\n", strlen("RCPT TO: <recipient@example.com>\r\n"), 0);

    // Send DATA command
    send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0);

    // Send message body
    send(sockfd, "Subject: Test message\r\n\r\nHello, world!\r\n.\r\n", strlen("Subject: Test message\r\n\r\nHello, world!\r\n.\r\n"), 0);

    // Receive response
    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}