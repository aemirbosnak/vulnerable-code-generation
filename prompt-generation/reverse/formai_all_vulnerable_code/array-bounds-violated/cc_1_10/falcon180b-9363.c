//Falcon-180B DATASET v1.0 Category: Networking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd;
    struct sockaddr_in server_addr;
    char *msg;
    int len;

    // Create SSL context
    ctx = SSL_CTX_new(SSLv23_method());
    if (ctx == NULL) {
        printf("Error creating SSL context\n");
        exit(1);
    }

    // Load trusted CA certificates
    SSL_CTX_set_default_verify_paths(ctx);

    // Create SSL object
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        printf("Error creating SSL object\n");
        exit(1);
    }

    // Set SSL options
    SSL_set_fd(ssl, 0);
    SSL_set_connect_state(ssl);

    // Connect to server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(443);
    inet_pton(AF_INET, "example.com", &server_addr.sin_addr);

    // Connect to server with TLS
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))!= 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Perform TLS handshake
    if (SSL_connect(ssl)!= 1) {
        printf("Error performing TLS handshake\n");
        exit(1);
    }

    // Send message to server
    msg = "Hello, world!";
    len = strlen(msg);
    SSL_write(ssl, msg, len);

    // Receive message from server
    char buf[1024];
    len = SSL_read(ssl, buf, sizeof(buf) - 1);
    buf[len] = '\0';
    printf("Received message: %s\n", buf);

    // Close SSL connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    // Close socket
    close(sockfd);

    return 0;
}