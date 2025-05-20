//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 993
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        handle_error("Failed to create socket");
    }
    return sock_fd;
}

void connect_to_server(int sock_fd, const char *server_ip) {
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_address.sin_addr);

    if (connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        handle_error("Failed to connect to server");
    }
}

void send_imap_command(int sock_fd, const char *command) {
    send(sock_fd, command, strlen(command), 0);
}

void receive_response(int sock_fd) {
    char buffer[BUFFER_SIZE] = {0};
    int bytes_read = recv(sock_fd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_read < 0) {
        handle_error("Failed to receive response");
    }
    buffer[bytes_read] = '\0';
    printf("Server response: %s\n", buffer);
}

void login(int sock_fd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "a001 LOGIN %s %s\r\n", username, password);
    printf("Sending login command: %s", command);
    send_imap_command(sock_fd, command);
    receive_response(sock_fd);
}

void list_mailboxes(int sock_fd) {
    const char *command = "a002 LIST \"\" \"*\"\r\n";
    printf("Sending list mailboxes command: %s", command);
    send_imap_command(sock_fd, command);
    receive_response(sock_fd);
}

void fetch_email(int sock_fd, const char *mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "a003 SELECT \"%s\"\r\n", mailbox);
    printf("Sending fetch email command: %s", command);
    send_imap_command(sock_fd, command);
    receive_response(sock_fd);
}

void logout(int sock_fd) {
    const char *command = "a004 LOGOUT\r\n";
    printf("Sending logout command: %s", command);
    send_imap_command(sock_fd, command);
    receive_response(sock_fd);
}

int main() {
    const char *server_ip = "192.168.1.2";  // Change to your IMAP server IP
    const char *username = "username";  // Change to your IMAP username
    const char *password = "password";  // Change to your IMAP password

    printf("Welcome to the Happy IMAP Client!\n");

    int sock_fd = create_socket();
    connect_to_server(sock_fd, server_ip);

    login(sock_fd, username, password);
    list_mailboxes(sock_fd);
    fetch_email(sock_fd, "INBOX");  // Fetch emails from INBOX
    logout(sock_fd);

    close(sock_fd);
    printf("Thank you for using the Happy IMAP Client! Goodbye!\n");
    return 0;
}