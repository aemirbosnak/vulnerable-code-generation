//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "imap.gmail.com"
#define PORT 993
#define USER "your_email"
#define PASS "your_password"

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sd;
    char buffer[1024];

    // Initialize SSL context
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // Load CA certificates
    if (!SSL_CTX_load_verify_locations(ctx, "cacert.pem", NULL)) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // Create SSL object
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // Connect to server
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Start SSL handshake
    if (SSL_connect(ssl)!= 1) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // Login to server
    char *login = "LOGIN ";
    strcat(login, USER);
    strcat(login, " ");
    strcat(login, PASS);
    strcat(login, "\r\n");

    send(sd, login, strlen(login), 0);

    char response[1024];
    recv(sd, response, sizeof(response), 0);

    printf("Response: %s", response);

    close(sd);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    return 0;
}