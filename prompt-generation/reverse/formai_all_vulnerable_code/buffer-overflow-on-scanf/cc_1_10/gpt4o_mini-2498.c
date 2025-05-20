//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21

void handle_ftp_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    char response[BUFFER_SIZE];
    recv(sockfd, response, sizeof(response), 0);
    printf("Server Response: %s", response);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *ftp_server = "ftp.dlptest.com"; // Change to your FTP server
    char username[50], password[50];
    char command[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_ftp_error("Socket creation failed!");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.241.154.178"); // Replace with FTP server IP address

    // Connect to FTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_ftp_error("Connection to server failed!");
    }

    // Receive welcome message
    char response[BUFFER_SIZE];
    recv(sockfd, response, sizeof(response), 0);
    printf("Server Response: %s", response);

    // User login
    printf("Enter username: ");
    scanf("%s", username);
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);

    printf("Enter password: ");
    scanf("%s", password);
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);

    // List files
    snprintf(command, sizeof(command), "PASV\r\n");
    send_command(sockfd, command);
    
    // Here we would parse the response from PASV and connect to the data port
    // For simplicity, let's assume server responded with 227 and we extract the IP & port correctly
    snprintf(command, sizeof(command), "LIST\r\n");
    send_command(sockfd, command);

    // Simulating receiving file list response
    recv(sockfd, response, sizeof(response), 0);
    printf("File List: %s", response);

    // Download file (simplified; proper implementation would handle data connection setup)
    printf("Enter filename to download: ");
    char filename[50];
    scanf("%s", filename);
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(sockfd, command);

    // Simulating receiving a file data response
    recv(sockfd, response, sizeof(response), 0);
    printf("Receiving file data: %s", response);

    // Close the socket
    close(sockfd);
    printf("Connection closed.\n");

    return 0;
}