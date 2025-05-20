//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

// POP3 Commands
#define AUTHORIZATION 0
#define TRANSACTION 1

void pop3_send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
    send(sock, "\r\n", 2, 0);
}

void pop3_receive_response(int sock) {
    char buffer[1024];
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
}

int main() {
    char *server = "pop.example.com"; // Change this to your POP3 server
    int port = 110; // Standard POP3 port
    char username[50], password[50];

    // Creating a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change this to the server's IP

    // Connecting to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to POP3 server at %s:%d\n", server, port);

    // Getting server response
    pop3_receive_response(sock);

    // User Authentication
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline

    char auth_command[100];
    snprintf(auth_command, sizeof(auth_command), "USER %s", username);
    pop3_send_command(sock, auth_command);
    pop3_receive_response(sock);

    snprintf(auth_command, sizeof(auth_command), "PASS %s", password);
    pop3_send_command(sock, auth_command);
    pop3_receive_response(sock);

    // List Emails
    pop3_send_command(sock, "LIST");
    pop3_receive_response(sock);

    // Retrieve a specific email, say first email
    char retrieve_command[50];
    snprintf(retrieve_command, sizeof(retrieve_command), "RETR 1");
    pop3_send_command(sock, retrieve_command);
    pop3_receive_response(sock);

    // Quit Command
    pop3_send_command(sock, "QUIT");
    pop3_receive_response(sock);

    printf("\nDisconnected from POP3 server.\n");
    close(sock);
    return 0;
}