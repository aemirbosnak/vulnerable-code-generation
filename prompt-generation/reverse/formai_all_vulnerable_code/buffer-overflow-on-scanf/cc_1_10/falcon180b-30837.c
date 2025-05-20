//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rand.h>

#define PORT 993
#define BUFSIZE 1024

SSL *ssl;
SSL_CTX *ctx;
BIO *bio;

int main() {
    char *host;
    char *user;
    char *pass;
    char *folder;

    printf("Enter IMAP host: ");
    scanf("%s", host);

    printf("Enter username: ");
    scanf("%s", user);

    printf("Enter password: ");
    scanf("%s", pass);

    printf("Enter folder name: ");
    scanf("%s", folder);

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    ctx = SSL_CTX_new(TLS_client_method());

    SSL_CTX_set_options(ctx, SSL_OP_ALL);
    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, NULL);

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, socket(AF_INET, SOCK_STREAM, IPPROTO_TCP));

    if (connect(SSL_get_fd(ssl), gethostbyname(host), sizeof(struct sockaddr_in)) == -1) {
        printf("Connection failed!\n");
        exit(1);
    }

    if (SSL_connect(ssl)!= 1) {
        printf("SSL connection failed!\n");
        exit(1);
    }

    char *login_cmd = "LOGIN ";
    strcat(login_cmd, user);
    strcat(login_cmd, " ");
    strcat(login_cmd, pass);
    strcat(login_cmd, " ");

    SSL_write(ssl, login_cmd, strlen(login_cmd));

    char *select_cmd = "SELECT ";
    strcat(select_cmd, folder);
    strcat(select_cmd, " ");

    SSL_write(ssl, select_cmd, strlen(select_cmd));

    char buf[BUFSIZE];
    while (1) {
        int n = SSL_read(ssl, buf, BUFSIZE);
        if (n <= 0) {
            break;
        }
        buf[n] = '\0';
        printf("%s", buf);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(SSL_get_fd(ssl));

    return 0;
}