//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>

#define SERVER "imap.gmail.com"
#define PORT 993
#define USER "your_email@gmail.com"
#define PASSWORD "your_password"

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sock;
    struct sockaddr_in addr;

    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Error creating SSL context\n");
        exit(1);
    }

    SSL_CTX_set_default_verify_paths(ctx);

    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        fprintf(stderr, "Error creating SSL object\n");
        exit(1);
    }

    if (SSL_set_fd(ssl, 0)!= 1) {
        fprintf(stderr, "Error setting SSL socket\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr))!= 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    if (SSL_connect(ssl)!= 1) {
        fprintf(stderr, "Error connecting SSL\n");
        exit(1);
    }

    char buffer[4096];
    char command[100];

    snprintf(command, sizeof(command), "LOGIN %s %s", USER, PASSWORD);
    send(sock, command, strlen(command), 0);

    while (1) {
        int bytes = SSL_read(ssl, buffer, sizeof(buffer));
        if (bytes <= 0) {
            fprintf(stderr, "Error reading from server\n");
            exit(1);
        }

        buffer[bytes] = '\0';
        printf("%s", buffer);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);

    return 0;
}