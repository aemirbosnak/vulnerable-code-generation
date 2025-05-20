//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFSIZE 1024

void recv_and_print(SSL *ssl) {
    char buf[BUFSIZE];
    int bytes = SSL_read(ssl, buf, sizeof(buf));
    if (bytes < 0) {
        printf("Error reading data from IMAP server\n");
    } else if (bytes > 0) {
        buf[bytes] = '\0';
        printf("IMAP server says: %s", buf);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s IMAP_SERVER_USERNAME IMAP_SERVER_PASSWORD IMAP_SERVER_ADDRESS\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *username = argv[1];
    const char *password = argv[2];
    const char *server_address = argv[3];
    int server_port = 993;

    // Open a socket to the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);
    server.sin_addr.s_addr = inet_addr(server_address);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error connecting to server\n");
        exit(EXIT_FAILURE);
    }

    // Initialize OpenSSL
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    const SSL_METHOD *method = SSLv23_client_method();
    SSL_CTX *ctx = SSL_CTX_new(method);
    if (ctx == NULL) {
        printf("Error creating SSL context\n");
        exit(EXIT_FAILURE);
    }
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) < 0) {
        printf("Error establishing SSL connection\n");
        exit(EXIT_FAILURE);
    }

    // Send login command to server
    char login_cmd[BUFSIZ];
    sprintf(login_cmd, "LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, login_cmd, strlen(login_cmd));
    recv_and_print(ssl);

    // Send SELECT command to server
    SSL_write(ssl, "SELECT INBOX\r\n", strlen("SELECT INBOX\r\n"));
    recv_and_print(ssl);

    // Send FETCH command to server
    SSL_write(ssl, "FETCH 1:* (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)])\r\n", strlen("FETCH 1:* (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)])\r\n"));
    recv_and_print(ssl);

    // Send LOGOUT command to server
    SSL_write(ssl, "LOGOUT\r\n", strlen("LOGOUT\r\n"));
    recv_and_print(ssl);

    // Cleanup and exit
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    exit(EXIT_SUCCESS);
}