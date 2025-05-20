//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER_ADDR "mail.example.com"
#define SERVER_PORT 993

int main() {
    // Create SSL context
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ctx) {
        fprintf(stderr, "Error creating SSL context\n");
        return 1;
    }

    // Load trust store
    if (SSL_CTX_load_verify_locations(ctx, NULL, "/etc/ssl/certs") != 1) {
        fprintf(stderr, "Error loading trust store\n");
        SSL_CTX_free(ctx);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error creating socket\n");
        SSL_CTX_free(ctx);
        return 1;
    }

    // Connect to server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    inet_aton(SERVER_ADDR, &addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        close(sock);
        SSL_CTX_free(ctx);
        return 1;
    }

    // Set up SSL connection
    SSL *ssl = SSL_new(ctx);
    if (!ssl) {
        fprintf(stderr, "Error creating SSL connection\n");
        close(sock);
        SSL_CTX_free(ctx);
        return 1;
    }
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) != 1) {
        fprintf(stderr, "Error establishing SSL connection\n");
        SSL_free(ssl);
        close(sock);
        SSL_CTX_free(ctx);
        return 1;
    }

    // Authenticate
    char username[256], password[256];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    char command[1024];
    sprintf(command, "a001 LOGIN %s %s", username, password);
    char response[1024];
    SSL_write(ssl, command, strlen(command));
    SSL_read(ssl, response, sizeof(response));
    if (response[0] != 'a' || response[1] != '0' || response[2] != '1' || response[3] != ' ' || response[4] != 'O' || response[5] != 'K') {
        fprintf(stderr, "Error logging in\n");
        SSL_write(ssl, "a002 LOGOUT", strlen("a002 LOGOUT"));
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sock);
        SSL_CTX_free(ctx);
        return 1;
    }

    // Select mailbox
    sprintf(command, "a002 SELECT INBOX");
    SSL_write(ssl, command, strlen(command));
    SSL_read(ssl, response, sizeof(response));
    if (response[0] != 'a' || response[1] != '0' || response[2] != '2' || response[3] != ' ' || response[4] != 'O' || response[5] != 'K') {
        fprintf(stderr, "Error selecting mailbox\n");
        SSL_write(ssl, "a003 LOGOUT", strlen("a003 LOGOUT"));
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sock);
        SSL_CTX_free(ctx);
        return 1;
    }

    // List messages
    sprintf(command, "a003 FETCH 1:* FLAGS");
    SSL_write(ssl, command, strlen(command));
    SSL_read(ssl, response, sizeof(response));
    printf("%s", response);

    // Clean up
    SSL_write(ssl, "a004 LOGOUT", strlen("a004 LOGOUT"));
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    return 0;
}