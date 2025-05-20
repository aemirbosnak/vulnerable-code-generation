//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>

#define SERVER_ADDRESS "imap.example.com"
#define SERVER_PORT 993

#define BUFFER_SIZE 1024

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        printf("Error creating SSL context\n");
        exit(1);
    }

    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        printf("Error creating SSL object\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    SSL_set_fd(ssl, sock);
    SSL_connect(ssl);

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = SSL_read(ssl, buffer, BUFFER_SIZE - 1);
        if (bytes_read <= 0) {
            printf("Error reading from server\n");
            break;
        }
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);

    return 0;
}