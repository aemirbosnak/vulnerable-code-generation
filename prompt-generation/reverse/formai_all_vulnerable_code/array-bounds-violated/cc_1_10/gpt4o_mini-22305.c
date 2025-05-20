//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define MAX_EMAILS 100

// Function prototypes
int connect_to_pop3(const char *hostname, int port);
void send_command(int sock, const char *command);
void receive_response(int sock);
void list_emails(int sock);
void quit_pop3(int sock);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <hostname> <port> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    const char *username = argv[3];
    
    int sock = connect_to_pop3(hostname, port);
    if (sock == -1) {
        return EXIT_FAILURE;
    }

    // Login
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send_command(sock, command);
    receive_response(sock);

    // Assuming default password here, in a real program you'd ask for it
    snprintf(command, sizeof(command), "PASS password\r\n");
    send_command(sock, command);
    receive_response(sock);

    // List emails
    list_emails(sock);

    // Quit
    quit_pop3(sock);
    close(sock);
    return EXIT_SUCCESS;
}

// Function to connect to the POP3 server
int connect_to_pop3(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection to POP3 server failed");
        close(sock);
        return -1;
    }

    // Receive welcome message
    receive_response(sock);
    return sock;
}

// Function to send a command to the POP3 server
void send_command(int sock, const char *command) {
    send(sock, command, strlen(command), 0);
}

// Function to receive and print response from the server
void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Response: %s", buffer);
}

// Function to list emails
void list_emails(int sock) {
    send_command(sock, "LIST\r\n");
    receive_response(sock);
}

// Function to quit the POP3 session
void quit_pop3(int sock) {
    send_command(sock, "QUIT\r\n");
    receive_response(sock);
}