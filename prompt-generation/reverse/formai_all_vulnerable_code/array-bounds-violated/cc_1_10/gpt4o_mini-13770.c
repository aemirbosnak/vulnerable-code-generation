//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAXLINE 1024
#define POP3_PORT 110

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("Error sending command");
    }
    printf("SENT: %s", cmd);
}

void receive_response(int sockfd) {
    char buffer[MAXLINE];
    int n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        error("Error receiving response");
    }
    buffer[n] = '\0'; // Null terminate the buffer
    printf("RECEIVED: %s", buffer);
}

void pop3_connect(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Error creating socket");
    }

    // Server address setup
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    // Receive server greeting
    receive_response(sockfd);

    // Authenticate
    send_command(sockfd, "USER <username>\r\n");
    receive_response(sockfd);
    send_command(sockfd, "PASS <password>\r\n");
    receive_response(sockfd);

    // List messages
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);

    // Retrieve a single message
    send_command(sockfd, "RETR 1\r\n");
    receive_response(sockfd);

    // Delete a message
    send_command(sockfd, "DELE 1\r\n");
    receive_response(sockfd);

    // Quit session
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    // Close socket
    close(sockfd);
}

int main() {
    const char *hostname = "127.0.0.1"; // Use your POP3 server address
    pop3_connect(hostname);
    return 0;
}