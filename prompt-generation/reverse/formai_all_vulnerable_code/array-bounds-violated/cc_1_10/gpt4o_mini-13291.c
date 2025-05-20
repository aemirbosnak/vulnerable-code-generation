//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int connect_to_server(const char *server_ip) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Error creating socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address/ Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to server failed");
    }

    return sock;
}

void send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        handle_error("Error receiving response");
    }

    buffer[bytes_received] = '\0';
    printf("Server Response: %s\n", buffer);
}

void login(int sock, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    send_command(sock, buffer);
    receive_response(sock);

    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    send_command(sock, buffer);
    receive_response(sock);
}

void list_emails(int sock) {
    send_command(sock, "LIST\r\n");
    receive_response(sock);
}

void retrieve_email(int sock, const char *email_number) {
    char buffer[BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "RETR %s\r\n", email_number);
    send_command(sock, buffer);
    receive_response(sock);
}

void delete_email(int sock, const char *email_number) {
    char buffer[BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "DELE %s\r\n", email_number);
    send_command(sock, buffer);
    receive_response(sock);
}

void quit(int sock) {
    send_command(sock, "QUIT\r\n");
    receive_response(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock = connect_to_server(server_ip);
    printf("Connected to POP3 server at %s\n", server_ip);

    receive_response(sock); // Initial server greeting

    login(sock, username, password);
    list_emails(sock);

    char email_number[10];
    printf("Enter the email number you want to retrieve: ");
    fgets(email_number, sizeof(email_number), stdin);
    strtok(email_number, "\n"); // Remove trailing newline
    retrieve_email(sock, email_number);

    printf("Enter the email number you want to delete: ");
    fgets(email_number, sizeof(email_number), stdin);
    strtok(email_number, "\n"); // Remove trailing newline
    delete_email(sock, email_number);

    quit(sock);
    close(sock);
    return 0;
}