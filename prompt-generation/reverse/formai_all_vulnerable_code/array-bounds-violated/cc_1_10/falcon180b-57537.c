//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "imap.gmail.com"
#define PORT 993
#define USER "your_email@gmail.com"
#define PASS "your_email_password"

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    BIO *bio;
    int sock;
    char buf[1024];
    int len;
    char *server;
    char *login;
    char *passwd;

    ctx = SSL_CTX_new(SSLv23_client_method());
    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);
    SSL_CTX_set_default_verify_paths(ctx);

    ssl = SSL_new(ctx);
    bio = BIO_new_socket(sock, BIO_NOCLOSE);
    SSL_set_bio(ssl, bio, bio);

    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    login = strdup(USER);
    passwd = strdup(PASS);

    sprintf(buf, "0 LOGIN \"%s\" \"%s\"\r\n", login, passwd);
    write(sock, buf, strlen(buf));

    len = SSL_read(ssl, buf, sizeof(buf));
    buf[len] = '\0';
    printf("Server Response: %s", buf);

    close(sock);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    exit(0);
}