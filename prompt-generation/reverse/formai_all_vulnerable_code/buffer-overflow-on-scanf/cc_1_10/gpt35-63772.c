//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024
#define HOST "imap.gmail.com"
#define PORT 993

void error(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}

void receive(SSL *ssl_conn){
    int len = 0;
    char buffer[BUFFER_SIZE] = {0};

    len = SSL_read(ssl_conn, buffer, BUFFER_SIZE - 1);
    if(len > 0){
        buffer[len] = 0;
        printf("%s", buffer);
        receive(ssl_conn);
    }
}

int main(){
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLS_method());
    if(!ctx) error("SSL_CTX_new");

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1) error("socket");

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(HOST);

    if(connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) error("connect");

    SSL *ssl_conn = SSL_new(ctx);
    if(!ssl_conn) error("SSL_new");

    if(SSL_set_fd(ssl_conn, sock_fd) == 0) error("SSL_set_fd");

    if(SSL_connect(ssl_conn) != 1) error("SSL_connect");

    char username[BUFFER_SIZE], password[BUFFER_SIZE], buffer[BUFFER_SIZE];
    printf("Username (without @gmail.com): ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    sprintf(buffer, "a001 LOGIN %s@gmail.com %s\r\n", username, password);
    SSL_write(ssl_conn, buffer, strlen(buffer));
    receive(ssl_conn);

    sprintf(buffer, "a002 LIST \"\" *\r\n");
    SSL_write(ssl_conn, buffer, strlen(buffer));
    receive(ssl_conn);

    sprintf(buffer, "a003 SELECT INBOX\r\n");
    SSL_write(ssl_conn, buffer, strlen(buffer));
    receive(ssl_conn);

    sprintf(buffer, "a004 FETCH 1 BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)]\r\n");
    SSL_write(ssl_conn, buffer, strlen(buffer));
    receive(ssl_conn);

    SSL_shutdown(ssl_conn);
    SSL_free(ssl_conn);
    close(sock_fd);
    SSL_CTX_free(ctx);
    return 0;
}