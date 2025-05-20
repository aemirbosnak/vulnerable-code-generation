//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER_PORT 993
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
}

void receive_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL) {
            break; // An OK response indicates we can stop reading.
        }
    }
}

void connect_and_authenticate(const char *server, const char *username, const char *password) {
    int sock;
    struct sockaddr_in server_addr;
    SSL_CTX *ctx;
    SSL *ssl;

    // Initialize OpenSSL library
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        handle_error("SSL_CTX_new");
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("socket");
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("connect");
    }

    // Setup SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        handle_error("SSL_connect");
    }

    // Login commands to IMAP
    char imap_command[BUFFER_SIZE];

    // Send login command
    snprintf(imap_command, sizeof(imap_command), "A001 LOGIN %s %s\r\n", username, password);
    send_command(ssl, imap_command);
    receive_response(ssl);

    // List mail folders
    snprintf(imap_command, sizeof(imap_command), "A002 LIST \"\" \"*\"\r\n");
    send_command(ssl, imap_command);
    receive_response(ssl);

    // Logout
    snprintf(imap_command, sizeof(imap_command), "A003 LOGOUT\r\n");
    send_command(ssl, imap_command);
    receive_response(ssl);

    // Cleanup SSL and socket
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    EVP_cleanup();
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <imap-server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    connect_and_authenticate(server, username, password);

    return EXIT_SUCCESS;
}