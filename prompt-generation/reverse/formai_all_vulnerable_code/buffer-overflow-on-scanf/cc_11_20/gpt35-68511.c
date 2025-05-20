//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024
#define CERTFILE "cert.pem"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
        perror("inet_pton");
        close(sock_fd);
        return 1;
    }

    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sock_fd);
        return 1;
    }

    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ctx) {
        perror("SSL_CTX_new");
        close(sock_fd);
        return 1;
    }

    SSL *ssl = SSL_new(ctx);
    if (!ssl) {
        perror("SSL_new");
        SSL_CTX_free(ctx);
        close(sock_fd);
        return 1;
    }

    SSL_set_fd(ssl, sock_fd);
    if (SSL_connect(ssl) != 1) {
        perror("SSL_connect");
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(sock_fd);
        return 1;
    }

    char buf[BUF_SIZE] = {'\0'};
    SSL_read(ssl, buf, BUF_SIZE); // read welcome message
    printf("%s", buf);

    // LOGIN
    char username[BUF_SIZE] = {'\0'};
    char password[BUF_SIZE] = {'\0'};

    printf("Username: ");
    scanf("%s", username);
    sprintf(buf, "LOGIN %s", username);
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, BUF_SIZE);
    if (strncmp(buf, "+OK", strlen("+OK")) != 0) {
        printf("Bad username\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(sock_fd);
        return 1;
    }

    printf("Password: ");
    scanf("%s", password);
    sprintf(buf, "%s %s", password, CERTFILE);
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, BUF_SIZE);
    if (strncmp(buf, "+OK", strlen("+OK")) != 0) {
        printf("Bad password\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        close(sock_fd);
        return 1;
    }

    printf("Connection established with IMAP server\n");

    // LIST FOLDERS
    SSL_write(ssl, "LIST", strlen("LIST"));
    SSL_read(ssl, buf, BUF_SIZE); // read OK response
    while (SSL_read(ssl, buf, BUF_SIZE) > 0) {
        if (strncmp(buf, ".", strlen(".")) == 0) {
            break;
        }
        printf("%s", buf);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock_fd);

    return 0;
}