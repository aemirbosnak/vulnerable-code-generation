//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024
#define TRUE 1
#define FALSE 0
#define IMAP_PORT 143

int main()
{
    int sockfd, ret;
    struct sockaddr_in servaddr;
    SSL_CTX *ctx;
    SSL *ssl;
    char buf[BUF_SIZE];
    char username[30], password[30], command[100];
    int len;

    SSL_library_init();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(SSLv23_client_method());

    if (ctx == NULL)
    {
        printf("Error: SSL_CTX_new failed\n");
        exit(1);
    }

    ssl = SSL_new(ctx);

    if (ssl == NULL)
    {
        printf("Error: SSL_new failed\n");
        exit(1);
    }

    SSL_set_fd(ssl, 0);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

    if (SSL_connect(ssl) <= 0)
    {
        printf("Error: SSL_connect failed\n");
        exit(1);
    }

    printf("Connected to IMAP server\n");

    while (1)
    {
        memset(buf, 0, BUF_SIZE);
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "login") == 0)
        {
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            sprintf(buf, "A001 LOGIN %s %s\r\n", username, password);
            SSL_write(ssl, buf, strlen(buf));

            memset(buf, 0, BUF_SIZE);
            SSL_read(ssl, buf, BUF_SIZE);
            printf("Login response: %s", buf);
        }
        else if (strcmp(command, "list") == 0)
        {
            sprintf(buf, "A001 LIST \"\" \"*\"\r\n");
            SSL_write(ssl, buf, strlen(buf));

            memset(buf, 0, BUF_SIZE);
            SSL_read(ssl, buf, BUF_SIZE);
            printf("List response: %s", buf);
        }
        else if (strcmp(command, "quit") == 0)
        {
            sprintf(buf, "A001 LOGOUT\r\n");
            SSL_write(ssl, buf, strlen(buf));

            memset(buf, 0, BUF_SIZE);
            SSL_read(ssl, buf, BUF_SIZE);
            printf("Logout response: %s", buf);

            SSL_shutdown(ssl);
            SSL_free(ssl);
            SSL_CTX_free(ctx);
            close(sockfd);

            exit(0);
        }
        else
        {
            printf("Invalid command\n");
        }
    }

    return 0;
}