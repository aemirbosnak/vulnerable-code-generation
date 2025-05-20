//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <openssl/crypto.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 443
#define CERTFILE "mycert.pem"

void init_openssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl() {
    EVP_cleanup();
}

void create_context(SSL_CTX **ctx) {
    const SSL_METHOD *method = SSLv23_server_method();
    *ctx = SSL_CTX_new(method);
    if (!(*ctx)) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }
}

void configure_context(SSL_CTX *ctx) {
    SSL_CTX_set_ecdh_auto(ctx, 1);
    if (SSL_CTX_use_certificate_file(ctx, CERTFILE, SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }
    if (SSL_CTX_use_PrivateKey_file(ctx, CERTFILE, SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }
}

void start_server() {
    SSL_CTX *ctx;
    create_context(&ctx);
    configure_context(ctx);

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = htonl(INADDR_ANY),
        .sin_port = htons(PORT)
    };
    if (bind(sock_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sock_fd, 1) < 0) {
        perror("ERROR on listening");
        exit(1);
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(sock_fd, (struct sockaddr*)&client_addr, &client_len);
        if (client_fd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        SSL *ssl = SSL_new(ctx);
        SSL_set_fd(ssl, client_fd);
        if (SSL_accept(ssl) <= 0) {
            ERR_print_errors_fp(stderr);
            SSL_shutdown(ssl);
            close(client_fd);
            SSL_free(ssl);
            continue;
        }

        char buffer[256];
        memset(buffer, 0, sizeof(buffer));
        int bytes = SSL_read(ssl, buffer, sizeof(buffer));
        if (bytes < 0) {
            ERR_print_errors_fp(stderr);
            SSL_shutdown(ssl);
            close(client_fd);
            SSL_free(ssl);
            continue;
        }

        buffer[bytes] = '\0';
        printf("Received message: %s\n", buffer);

        const char* response = "Hello, world!";
        SSL_write(ssl, response, strlen(response));

        SSL_shutdown(ssl);
        close(client_fd);
        SSL_free(ssl);
    }

    SSL_CTX_free(ctx);
}

int main() {
    init_openssl();
    start_server();
    cleanup_openssl();
    return 0;
}