//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed\n");
        exit(1);
    }

    // Set server address
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(25);
    inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Connection failed\n");
        exit(1);
    }

    // Send HELO command
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    // Send message body
    char message[1024];
    sprintf(message, "Subject: Test Message\r\n\r\nHello, World!\r\n");
    send(sockfd, message, strlen(message), 0);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}