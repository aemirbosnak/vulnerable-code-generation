//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUF_SIZE 1024
#define FTP_PORT 21

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    printf("Sending command: %s\n", command);
    send(sockfd, command, strlen(command), 0);
}

void receive_response(int sockfd) {
    char buffer[BUF_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving response");
    }
    buffer[bytes_received] = '\0';
    printf("Server Response: %s", buffer);
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Define the sockaddr_in structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to your FTP server IP
    server_addr.sin_port = htons(FTP_PORT);

    // Connect to the FTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to FTP server");
    }
    printf("Connected to FTP server!\n");

    // Receive welcome message
    receive_response(sockfd);

    // Login to the FTP server
    const char *username = "myusername"; // Change to your username
    const char *password = "mypassword"; // Change to your password
    char command[BUF_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    receive_response(sockfd);

    // List files in the current directory
    send_command(sockfd, "PASV\r\n");
    receive_response(sockfd);

    // You might want to parse the PASV response for IP details
    // Here, we'll skip to LIST command for simplicity
    send_command(sockfd, "LIST\r\n");
    receive_response(sockfd);

    // Assume we know the filename we want
    const char *filename = "example.txt"; // Change to the file you want to download
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Here you'd typically handle the data connection for downloading files
    // For now, we'll simply conclude the interaction
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    // Clean up and close the connection
    close(sockfd);
    printf("Disconnected from FTP server. Goodbye!\n");
    
    return 0;
}