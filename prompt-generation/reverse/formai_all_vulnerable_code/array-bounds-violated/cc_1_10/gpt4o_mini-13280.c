//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void handle_errors(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void init_openssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl() {
    EVP_cleanup();
}

SSL_CTX *create_context() {
    const SSL_METHOD *method;
    SSL_CTX *ctx;

    method = SSLv23_client_method();
    ctx = SSL_CTX_new(method);
    if (!ctx) {
        handle_errors("Unable to create SSL context");
    }
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);
}

int connect_to_server(const char *hostname) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_errors("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        handle_errors("Invalid address/ Address not supported");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_errors("Connection failed");
    }

    return sock;
}

void send_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
}

void read_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;

    while ((bytes = SSL_read(ssl, buffer, sizeof(buffer)-1)) > 0) {
        buffer[bytes] = 0; // Null-terminate the buffer
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL) {
            break; // Successfully read response
        }
    }
}

void authenticate(SSL *ssl, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", username, password);
    send_command(ssl, command);
    read_response(ssl);
}

void fetch_mail(SSL *ssl, const char *mail_id) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A002 FETCH %s RFC822\r\n", mail_id);
    send_command(ssl, command);
    read_response(ssl);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    init_openssl();
    SSL_CTX *ctx = create_context();
    configure_context(ctx);

    int sock = connect_to_server(hostname);
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);

    if (SSL_connect(ssl) <= 0) {
        handle_errors("SSL connection failed");
    }

    printf("Connected to IMAP server!\n");

    // Authenticate
    authenticate(ssl, username, password);

    // Fetching email, assuming we want to fetch the latest email (mail ID: 1)
    fetch_mail(ssl, "1");

    // Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    cleanup_openssl();

    return EXIT_SUCCESS;
}