//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];
    int n;
    int port = 110;
    char* host = "localhost";

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    inet_pton(AF_INET, host, &serveraddr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send POP3 commands
    send(sockfd, "USER test\r\n", strlen("USER test\r\n"), 0);
    send(sockfd, "PASS test\r\n", strlen("PASS test\r\n"), 0);
    send(sockfd, "STAT\r\n", strlen("STAT\r\n"), 0);

    // Receive server response
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        printf("Error receiving server response\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}