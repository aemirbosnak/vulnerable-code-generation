//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 2048
#define HOSTNAME "imap.example.com"
#define USERNAME "your_email@example.com"
#define PASSWORD "your_password"

void init_openssl() {
    SSL_load_error_strings();   
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl() {
    EVP_cleanup();
}

SSL_CTX *create_context() {
    SSL_METHOD *method;
    SSL_CTX *ctx;

    method = SSLv23_server_method();
    ctx = SSL_CTX_new(method);
    if (!ctx) {
        perror("Unable to create SSL context");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    // Set the key and cert
    if (SSL_CTX_use_certificate_file(ctx, "server-cert.pem", SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
    }
    if (SSL_CTX_use_PrivateKey_file(ctx, "server-key.pem", SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
    }
}

int connect_to_server(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void imap_send(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
    SSL_write(ssl, "\r\n", 2); // IMAP uses CRLF line endings
}

void imap_receive(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;

    while ((bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes] = 0; // Null terminate
        printf("%s", buffer);
    }
}

void imap_login(SSL *ssl, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A001 LOGIN \"%s\" \"%s\"", username, password);
    imap_send(ssl, command);
    imap_receive(ssl);
}

void imap_list_mailbox(SSL *ssl) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A002 LIST \"\" \"*\"");
    imap_send(ssl, command);
    imap_receive(ssl);
}

void imap_logout(SSL *ssl) {
    imap_send(ssl, "A003 LOGOUT");
    imap_receive(ssl);
}

int main() {
    init_openssl();
    SSL_CTX *ctx = create_context();
    configure_context(ctx);

    int sockfd = connect_to_server(HOSTNAME, IMAP_PORT);
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    } else {
        printf("SSL connection established.\n");

        // Perform IMAP operations
        imap_login(ssl, USERNAME, PASSWORD);
        imap_list_mailbox(ssl);
        imap_logout(ssl);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    cleanup_openssl();

    return 0;
}