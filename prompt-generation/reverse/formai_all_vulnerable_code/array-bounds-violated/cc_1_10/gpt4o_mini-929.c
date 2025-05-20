//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 21
#define BUFFER_SIZE 1024

// Function to establish FTP connection
int connect_to_ftp(const char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function for sending FTP commands
void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0); // Add CRLF line termination
}

// Function to read server response
void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate string
        printf("%s", buffer);
        if (bytes_received < BUFFER_SIZE - 1) {
            break; // Break if buffer is less than max size
        }
    }
}

// Function to log into the FTP server
void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    // Username
    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command);
    read_response(sockfd);

    // Password
    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command);
    read_response(sockfd);
}

// Function to list directory contents
void list_directory(int sockfd) {
    send_command(sockfd, "PASV");
    read_response(sockfd);
    
    // We need to extract the data connection port from the PASV response
    // A simple implementation without regex for extracting port
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer)-1, 0);
    buffer[BUFFER_SIZE - 1] = '\0';

    int p1, p2, port;
    sscanf(strrchr(buffer, '(') + 1, "%*d,%*d,%*d,%*d,%d,%d", &p1, &p2);
    port = p1 * 256 + p2;

    // Create a new socket for data connection
    int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &data_addr.sin_addr); // Change to appropriate IP

    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("Data connection failed");
        close(data_sockfd);
        exit(EXIT_FAILURE);
    }

    // Send LIST command
    send_command(sockfd, "LIST");
    read_response(data_sockfd); // Read the file list

    close(data_sockfd);
}

// Main function to drive the FTP client
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = connect_to_ftp(server_ip);
    read_response(sockfd);
    
    ftp_login(sockfd, username, password);
    list_directory(sockfd);

    send_command(sockfd, "QUIT"); // Exit the FTP session
    read_response(sockfd);

    close(sockfd);
    return EXIT_SUCCESS;
}