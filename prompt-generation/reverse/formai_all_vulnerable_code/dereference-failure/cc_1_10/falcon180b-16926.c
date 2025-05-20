//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <openssl/ssl.h>

#define BUF_SIZE 1024

static void die(const char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char *argv[])
{
    SSL_CTX *ctx;
    SSL *ssl;
    int sd;
    struct hostent *he;
    struct sockaddr_in sa;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL)
        die("SSL_CTX_new");

    SSL_CTX_set_default_verify_paths(ctx);

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0)
        die("socket");

    he = gethostbyname(argv[1]);
    if (he == NULL)
        die("gethostbyname");

    memcpy(&sa.sin_addr, he->h_addr, he->h_length);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(atoi(argv[2]));

    if (connect(sd, (struct sockaddr *)&sa, sizeof(sa)) < 0)
        die("connect");

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sd);

    if (SSL_connect(ssl) <= 0)
        die("SSL_connect");

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    char buf[BUF_SIZE];
    while (fgets(buf, sizeof(buf), stdin)!= NULL) {
        int len = strlen(buf);
        if (buf[len - 1] == '\n')
            buf[--len] = '\0';

        SSL_write(ssl, buf, len);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    close(sd);

    return 0;
}