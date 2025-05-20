//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <unistd.h>

#define SERVER "imap.gmail.com"
#define PORT 993

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    
    char email[100];
    char password[100];
    printf("Enter your email: ");
    scanf("%s", email);
    printf("Enter your password: ");
    scanf("%s", password);

    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        printf("Error creating SSL context!\n");
        ERR_print_errors_fp(stderr);
        return -1;
    }

    int server;
    struct sockaddr_in server_addr;

    server = socket(AF_INET, SOCK_STREAM, 0);
    if (server == -1) {
        printf("Error creating socket!\n");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER);
    server_addr.sin_port = htons(PORT);

    if (connect(server, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        printf("Error connecting to server!\n");
        return -1;
    }

    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, server);

    if (SSL_connect(ssl) != 1) {
        printf("Error establishing secure connection!\n");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, ". LOGIN %s %s\r\n", email, password);
    SSL_write(ssl, buffer, strlen(buffer));
    memset(buffer, 0, BUFFER_SIZE);
    SSL_read(ssl, buffer, BUFFER_SIZE - 1);

    if (strstr(buffer, "OK") == NULL) {
        printf("Authentication failed!\n");
        return -1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, ". SELECT INBOX\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    memset(buffer, 0, BUFFER_SIZE);
    SSL_read(ssl, buffer, BUFFER_SIZE - 1);

    if (strstr(buffer, "OK") == NULL) {
        printf("Error selecting INBOX!\n");
        return -1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, ". SEARCH ALL\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    memset(buffer, 0, BUFFER_SIZE);
    SSL_read(ssl, buffer, BUFFER_SIZE - 1);

    char *ptr = strstr(buffer, "* SEARCH");
    if (ptr != NULL) {
        ptr += strlen("* SEARCH ");
        while (*ptr != '\r') {
            printf("%c", *ptr);
            ptr++;
        }
        printf(" messages in your Inbox.\n");
    } else {
        printf("Error getting message count!\n");
        return -1;
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(server);
    SSL_CTX_free(ctx);

    return 0;
}