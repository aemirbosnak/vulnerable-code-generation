//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main() {
    SSL_CTX *ctx = NULL;
    SSL *ssl = NULL;
    BIO *conn = NULL;
    struct hostent *host = NULL;
    int sock = -1;
    char buffer[BUFFER_SIZE];

    SSL_library_init();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(SSLv23_method());
    if (ctx == NULL) {
        fprintf(stderr, "Error creating SSL context\n");
        return 1;
    }

    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        fprintf(stderr, "Error creating SSL object\n");
        return 1;
    }

    SSL_set_fd(ssl, 0);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

    if (SSL_connect(ssl) <= 0) {
        fprintf(stderr, "Error connecting to server\n");
        return 1;
    }

    conn = SSL_get_fd(ssl);
    host = gethostbyname("imap.gmail.com");
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)host->h_addr, host->h_length) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        return 1;
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (SSL_read(ssl, buffer, BUFFER_SIZE) <= 0) {
            fprintf(stderr, "Error reading from server\n");
            return 1;
        }

        printf("%s", buffer);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);

    return 0;
}