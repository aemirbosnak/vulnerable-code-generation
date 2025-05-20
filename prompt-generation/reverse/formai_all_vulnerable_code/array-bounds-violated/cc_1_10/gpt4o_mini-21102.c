//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
} imap_client;

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int connect_to_imap_server(const char *server_address) {
    int sock;
    struct sockaddr_in server;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed");
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(IMAP_PORT);

    if (inet_pton(AF_INET, server_address, &server.sin_addr) <= 0) {
        handle_error("Invalid address or address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        handle_error("Connection failed");
    }

    return sock;
}

void send_command(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
}

void read_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    if (bytes_read < 0) {
        handle_error("Error reading response");
    }
}

void login(imap_client *client, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A01 LOGIN %s %s\r\n", username, password);
    send_command(client->socket, command);
    read_response(client->socket);
}

void list_mailboxes(imap_client *client) {
    const char *command = "A02 LIST \"\" \"*\"\r\n";
    send_command(client->socket, command);
    read_response(client->socket);
}

void fetch_emails(imap_client *client, const char *mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A03 SELECT \"%s\"\r\n", mailbox);
    send_command(client->socket, command);
    read_response(client->socket);
}

void fetch_email(int socket, int email_number) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A04 FETCH %d BODY[]\r\n", email_number);
    send_command(socket, command);
    read_response(socket);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server_address = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    imap_client client;
    client.socket = connect_to_imap_server(server_address);

    login(&client, username, password);
    list_mailboxes(&client);
    fetch_emails(&client, "INBOX");

    // Fetch first email in the inbox
    fetch_email(client.socket, 1);

    close(client.socket);
    return EXIT_SUCCESS;
}