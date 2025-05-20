//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_LINE_LEN 1024
#define MAX_BUF_LEN 4096

int main(int argc, char **argv) {

    SSL_CTX *ctx;
    SSL *ssl;
    BIO *bio;
    int sock, ret;
    struct sockaddr_in server_addr;

    char *server = "imap.gmail.com";
    char *user = "your_username";
    char *pass = "your_password";

    char buf[MAX_BUF_LEN];

    ctx = SSL_CTX_new(SSLv23_client_method());

    if (ctx == NULL) {
        fprintf(stderr, "SSL_CTX_new failed\n");
        exit(1);
    }

    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);
    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv3);

    ssl = SSL_new(ctx);

    if (ssl == NULL) {
        fprintf(stderr, "SSL_new failed\n");
        exit(1);
    }

    bio = BIO_new_socket(sock, BIO_NOCLOSE);
    SSL_set_bio(ssl, bio, bio);

    if (SSL_connect(ssl) <= 0) {
        fprintf(stderr, "SSL_connect failed\n");
        exit(1);
    }

    fprintf(stdout, "Connected to %s\n", server);

    sprintf(buf, "A001 LOGIN %s %s\r\n", user, pass);
    send(sock, buf, strlen(buf), 0);

    ret = SSL_read(ssl, buf, MAX_BUF_LEN);

    if (ret <= 0) {
        fprintf(stderr, "SSL_read failed\n");
        exit(1);
    }

    buf[ret] = '\0';

    fprintf(stdout, "Server response: %s\n", buf);

    close(sock);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    return 0;
}