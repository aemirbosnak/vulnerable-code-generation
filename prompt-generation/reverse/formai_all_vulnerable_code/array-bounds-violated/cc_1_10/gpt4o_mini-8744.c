//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

// Function to create socket and connect to POP3 server
int connect_to_pop3_server(const char *server_ip) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to POP3 server failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to communicate with the POP3 server and send commands
void send_command(int sock, const char *command) {
    char buffer[BUFFER_SIZE];
    ssize_t n;

    // Send command to server
    send(sock, command, strlen(command), 0);
    send(sock, "\r\n", 2, 0);  // POP3 commands must end with CRLF

    // Receive response from server
    n = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';  // Null-terminate the buffer

    printf("%s", buffer);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        return 1;
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Connect to the POP3 server
    int sock = connect_to_pop3_server(server_ip);
    
    // Wait for initial server greeting
    send_command(sock, "");

    // Authenticate with USER command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sock, command);

    // Authenticate with PASS command
    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sock, command);

    // Send STAT command to get number of messages
    send_command(sock, "STAT");

    // Here we can add more commands like LIST, RETR, etc.

    // Send QUIT command to close connection
    send_command(sock, "QUIT");

    // Close the socket
    close(sock);
    
    return 0;
}