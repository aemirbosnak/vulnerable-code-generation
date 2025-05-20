//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 993

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s [hostname] [username]\n", argv[0]);
        exit(1);
    }

    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host %s\n", argv[1]);
        exit(1);
    }

    char buffer[2048];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    bcopy((char *)server->h_addr, (char *)&addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error: connection failed");
        exit(1);
    }

    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) == -1) {
        perror("Error: SSL connection failed");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    int result = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (result < 0) {
        perror("Error: reading from server failed");
        exit(1);
    }
    printf("%s", buffer);

    char user[256] = {0}, pass[256] = {0};
    printf("Username: %s", argv[2]);
    strcpy(user, argv[2]);
    printf("Password: ");
    scanf("%s", pass);

    snprintf(buffer, 2047, ". login %s %s\n", user, pass);
    SSL_write(ssl, buffer, strlen(buffer));

    memset(buffer, 0, sizeof(buffer));
    result = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (result < 0) {
        perror("Error: reading from server failed");
        exit(1);
    }
    printf("%s", buffer);

    snprintf(buffer, 2047, ". list \"\" *\n");
    SSL_write(ssl, buffer, strlen(buffer));

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        result = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (result < 0) {
            perror("Error: reading from server failed");
            exit(1);
        }
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL) break;
    }

    snprintf(buffer, 2047, ". select inbox\n");
    SSL_write(ssl, buffer, strlen(buffer));

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        result = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (result < 0) {
            perror("Error: reading from server failed");
            exit(1);
        }
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL) break;
    }

    snprintf(buffer, 2047, ". fetch 1:* (body[header.fields (subject)])\n");
    SSL_write(ssl, buffer, strlen(buffer));

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        result = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (result < 0) {
            perror("Error: reading from server failed");
            exit(1);
        }
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL) break;
    }

    snprintf(buffer, 2047, ". logout\n");
    SSL_write(ssl, buffer, strlen(buffer));

    SSL_shutdown(ssl);  
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return 0;
}