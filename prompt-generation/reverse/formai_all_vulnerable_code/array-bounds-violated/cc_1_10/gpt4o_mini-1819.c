//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 21

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("Failed to send command");
    }
    
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer)-1, 0);
    printf("Server response: %s", buffer);
}

void ftp_client(const char *hostname, const char *username, const char *password) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to the server failed");
    }

    // Login to FTP
    char command[BUFFER_SIZE];

    recv(sockfd, command, sizeof(command)-1, 0); // Get server welcome message

    sprintf(command, "USER %s\r\n", username);
    send_command(sockfd, command);

    sprintf(command, "PASS %s\r\n", password);
    send_command(sockfd, command);

    // List files in current directory
    sprintf(command, "PASV\r\n");
    send_command(sockfd, command);

    // Extracting the data port number from response (PASV)
    int p1, p2, data_port;
    sscanf(command, "227 Entering Passive Mode (%*d,%*d,%*d,%*d,%d,%d)", &p1, &p2);
    data_port = p1 * 256 + p2;

    int data_sock;
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    data_addr.sin_addr.s_addr = inet_addr(hostname);

    // Create data socket
    if ((data_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Data socket creation failed");
    }

    // Connect to data socket
    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Data connection to the server failed");
    }

    // Send LIST command
    sprintf(command, "LIST\r\n");
    send_command(sockfd, command);

    // Receive directory listing
    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(data_sock, buffer, sizeof(buffer)-1, 0);
        if (bytes_received <= 0) break;
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    // Close data socket
    close(data_sock);

    // Quit FTP
    sprintf(command, "QUIT\r\n");
    send_command(sockfd, command);

    // Close socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ftp_client(argv[1], argv[2], argv[3]);
    return 0;
}