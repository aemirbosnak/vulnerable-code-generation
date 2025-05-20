//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 993
#define BUFFER_SIZE 1024
#define SERVER "imap.example.com" // replace with actual IMAP server

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0)
        error("Send command failed");
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK")) // Checking for the OK response
            break;
    }

    if (bytes_read < 0)
        error("Receive failed");
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket");

    // Define server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("YOUR.IMAP.SERVER.IP"); // replace with actual IP

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("Connection failed");

    printf("Connected to IMAP server.\n");

    // Send LOGIN command
    char login_command[BUFFER_SIZE];
    snprintf(login_command, sizeof(login_command), "A001 LOGIN your_username your_password\r\n"); // replace with actual credentials

    send_command(sockfd, login_command);
    receive_response(sockfd);

    // Send SELECT command to choose the mailbox
    send_command(sockfd, "A002 SELECT INBOX\r\n");
    receive_response(sockfd);

    // Send FETCH command to retrieve email headers
    send_command(sockfd, "A003 FETCH 1:5 (ENVELOPE)\r\n");
    receive_response(sockfd);

    // Logout from server
    send_command(sockfd, "A004 LOGOUT\r\n");
    receive_response(sockfd);

    // Close socket
    close(sockfd);
    printf("Disconnected from IMAP server.\n");

    return 0;
}