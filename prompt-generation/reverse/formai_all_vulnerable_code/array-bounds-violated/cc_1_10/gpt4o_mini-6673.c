//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define COMMAND_SIZE 256

// Function to send command to the FTP server
void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

// Function to receive response from the FTP server
void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null terminate the buffer
        printf("%s", buffer);
        if (strlen(buffer) < BUFFER_SIZE - 1) break; // Exit on short packets
    }
}

// Function to log in to the FTP server
void ftp_login(int sock) {
    char command[COMMAND_SIZE];
    
    // Send USER command
    printf("Enter username: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0; // Remove trailing newline
    snprintf(command, sizeof(command), "USER %s\r\n", command);
    send_command(sock, command);
    receive_response(sock);

    // Send PASS command
    printf("Enter password: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = 0; // Remove trailing newline
    snprintf(command, sizeof(command), "PASS %s\r\n", command);
    send_command(sock, command);
    receive_response(sock);
}

// Function to list files in the current directory
void ftp_list(int sock) {
    char command[COMMAND_SIZE];
    snprintf(command, sizeof(command), "PASV\r\n");
    send_command(sock, command);
    receive_response(sock);
}

// Function to download a file
void ftp_get(int sock) {
    char command[COMMAND_SIZE];
    char filename[COMMAND_SIZE];

    printf("Filename to download: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove trailing newline

    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    send_command(sock, command);
    receive_response(sock);
}

// Main FTP client function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to FTP server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }
    
    // Wait for server response
    receive_response(sock);

    // Log in process
    ftp_login(sock);

    // List files
    ftp_list(sock);

    // Download a file
    ftp_get(sock);

    // Close socket
    close(sock);
    
    return 0;
}