//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define FTP_PORT 21
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("-> %s", command);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("<- %s", buffer);
        if (buffer[3] == ' ') break; // Exit on response code
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <FTP Server> <Username> <Password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ftp_server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Define server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(ftp_server);

    // Connect to FTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to FTP server failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive initial server response
    receive_response(sockfd);

    // Login
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);

    // List files in the current directory
    snprintf(command, sizeof(command), "PASV\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);

    // Simulate entering passive mode and getting a data connection
    // For simplicity, the passive address and port extraction is skipped.
    // In real-world usage, you would parse the received response for it.

    // List files
    snprintf(command, sizeof(command), "LIST\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);

    // Download a file (example)
    strcpy(command, "RETR example.txt\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);

    // Close socket
    close(sockfd);
    printf("Disconnected from server.\n");
    return EXIT_SUCCESS;
}