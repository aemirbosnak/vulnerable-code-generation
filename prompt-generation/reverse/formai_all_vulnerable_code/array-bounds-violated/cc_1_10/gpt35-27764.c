//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 16384

void check(int exp, char *msg) {
    if (exp == -1) {
        perror(msg);
        exit(1);
    }
}

int main(int argc, char **argv) {

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    // create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    check(sockfd, "Failed to open socket");

    // get host by name
    server = gethostbyname("imap.gmail.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // set port to 993 for IMAPS
    portno = 993;

    // zero out server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));

    // set up server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to server
    check(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)), "Failed to connect to server");

    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    SSL *ssl = SSL_new(ctx);

    check(SSL_set_fd(ssl, sockfd), "SSL_set_fd failed");
    check(SSL_connect(ssl), "SSL_connect failed");

    printf("Connected to server.\n");

    //recv response from server 
    n = SSL_read(ssl, buffer, BUFFER_SIZE - 1);
    check(n, "ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send login command
    char *login = "a001 LOGIN email@example.com password\r\n";
    SSL_write(ssl, login, strlen(login));

    //recv response from server 
    n = SSL_read(ssl, buffer, BUFFER_SIZE - 1);
    check(n, "ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send select command
    char *select = "a002 SELECT INBOX\r\n";
    SSL_write(ssl, select, strlen(select));

    //recv response from server 
    n = SSL_read(ssl, buffer, BUFFER_SIZE - 1);
    check(n, "ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send fetch command
    char *fetch = "a003 FETCH 1 BODY[]\r\n";
    SSL_write(ssl, fetch, strlen(fetch));

    //recv response from server 
    n = SSL_read(ssl, buffer, BUFFER_SIZE - 1);
    check(n, "ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send logout command
    char *logout = "a004 LOGOUT\r\n";
    SSL_write(ssl, logout, strlen(logout));

    //recv response from server 
    n = SSL_read(ssl, buffer, BUFFER_SIZE - 1);
    check(n, "ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s\n", buffer);

    SSL_free(ssl);
    close(sockfd);

    return 0;
}