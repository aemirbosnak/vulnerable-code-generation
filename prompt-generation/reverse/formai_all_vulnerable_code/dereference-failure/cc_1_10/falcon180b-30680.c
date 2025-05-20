//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 993
#define SERVER_NAME "localhost"

int main(int argc, char *argv[]) {
    SSL_CTX *ctx;
    SSL *ssl;
    int sock;
    struct hostent *host;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE];
    int bytes;

    ctx = SSL_CTX_new(SSLv23_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stdout);
        exit(1);
    }

    SSL_CTX_set_default_verify_paths(ctx);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    host = gethostbyname(SERVER_NAME);
    if (host == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    memcpy(&addr.sin_addr, host->h_addr, host->h_length);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    SSL_connect(ssl);

    printf("Connected to %s:%d\n", SERVER_NAME, SERVER_PORT);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);

        SSL_write(ssl, buffer, strlen(buffer));

        bytes = SSL_read(ssl, buffer, BUFFER_SIZE);
        if (bytes <= 0) {
            printf("Disconnected\n");
            break;
        }

        printf("%s", buffer);
    }

    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);

    return 0;
}