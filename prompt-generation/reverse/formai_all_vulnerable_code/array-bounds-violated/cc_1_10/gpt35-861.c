//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/md5.h>

#define HOST "imap.gmail.com"
#define PORT "993"
#define USERNAME "example@gmail.com"
#define PASSWORD "examplepassword"

SSL_CTX* InitCTX(void) {
    SSL_CTX *ctx = NULL;
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }
    return ctx;
}

int main(void) {
    SSL_CTX *ctx;
    int sockfd;

    struct addrinfo hints, *servinfo;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(HOST, PORT, &hints, &servinfo) != 0) {
        fprintf(stderr, "getaddrinfo error\n");
        exit(1);
    }

    if ((sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol)) == -1) {
        fprintf(stderr, "socket error\n");
        exit(1);
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        fprintf(stderr, "connect error\n");
        exit(1);
    }

    freeaddrinfo(servinfo);

    SSL_library_init();
    ctx = InitCTX();
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) == -1) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    char buf[1024];
    int numbytes = SSL_read(ssl, buf, sizeof(buf) - 1);
    if (numbytes > 0) {
        buf[numbytes] = '\0';
        printf("%s", buf);
    }

    char username[strlen(USERNAME) + 1];
    snprintf(username, sizeof(username), "%s", USERNAME);
    char password[strlen(PASSWORD) + 1];
    snprintf(password, sizeof(password), "%s", PASSWORD);

    char login_command[1024];
    snprintf(login_command, sizeof(login_command), "A001 LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, login_command, strlen(login_command));
    numbytes = SSL_read(ssl, buf, sizeof(buf) - 1);
    if (numbytes > 0) {
        buf[numbytes] = '\0';
        printf("%s", buf);
    }

    char select_command[1024];
    snprintf(select_command, sizeof(select_command), "A002 SELECT \"INBOX\"\r\n");
    SSL_write(ssl, select_command, strlen(select_command));
    numbytes = SSL_read(ssl, buf, sizeof(buf) - 1);
    if (numbytes > 0) {
        buf[numbytes] = '\0';
        printf("%s", buf);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);

    return 0;
}