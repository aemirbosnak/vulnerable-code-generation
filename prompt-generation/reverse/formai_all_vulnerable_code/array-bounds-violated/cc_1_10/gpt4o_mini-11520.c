//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <fcntl.h>

#define IMAP_PORT 143
#define BUFFER_SIZE 1024
#define USER "your-email@example.com"
#define PASSWORD "your-password"

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("Error sending command");
    }
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving response");
    }

    buffer[bytes_received] = '\0'; // Null-terminate string
    printf("Server Response: %s", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    
    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Socket creation failed");
    }

    // Setting up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    
    // Converting IPv4 address from text to binary form
    if (inet_pton(AF_INET, "imap.example.com", &server_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connecting to the IMAP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to IMAP server failed");
    }

    // Read the initial greeting from the server
    read_response(sockfd);
    
    // Log in to the IMAP server
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", USER, PASSWORD);
    send_command(sockfd, command);
    read_response(sockfd);

    // Select the mailbox
    snprintf(command, sizeof(command), "A002 SELECT INBOX\r\n");
    send_command(sockfd, command);
    read_response(sockfd);

    // Fetch email IDs
    snprintf(command, sizeof(command), "A003 SEARCH ALL\r\n");
    send_command(sockfd, command);
    read_response(sockfd);
    
    // Close connection
    snprintf(command, sizeof(command), "A004 LOGOUT\r\n");
    send_command(sockfd, command);
    read_response(sockfd);
    
    // Closing socket
    close(sockfd);
    printf("Disconnected from IMAP server\n");

    return 0;
}