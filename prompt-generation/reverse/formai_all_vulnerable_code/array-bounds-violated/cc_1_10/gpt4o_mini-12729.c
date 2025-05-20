//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 993  // Standard port for IMAP over SSL

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, "\r\n", 2, 0); // IMAP commands end with CRLF
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("%s", buffer);
        if (strstr(buffer, "OK Completed") || strstr(buffer, "NO") || strstr(buffer, "BAD")) {
            break; // Stop when receiving a response code
        }
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server_ip = "imap.example.com"; // Replace with your IMAP server
    char *username = "your_email@example.com"; // Your email
    char *password = "your_password"; // Your password
    char command[BUFFER_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Prepare server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Convert and set IP address
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        close(sockfd);
        return -1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return -1;
    }

    // Wait for the server's greeting
    receive_response(sockfd);

    // Login to the server
    snprintf(command, sizeof(command), "A001 LOGIN \"%s\" \"%s\"", username, password);
    send_command(sockfd, command);
    receive_response(sockfd);

    // List mailboxes
    send_command(sockfd, "A002 LIST \"\" \"*\"");
    receive_response(sockfd);

    // Select INBOX
    send_command(sockfd, "A003 SELECT \"INBOX\"");
    receive_response(sockfd);

    // Fetch the latest emails
    send_command(sockfd, "A004 FETCH 1:* (SUBJECT)");
    receive_response(sockfd);

    // Logout
    send_command(sockfd, "A005 LOGOUT");
    receive_response(sockfd);

    // Clean up
    close(sockfd);
    return 0;
}