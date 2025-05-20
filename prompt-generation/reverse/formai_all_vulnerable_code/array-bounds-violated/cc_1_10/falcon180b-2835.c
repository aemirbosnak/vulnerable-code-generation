//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

#define BUFFER_SIZE 1024
#define PORT 993
#define HOST "imap.gmail.com"
#define USER "your_username"
#define PASSWORD "your_password"

int main() {
    SSL *ssl;
    SSL_CTX *ctx;
    BIO *bio;
    int sock;
    struct sockaddr_in server;

    SSL_library_init();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(SSLv23_method());
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, 0);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

    if (SSL_connect(ssl) <= 0) {
        printf("SSL_connect error\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket error\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(HOST);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Connect error\n");
        exit(1);
    }

    bio = BIO_new_socket(sock, BIO_NOCLOSE);
    SSL_set_bio(ssl, bio, bio);

    char username[50] = {0};
    strcat(username, USER);
    char password[50] = {0};
    strcat(password, PASSWORD);

    char buffer[BUFFER_SIZE] = {0};
    sprintf(buffer, "A001 LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, buffer, strlen(buffer));

    char response[BUFFER_SIZE] = {0};
    int read = SSL_read(ssl, response, BUFFER_SIZE);
    response[read] = '\0';
    printf("Response: %s", response);

    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);

    return 0;
}