//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

// Function to connect to the IMAP server
int connect_to_imap(const char *server, const char *username, const char *password) {
    int sock;
    struct sockaddr_in server_addr;
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    
    // Convert the server IP address to binary format
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return -1;
    }

    // Establish connection to IMAP server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the IMAP server failed");
        close(sock);
        return -1;
    }

    return sock;
}

// Function to send an IMAP command and receive the response
void send_imap_command(int sock, const char *command) {
    char buffer[BUFFER_SIZE];
    
    // Send command with CRLF termination
    send(sock, command, strlen(command), 0);
    send(sock, "\r\n", 2, 0);
    
    // Receive response
    ssize_t bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';  // Null-terminate the buffer
        printf("%s", buffer);
    } else {
        perror("Failed to read from server");
    }
}

// Function to login to the IMAP server
void imap_login(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A1 LOGIN \"%s\" \"%s\"", username, password);
    send_imap_command(sock, command);
}

// Function to fetch the list of mailboxes
void fetch_mailboxes(int sock) {
    send_imap_command(sock, "A2 LIST \"\" \"*\"");
}

// Function to fetch headers of messages in a specific mailbox
void fetch_headers(int sock, const char *mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A3 SELECT \"%s\"", mailbox);
    send_imap_command(sock, command);
    
    // Fetch headers; modify as needed for your IMAP server
    send_imap_command(sock, "A4 FETCH 1:* (ENVELOPE)");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    // Connect to the IMAP server
    int sock = connect_to_imap(server, username, password);
    if (sock < 0) {
        return EXIT_FAILURE;
    }

    // Log in to the IMAP server
    imap_login(sock, username, password);
    
    // Fetch the list of mailboxes
    fetch_mailboxes(sock);

    // Fetch headers from the first mailbox (example)
    fetch_headers(sock, "INBOX");

    // Close the socket
    close(sock);
    return EXIT_SUCCESS;
}