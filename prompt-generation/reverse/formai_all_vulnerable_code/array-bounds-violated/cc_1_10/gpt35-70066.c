//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "imap.gmail.com"
#define PORT 993

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd, bytes_received;
    char recv_buf[1024], send_buf[1024];

    //initialize SSL library
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    //create SSL_CTX object
    ctx = SSL_CTX_new(SSLv23_client_method());

    //verify that SSL_CTX object was successfully created
    if(!ctx)
        fprintf(stderr, "SSL_CTX_new() error\n");

    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //set up server address struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER);
    server_addr.sin_port = htons(PORT);

    //connect to server
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        SSL_CTX_free(ctx);
        printf("Unable to connect to server\n");
        return 1;
    }

    //create SSL object
    ssl = SSL_new(ctx);

    //connect SSL object to the socket
    SSL_set_fd(ssl, sockfd);

    //perform SSL handshake
    if(SSL_connect(ssl) == -1) {
        close(sockfd);
        SSL_CTX_free(ctx);
        printf("SSL_connect() error\n");
        return 1;
    }

    //receive greeting from server
    bytes_received = SSL_read(ssl, recv_buf, sizeof(recv_buf)-1);
    recv_buf[bytes_received] = '\0';
    printf("Server greeting: %s\n", recv_buf);

    //send login command to server
    sprintf(send_buf, "1 LOGIN user@gmail.com password\n");
    SSL_write(ssl, send_buf, strlen(send_buf));

    //receive command response from server
    bytes_received = SSL_read(ssl, recv_buf, sizeof(recv_buf)-1);
    recv_buf[bytes_received] = '\0';
    printf("Command response: %s\n", recv_buf);

    //send select command to server
    sprintf(send_buf, "2 SELECT INBOX\n");
    SSL_write(ssl, send_buf, strlen(send_buf));

    //receive command response from server
    bytes_received = SSL_read(ssl, recv_buf, sizeof(recv_buf)-1);
    recv_buf[bytes_received] = '\0';
    printf("Command response: %s\n", recv_buf);

    //send fetch command to server
    sprintf(send_buf, "3 FETCH 1 BODY[HEADER]\n");
    SSL_write(ssl, send_buf, strlen(send_buf));

    //receive command response from server
    bytes_received = SSL_read(ssl, recv_buf, sizeof(recv_buf)-1);
    recv_buf[bytes_received] = '\0';
    printf("Command response: %s\n", recv_buf);

    //cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);

    return 0;
}