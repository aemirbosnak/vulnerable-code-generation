//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Define constants for IMAP protocol
#define IMAP_PORT 143
#define BUFFER_SIZE 4096
#define SERVER_ADDRESS "imap.example.com"

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to send IMAP command
void send_imap_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("Error sending command");
    }
}

// Function to receive IMAP response
void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    // Receive response from the server
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL || strstr(buffer, "BYE") != NULL) {
            break; // Break on successful or disconnect response
        }
    }
    if (bytes_received < 0) {
        error("Error receiving response");
    }
}

// Main function to create IMAP client
int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Server address setup
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    
    // Convert IP address to binary
    if (inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }
    
    // Receive server greeting
    receive_response(sockfd);

    // Send LOGIN command
    send_imap_command(sockfd, "A001 LOGIN your_email@example.com your_password\r\n");
    receive_response(sockfd);

    // Send LIST command to see mailboxes
    send_imap_command(sockfd, "A002 LIST \"\" \"*\"\r\n");
    receive_response(sockfd);

    // Send SELECT command to choose INBOX
    send_imap_command(sockfd, "A003 SELECT INBOX\r\n");
    receive_response(sockfd);

    // Send FETCH command to get messages
    send_imap_command(sockfd, "A004 FETCH 1:* (ENVELOPE)\r\n");
    receive_response(sockfd);

    // Send LOGOUT command to disconnect
    send_imap_command(sockfd, "A005 LOGOUT\r\n");
    receive_response(sockfd);

    // Close socket
    close(sockfd);
    return 0;
}