//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void connectToFtpServer(const char *hostname, int *sockfd) {
    struct sockaddr_in server_addr;

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) {
        error("ERROR opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("ERROR Invalid address/ Address not supported");
    }

    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting to server");
    }
}

void sendCommand(int sockfd, const char *command) {
    int n;
    char buffer[BUFFER_SIZE];

    // Send command to the FTP server
    send(sockfd, command, strlen(command), 0);
    
    // Receive server response
    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';
    printf("Server: %s\n", buffer);
}

void ftpLogin(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    sendCommand(sockfd, command);
    
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    sendCommand(sockfd, command);
}

void ftpUploadFile(int sockfd, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        error("ERROR opening file");
    }

    sendCommand(sockfd, "PASV\r\n"); // Switch to passive mode
    // Simplistic parsing of PASV response (needs improvement)
    char response[BUFFER_SIZE];
    recv(sockfd, response, sizeof(response) - 1, 0);
    response[strcspn(response, "\n")] = 0; // Remove trailing newline
    printf("Server: %s\n", response);

    // Send STOR command to store the file
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "STOR %s\r\n", filename);
    sendCommand(sockfd, command);

    // Read file data and send
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        send(sockfd, buffer, bytesRead, 0);
    }

    fclose(file);
    printf("File uploaded successfully.\n");
}

void ftpQuit(int sockfd) {
    sendCommand(sockfd, "QUIT\r\n");
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;
    connectToFtpServer(hostname, &sockfd);
    
    // Log in to FTP server
    ftpLogin(sockfd, username, password);

    // Upload file (example hardcoded filename)
    ftpUploadFile(sockfd, "example.txt");

    // Cleanly exit
    ftpQuit(sockfd);
    
    return 0;
}