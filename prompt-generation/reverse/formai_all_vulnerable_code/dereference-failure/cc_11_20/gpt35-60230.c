//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    // check if the command line arguments are correct
    if (argc < 3 || argc > 4) {
        printf("Usage: %s server port [ssl]\n", argv[0]);
        return 1;
    }

    // create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // get the address of the server
    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // create a struct sockaddr_in with the server address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *((struct in_addr *) he->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    // connect to the server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        return 1;
    }

    // if SSL is enabled, create an SSL context and wrap the socket
    SSL_CTX *ctx = NULL;
    SSL *ssl = NULL;
    if (argc == 4 && strncmp(argv[3], "ssl", 3) == 0) {
        SSL_library_init();
        ctx = SSL_CTX_new(SSLv23_client_method());
        if (ctx == NULL) {
            perror("SSL_CTX_new");
            return 1;
        }
        ssl = SSL_new(ctx);
        SSL_set_fd(ssl, sock);
        if (SSL_connect(ssl) == -1) {
            perror("SSL_connect");
            return 1;
        }
    }

    // receive the welcome message from the server
    char buf[BUF_SIZE];
    int numbytes;
    if (ssl != NULL) {
        numbytes = SSL_read(ssl, buf, BUF_SIZE);
    } else {
        numbytes = recv(sock, buf, BUF_SIZE, 0);
    }
    if (numbytes == -1) {
        perror("recv");
        return 1;
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    // log in to the mail server
    if (ssl != NULL) {
        SSL_write(ssl, "A001 LOGIN username password\r\n", strlen("A001 LOGIN username password\r\n"));
        numbytes = SSL_read(ssl, buf, BUF_SIZE);
    } else {
        send(sock, "A001 LOGIN username password\r\n", strlen("A001 LOGIN username password\r\n"), 0);
        numbytes = recv(sock, buf, BUF_SIZE, 0);
    }
    if (numbytes == -1) {
        perror("recv/send");
        return 1;
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    // select the mailbox to fetch messages from
    if (ssl != NULL) {
        SSL_write(ssl, "A002 SELECT inbox\r\n", strlen("A002 SELECT inbox\r\n"));
        numbytes = SSL_read(ssl, buf, BUF_SIZE);
    } else {
        send(sock, "A002 SELECT inbox\r\n", strlen("A002 SELECT inbox\r\n"), 0);
        numbytes = recv(sock, buf, BUF_SIZE, 0);
    }
    if (numbytes == -1) {
        perror("recv/send");
        return 1;
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    // fetch the list of messages in the mailbox
    if (ssl != NULL) {
        SSL_write(ssl, "A003 FETCH 1:* (BODY[HEADER])\r\n", strlen("A003 FETCH 1:* (BODY[HEADER])\r\n"));
        numbytes = SSL_read(ssl, buf, BUF_SIZE);
    } else {
        send(sock, "A003 FETCH 1:* (BODY[HEADER])\r\n", strlen("A003 FETCH 1:* (BODY[HEADER])\r\n"), 0);
        numbytes = recv(sock, buf, BUF_SIZE, 0);
    }
    if (numbytes == -1) {
        perror("recv/send");
        return 1;
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    // log out and close the connection
    if (ssl != NULL) {
        SSL_write(ssl, "A004 LOGOUT\r\n", strlen("A004 LOGOUT\r\n"));
        numbytes = SSL_read(ssl, buf, BUF_SIZE);
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
    } else {
        send(sock, "A004 LOGOUT\r\n", strlen("A004 LOGOUT\r\n"), 0);
        numbytes = recv(sock, buf, BUF_SIZE, 0);
    }
    if (numbytes == -1) {
        perror("recv/send");
        return 1;
    }
    buf[numbytes] = '\0';
    printf("%s", buf);

    close(sock);

    return 0;
}