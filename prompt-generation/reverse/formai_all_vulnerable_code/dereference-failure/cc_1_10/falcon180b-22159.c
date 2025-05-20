//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

void print_error(const char *func, int code) {
    char *error = ERR_error_string(code, NULL);
    fprintf(stderr, "%s: %s\n", func, error);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        fprintf(stderr, "Error creating SSL context\n");
        return 1;
    }

    SSL *ssl = SSL_new(ctx);
    if (!ssl) {
        fprintf(stderr, "Error creating SSL object\n");
        return 1;
    }

    SSL_set_fd(ssl, 0);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

    if (SSL_connect(ssl) <= 0) {
        fprintf(stderr, "Error connecting to server\n");
        return 1;
    }

    char *login = "LOGIN ";
    strcat(login, username);
    strcat(login, " ");
    strcat(login, password);

    send(0, login, strlen(login), 0);

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE);
        if (bytes_received <= 0) {
            fprintf(stderr, "Error reading from server\n");
            return 1;
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    return 0;
}