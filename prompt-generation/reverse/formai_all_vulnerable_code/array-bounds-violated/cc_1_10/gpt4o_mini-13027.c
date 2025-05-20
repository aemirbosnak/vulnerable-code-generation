//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define DEFAULT_PORT 993
#define BUFFER_SIZE 4096

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
        perror("Unable to create SSL context");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    // Set the key and random certificate file path if necessary
    // SSL_CTX_use_certificate_file(ctx, "certificate.pem", SSL_FILETYPE_PEM);
    // SSL_CTX_use_PrivateKey_file(ctx, "privatekey.pem", SSL_FILETYPE_PEM);
}

int connect_to_imap(const char *hostname, int port) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}

void ssl_connect(SSL_CTX *ctx, int sock) {
    SSL *ssl;

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        close(sock);
        SSL_free(ssl);
        exit(EXIT_FAILURE);
    }

    printf("SSL connection established!\n");
    // Communicate over the SSL connection here...

    SSL_free(ssl);
}

void imap_send_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
}

void read_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;

    do {
        bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (bytes > 0) {
            buffer[bytes] = '\0';
            printf("%s", buffer);
        } else {
            ERR_print_errors_fp(stderr);
            break;
        }
    } while (bytes > 0);
}

void authenticate_imap(SSL *ssl, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A001 LOGIN %s %s\r\n", username, password);
    imap_send_command(ssl, command);
    read_response(ssl);
}

void list_mailboxes(SSL *ssl) {
    imap_send_command(ssl, "A002 LIST \"\" \"*\"\r\n");
    read_response(ssl);
}

void close_connection(SSL *ssl, int sock) {
    imap_send_command(ssl, "A003 LOGOUT\r\n");
    read_response(ssl);
    close(sock);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock;
    SSL_CTX *ctx;

    init_openssl();
    ctx = create_context();
    configure_context(ctx);

    sock = connect_to_imap(hostname, DEFAULT_PORT);
    
    ssl_connect(ctx, sock);

    SSL *ssl;
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);

    authenticate_imap(ssl, username, password);
    list_mailboxes(ssl);

    close_connection(ssl, sock);
    
    SSL_CTX_free(ctx);
    cleanup_openssl();

    return EXIT_SUCCESS;
}