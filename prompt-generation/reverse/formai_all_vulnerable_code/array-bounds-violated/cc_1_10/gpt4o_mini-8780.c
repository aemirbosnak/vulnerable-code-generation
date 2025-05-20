//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "imap.example.com"
#define PORT 993
#define USERNAME "your_email@example.com"
#define PASSWORD "your_password"
#define BUFFER_SIZE 4096

void initialize_ssl() {
    SSL_load_error_strings();
    SSL_library_init();
    OpenSSL_add_all_algorithms();
}

SSL* create_ssl_connection(int server) {
    SSL_CTX *ctx;
    SSL *ssl;

    ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        fprintf(stderr, "Unable to create SSL context\n");
        exit(EXIT_FAILURE);
    }

    ssl = SSL_new(ctx);
    if (!ssl) {
        fprintf(stderr, "Unable to create SSL structure\n");
        exit(EXIT_FAILURE);
    }

    SSL_set_fd(ssl, server);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    }

    return ssl;
}

void send_command(SSL* ssl, const char* command) {
    SSL_write(ssl, command, strlen(command));
    SSL_write(ssl, "\r\n", 2);
}

void read_response(SSL* ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;

    while ((bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes] = 0;  // Null-terminate the buffer
        printf("%s", buffer);
        if (strstr(buffer, "* BYE") != NULL) {
            break;
        }
    }
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    initialize_ssl();

    // Create a TCP socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket error");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    // Connect to the IMAP server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Create an SSL connection
    SSL* ssl = create_ssl_connection(server_socket);
    
    // Send LOGIN command
    char login_command[BUFFER_SIZE];
    snprintf(login_command, sizeof(login_command), "a1 LOGIN \"%s\" \"%s\"", USERNAME, PASSWORD);
    send_command(ssl, login_command);
    read_response(ssl);

    // Send SELECT command for INBOX
    send_command(ssl, "a2 SELECT INBOX");
    read_response(ssl);

    // Fetch message headers
    send_command(ssl, "a3 FETCH 1:* (ENVELOPE)");
    read_response(ssl);

    // Logout from the server
    send_command(ssl, "a4 LOGOUT");
    read_response(ssl);

    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(server_socket);
    return 0;
}