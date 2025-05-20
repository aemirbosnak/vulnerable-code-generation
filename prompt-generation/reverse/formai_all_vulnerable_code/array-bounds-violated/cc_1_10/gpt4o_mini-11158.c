//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void handle_error(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void pop3_send_command(int sock, const char* cmd) {
    send(sock, cmd, strlen(cmd), 0);
    printf("Sent: %s", cmd);
}

void pop3_receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    ssize_t recv_size;

    recv_size = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (recv_size < 0) {
        handle_error("recv failed");
    }
    buffer[recv_size] = '\0';
    printf("Received: %s", buffer);
}

void login_to_pop3(int sock, const char* username, const char* password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    pop3_send_command(sock, command);
    pop3_receive_response(sock);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    pop3_send_command(sock, command);
    pop3_receive_response(sock);
}

void list_emails(int sock) {
    char command[] = "LIST\r\n";

    pop3_send_command(sock, command);
    pop3_receive_response(sock);
}

void quit_pop3(int sock) {
    char command[] = "QUIT\r\n";

    pop3_send_command(sock, command);
    pop3_receive_response(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Socket creation failed");
    }

    // Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }

    printf("Connected to POP3 server: %s\n", server);
    pop3_receive_response(sock);

    // Login to the POP3 server
    login_to_pop3(sock, username, password);

    // List emails
    list_emails(sock);

    // Quit session
    quit_pop3(sock);

    // Close the socket
    close(sock);
    return 0;
}