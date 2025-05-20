//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define constants for usage
#define PORT 993 // Default IMAP over SSL port
#define BUFFER_SIZE 2048

// Function Prototypes
void die(const char *errorMessage);
int create_socket(const char *server);
void imap_login(int socket, const char *username, const char *password);
void list_mailboxes(int socket);
void send_command(int socket, const char *command);
void receive_response(int socket);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    
    printf("Connecting to IMAP server at %s...\n", server);
    
    int socket = create_socket(server);
    printf("Connected successfully!\n");

    imap_login(socket, username, password);
    list_mailboxes(socket);

    close(socket);
    return 0;
}

void die(const char *errorMessage) {
    perror(errorMessage);
    exit(1);
}

int create_socket(const char *server) {
    int sock;
    struct sockaddr_in server_addr;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        die("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        die("Invalid address/ Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection to the server failed");
    }

    return sock;
}

void imap_login(int socket, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "a1 LOGIN %s %s\n", username, password);
    send_command(socket, command);
}

void list_mailboxes(int socket) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "a2 LIST \"\" \"*\"\n");
    send_command(socket, command);
    receive_response(socket);
}

void send_command(int socket, const char *command) {
    if (send(socket, command, strlen(command), 0) < 0) {
        die("Failed to send command to server");
    }
    printf("Sent command: %s", command);
}

void receive_response(int socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("Received response:\n%s", buffer);
        if (strstr(buffer, "a2 OK") != NULL) {
            break; // Stop when we receive the OK response for LIST command
        }
    }

    if (bytes_received < 0) {
        die("Failed to receive data from server");
    }
}