//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: surprised
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<openssl/ssl.h>
#include<openssl/err.h>

#define SERVER "imap.gmail.com"
#define MAXSIZE 1024

int main(int argc, char* argv[]) {
    int sock;
    struct sockaddr_in server;
    char server_reply[MAXSIZE];
    SSL_CTX *ctx;
    SSL *ssl;

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    server.sin_addr.s_addr = inet_addr("172.217.166.109");
    server.sin_family = AF_INET;
    server.sin_port = htons(993);

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection error");
        exit(EXIT_FAILURE);
    }

    if(SSL_library_init() < 0) {
        perror("INITIALIZATION ERROR");
        exit(EXIT_FAILURE);
    }

    ctx = SSL_CTX_new(TLSv1_2_method());

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);

    if(SSL_connect(ssl) < 0) {
        perror("SSL Connection error");
        ERR_print_errors_fp(stderr);
    } else {
        printf("SSL Connected\n");
    }

    memset(server_reply, '\0', sizeof(server_reply));
    SSL_read(ssl, server_reply, MAXSIZE);

    printf("%s\n", server_reply);

    memset(server_reply, '\0', sizeof(server_reply));

    char user_input[MAXSIZE];
    printf("\nEnter username: ");
    scanf("%s", user_input);

    char login_command[MAXSIZE];
    snprintf(login_command, MAXSIZE, "a001 login %s\n", user_input);

    SSL_write(ssl, login_command, strlen(login_command));
    SSL_read(ssl, server_reply, MAXSIZE);

    printf("%s\n", server_reply);

    while(strcmp(server_reply, "* BYE Logging out\r\n") != 0) {
        memset(server_reply, '\0', sizeof(server_reply));
        printf("\nEnter a command: ");
        scanf("%s", user_input);
        SSL_write(ssl, user_input, strlen(user_input));
        SSL_read(ssl, server_reply, MAXSIZE);
        printf("%s\n", server_reply);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);

    return 0;
}