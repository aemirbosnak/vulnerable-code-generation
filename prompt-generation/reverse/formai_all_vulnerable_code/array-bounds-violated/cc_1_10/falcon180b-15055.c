//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd;
    struct sockaddr_in server_addr;
    char *host = "imap.example.com";
    int port = 993;

    // Initialize SSL context
    ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Failed to create SSL context\n");
        exit(1);
    }

    // Load trusted CA certificates
    if (SSL_CTX_load_verify_locations(ctx, "ca.crt", NULL)!= 1) {
        fprintf(stderr, "Failed to load CA certificates\n");
        exit(1);
    }

    // Create SSL object
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        fprintf(stderr, "Failed to create SSL object\n");
        exit(1);
    }

    // Connect to IMAP server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Failed to create socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Failed to connect to server\n");
        exit(1);
    }

    // Start SSL handshake
    if (SSL_connect(ssl)!= 1) {
        fprintf(stderr, "Failed to establish SSL connection\n");
        exit(1);
    }

    // Send IMAP login command
    char *login_cmd = "A001 LOGIN user@example.com password\r\n";
    SSL_write(ssl, login_cmd, strlen(login_cmd));

    // Read IMAP response
    char response[1024];
    int bytes_read = SSL_read(ssl, response, sizeof(response));
    if (bytes_read <= 0) {
        fprintf(stderr, "Failed to read IMAP response\n");
        exit(1);
    }

    // Print IMAP response
    response[bytes_read] = '\0';
    printf("IMAP response: %s", response);

    // Close SSL connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    // Close socket
    close(sockfd);

    return 0;
}