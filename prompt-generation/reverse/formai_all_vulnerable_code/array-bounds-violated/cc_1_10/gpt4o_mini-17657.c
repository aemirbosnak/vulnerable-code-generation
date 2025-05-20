//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110 // Default POP3 port

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0);
}

void receive_response(int sockfd) {
    char buffer[1024];
    ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error_exit("recv");
    }
    buffer[bytes_received] = '\0';
    printf("Server response: %s\n", buffer);
}

int main() {
    const char *server = "your.pop3.server"; // Replace with your POP3 server
    const char *username = "your_username";   // Replace with your username
    const char *password = "your_password";   // Replace with your password

    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_exit("socket");
    }

    // Define the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        error_exit("Invalid address / Address not supported");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("connect");
    }
    
    // Receive the initial server greeting
    receive_response(sockfd);

    // Send USER command
    printf("Sending USER command...\n");
    send_command(sockfd, "USER your_username"); // Replace with your username
    receive_response(sockfd);

    // Send PASS command
    printf("Sending PASS command...\n");
    send_command(sockfd, "PASS your_password"); // Replace with your password
    receive_response(sockfd);

    // Send LIST command to retrieve message list
    printf("Sending LIST command...\n");
    send_command(sockfd, "LIST");
    receive_response(sockfd);

    // Send RETR command to download the first message
    printf("Sending RETR command for first message...\n");
    send_command(sockfd, "RETR 1");
    receive_response(sockfd);

    // Send QUIT command to logout
    printf("Sending QUIT command...\n");
    send_command(sockfd, "QUIT");
    receive_response(sockfd);

    // Clean up
    close(sockfd);
    return 0;
}