//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BACKLOG 5
#define MAX_REQUEST_SIZE 1024

int main() {
    // Initialize the OpenSSL library
    SSL_library_init();

    // Create a new SSL context
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_server_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Load the server certificate and private key
    if (!SSL_CTX_use_certificate_file(ctx, "server.crt", SSL_FILETYPE_PEM) ||
        !SSL_CTX_use_PrivateKey_file(ctx, "server.key", SSL_FILETYPE_PEM)) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Create a new socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address and port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(443);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Create a new SSL session
        SSL *ssl = SSL_new(ctx);
        if (ssl == NULL) {
            ERR_print_errors_fp(stderr);
            close(client_sockfd);
            continue;
        }

        // Set the SSL session to use the accepted socket
        if (SSL_set_fd(ssl, client_sockfd) == 0) {
            ERR_print_errors_fp(stderr);
            SSL_free(ssl);
            close(client_sockfd);
            continue;
        }

        // Accept the SSL handshake
        if (SSL_accept(ssl) <= 0) {
            ERR_print_errors_fp(stderr);
            SSL_free(ssl);
            close(client_sockfd);
            continue;
        }

        // Read the request from the client
        char request[MAX_REQUEST_SIZE];
        int request_len = SSL_read(ssl, request, MAX_REQUEST_SIZE - 1);
        if (request_len <= 0) {
            ERR_print_errors_fp(stderr);
            SSL_free(ssl);
            close(client_sockfd);
            continue;
        }
        request[request_len] = '\0';

        // Parse the request
        char *method = strtok(request, " ");
        char *uri = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Send the response
        char response[MAX_REQUEST_SIZE];
        snprintf(response, MAX_REQUEST_SIZE, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, world!</h1>");
        int response_len = strlen(response);
        if (SSL_write(ssl, response, response_len) <= 0) {
            ERR_print_errors_fp(stderr);
            SSL_free(ssl);
            close(client_sockfd);
            continue;
        }

        // Close the SSL session
        SSL_free(ssl);

        // Close the connection
        close(client_sockfd);
    }

    // Close the socket
    close(sockfd);

    // Cleanup the OpenSSL library
    SSL_CTX_free(ctx);
    SSL_library_cleanup();

    return 0;
}