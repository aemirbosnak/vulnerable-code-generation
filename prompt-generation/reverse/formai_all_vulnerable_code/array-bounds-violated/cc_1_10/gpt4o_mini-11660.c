//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void sendCommand(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
}

void receiveResponse(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes;

    do {
        bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes < 0) {
            handleError("Failed to receive response");
        }
        buffer[bytes] = '\0';
        printf("%s", buffer);
    } while (bytes > 0 && buffer[bytes - 1] != '\n');
}

void fetchMessages(int sock, const char *mailbox) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A001 SELECT %s\r\n", mailbox);
    sendCommand(sock, command);
    receiveResponse(sock);

    snprintf(command, sizeof(command), "A002 FETCH 1:* (FLAGS BODY[TEXT])\r\n");
    sendCommand(sock, command);
    receiveResponse(sock);

    snprintf(command, sizeof(command), "A003 CLOSE\r\n");
    sendCommand(sock, command);
    receiveResponse(sock);
}

void listMailboxes(int sock) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A000 LIST \"\" \"*\"\r\n");
    sendCommand(sock, command);
    receiveResponse(sock);
}

void processMailbox(int sock, const char *mailbox) {
    printf("Processing mailbox: %s\n", mailbox);
    fetchMessages(sock, mailbox);
}

void recursiveMailboxes(int sock, const char *mailbox) {
    // In a real client, this could be a recursive call based on hierarchy, 
    // assuming for simplicity we're only going to fetch the main mailbox.
    processMailbox(sock, mailbox);
}

void login(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A000 LOGIN %s %s\r\n", username, password);
    sendCommand(sock, command);
    receiveResponse(sock);
}

int main() {
    const char *host = "imap.example.com";
    const char *username = "user@example.com";
    const char *password = "password";
    struct sockaddr_in server_addr;
    SSL_CTX *ctx;
    SSL *ssl;
    int sock;

    // Initialize SSL
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) handleError("Could not initialize SSL");

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) handleError("Could not create socket");

    // Server setup
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(993); // IMAP SSL port
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        handleError("Invalid address");
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handleError("Connection to server failed");
    }

    // Create SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        handleError("SSL connection failed");
    }

    // Login
    login(sock, username, password);
    // List mailboxes and fetch messages
    listMailboxes(sock);
    recursiveMailboxes(sock, "INBOX");

    // Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    return 0;
}