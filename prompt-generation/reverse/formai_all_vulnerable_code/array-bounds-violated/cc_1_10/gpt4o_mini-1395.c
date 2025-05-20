//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void initialize_ssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_ssl() {
    EVP_cleanup();
}

SSL *create_ssl_connection(int sock) {
    SSL_CTX *ctx;
    SSL *ssl;

    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        perror("Unable to create SSL context");
        exit(EXIT_FAILURE);
    }

    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        perror("Unable to create SSL structure");
        SSL_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }

    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }

    return ssl;
}

void send_imap_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
    SSL_write(ssl, "\r\n", 2);
}

void receive_imap_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;

    while ((bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO") || strstr(buffer, "BAD")) {
            break;
        }
    }
}

void list_mail_folders(SSL *ssl) {
    send_imap_command(ssl, "A01 LIST \"\" \"*\"");
    receive_imap_response(ssl);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    struct sockaddr_in serv_addr;
    int sock;

    initialize_ssl();

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Unable to create socket");
        cleanup_ssl();
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(IMAP_PORT);
    inet_pton(AF_INET, server, &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Unable to connect to server");
        close(sock);
        cleanup_ssl();
        exit(EXIT_FAILURE);
    }

    SSL *ssl = create_ssl_connection(sock);

    // Login
    char command[256];
    snprintf(command, sizeof(command), "A01 LOGIN %s %s", username, password);
    send_imap_command(ssl, command);
    receive_imap_response(ssl);

    // List mail folders
    list_mail_folders(ssl);

    // Logout
    send_imap_command(ssl, "A02 LOGOUT");
    receive_imap_response(ssl);

    SSL_free(ssl);
    close(sock);
    cleanup_ssl();
    
    return 0;
}