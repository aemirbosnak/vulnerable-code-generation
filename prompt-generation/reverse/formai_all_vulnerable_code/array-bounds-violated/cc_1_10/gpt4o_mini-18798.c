//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER_ADDR "imap.example.com"
#define SERVER_PORT 993
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void init_ssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

SSL_CTX *create_context() {
    const SSL_METHOD *method;
    SSL_CTX *ctx;

    method = SSLv23_client_method();
    ctx = SSL_CTX_new(method);
    
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    
    return ctx;
}

void cleanup_ssl(SSL_CTX *ctx) {
    SSL_CTX_free(ctx);
    EVP_cleanup();
}

int connect_to_server(const char *address, int port) {
    struct sockaddr_in serv_addr;
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    
    if (inet_pton(AF_INET, address, &serv_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }
    
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection failed");
    }

    return sockfd;
}

void imap_send(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
    SSL_write(ssl, "\r\n", 2);
}

void imap_response(SSL *ssl) {
    char buffer[BUFFER_SIZE] = {0};
    int len;

    while ((len = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[len] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO") || strstr(buffer, "BAD")) {
            break; // Exit on response completion
        }
    }
}

void login(SSL *ssl, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "A001 LOGIN %s %s", username, password);
    imap_send(ssl, command);
    imap_response(ssl);
}

void list_mailboxes(SSL *ssl) {
    imap_send(ssl, "A002 LIST \"\" \"*\"");
    imap_response(ssl);
}

void select_mailbox(SSL *ssl, const char *mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A003 SELECT \"%s\"", mailbox);
    imap_send(ssl, command);
    imap_response(ssl);
}

void fetch_emails(SSL *ssl) {
    imap_send(ssl, "A004 FETCH 1:* (ENVELOPE)");
    imap_response(ssl);
}

int main() {
    int sockfd;
    SSL_CTX *ctx;
    SSL *ssl;

    init_ssl();
    ctx = create_context();
    
    sockfd = connect_to_server(SERVER_ADDR, SERVER_PORT);
    
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    } else {
        printf("SSL connection established\n");

        login(ssl, "your_username@example.com", "your_password");
        list_mailboxes(ssl);
        select_mailbox(ssl, "INBOX");
        fetch_emails(ssl);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    cleanup_ssl(ctx);

    return 0;
}