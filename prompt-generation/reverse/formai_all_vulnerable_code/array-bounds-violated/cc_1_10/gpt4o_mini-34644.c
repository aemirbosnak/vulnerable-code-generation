//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_SERVER "imap.example.com"
#define IMAP_PORT 993
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket(const char *hostname, int port) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("ERROR opening socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    return sock;
}

SSL_CTX *initialize_ssl_context() {
    SSL_CTX *ctx;
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();

    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    
    return ctx;
}

void imap_send(SSL *ssl, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    SSL_write(ssl, buffer, strlen(buffer));
}

void imap_read_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;
    
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (bytes < 0) {
        error("ERROR reading response");
    }

    buffer[bytes] = '\0'; // Null-terminate the response
    printf("Response: %s", buffer);
}

void perform_imap_login(SSL *ssl, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A1 LOGIN %s %s", username, password);
    imap_send(ssl, command);
    imap_read_response(ssl);
}

void perform_imap_select(SSL *ssl, const char *mailbox) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A2 SELECT \"%s\"", mailbox);
    imap_send(ssl, command);
    imap_read_response(ssl);
}

void perform_imap_fetch(SSL *ssl, const char *msg_id) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A3 FETCH %s BODY[]", msg_id);
    imap_send(ssl, command);
    imap_read_response(ssl);
}

void cleanup(SSL *ssl, SSL_CTX *ctx, int sock) {
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <username> <password> <mailbox>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *username = argv[1];
    const char *password = argv[2];
    const char *mailbox = argv[3];

    int sock;
    SSL_CTX *ctx;
    SSL *ssl;

    sock = create_socket(IMAP_SERVER, IMAP_PORT);
    ctx = initialize_ssl_context();
    
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        cleanup(ssl, ctx, sock);
        exit(EXIT_FAILURE);
    }

    perform_imap_login(ssl, username, password);
    perform_imap_select(ssl, mailbox);
    perform_imap_fetch(ssl, "1");

    cleanup(ssl, ctx, sock);
    return 0;
}