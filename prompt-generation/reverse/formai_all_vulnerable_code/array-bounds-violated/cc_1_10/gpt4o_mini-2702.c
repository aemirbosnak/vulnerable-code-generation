//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define SERVER_PORT 21
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void connect_to_server(int *sockfd, const char *server_ip) {
    struct sockaddr_in server_addr;

    // Create socket
    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    // Connect to server
    if (connect(*sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to FTP server failed");
    }
}

void listen_for_server_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive server response
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        error("Failed to receive data");
    }
}

void send_command(int sockfd, const char *command) {
    // Send command to server
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("Failed to send command");
    }
    printf("Sent: %s", command);
}

void ftp_login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    // Send USER command
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sockfd, command);
    listen_for_server_response(sockfd);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send_command(sockfd, command);
    listen_for_server_response(sockfd);
}

void ftp_list_files(int sockfd) {
    char command[BUFFER_SIZE];

    // Send LIST command
    snprintf(command, sizeof(command), "PASV\r\n");
    send_command(sockfd, command);
    listen_for_server_response(sockfd);
    
    // The server response would contain the IP and port to connect for data transfer.
    // Here we should parse it and connect to the server, but for simplicity,
    // we will just send a LIST command afterwards.
    snprintf(command, sizeof(command), "LIST\r\n");
    send_command(sockfd, command);
    listen_for_server_response(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd;

    // Connect to FTP server
    connect_to_server(&sockfd, server_ip);
    listen_for_server_response(sockfd);
    
    // Login to FTP server
    ftp_login(sockfd, username, password);
    
    // List files on FTP server
    ftp_list_files(sockfd);

    // Close the socket
    close(sockfd);
    
    return 0;
}