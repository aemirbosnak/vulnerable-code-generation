//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *port = argv[2];

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    struct addrinfo *result;
    if (getaddrinfo(hostname, port, &hints, &result) != 0) {
        fprintf(stderr, "getaddrinfo() failed: %s\n", gai_strerror(errno));
        return EXIT_FAILURE;
    }

    int fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (fd == -1) {
        perror("socket()");
        return EXIT_FAILURE;
    }

    if (connect(fd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect()");
        close(fd);
        return EXIT_FAILURE;
    }

    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ctx == NULL) {
        perror("SSL_CTX_new()");
        close(fd);
        return EXIT_FAILURE;
    }

    SSL *ssl = SSL_new(ctx);
    if (ssl == NULL) {
        perror("SSL_new()");
        SSL_CTX_free(ctx);
        close(fd);
        return EXIT_FAILURE;
    }

    SSL_set_fd(ssl, fd);

    if (SSL_connect(ssl) == -1) {
        perror("SSL_connect()");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(fd);
        return EXIT_FAILURE;
    }

    const char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";

    if (SSL_write(ssl, request, strlen(request)) == -1) {
        perror("SSL_write()");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(fd);
        return EXIT_FAILURE;
    }

    char buffer[1024];
    int n;

    while ((n = SSL_read(ssl, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, n, 1, stdout);
    }

    if (n == -1) {
        perror("SSL_read()");
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(fd);

    return EXIT_SUCCESS;
}