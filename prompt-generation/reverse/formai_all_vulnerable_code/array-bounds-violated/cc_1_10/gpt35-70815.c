//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024
#define CRLF "\r\n"
#define HOST "mail.example.com"
#define USER "username"
#define PASS "password"
#define MAILBOX "Inbox"

void ssl_init(void) {
    SSL_load_error_strings();
    SSL_library_init();
}

SSL* ssl_connect(int sockfd) {
    SSL_CTX *ctx;
    SSL *ssl;

    ssl_init();

    ctx = SSL_CTX_new(SSLv23_method());
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    if (SSL_connect(ssl) == -1) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    return ssl;
}

void ssl_disconnect(SSL* ssl, int sockfd) {
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    int sockfd, port = 993, num_bytes;
    char buf[BUF_SIZE], reply[BUF_SIZE];
    char *host = HOST, *user = USER, *pass = PASS, *mailbox = MAILBOX;
    struct hostent *server;
    struct sockaddr_in servaddr;
    SSL *ssl;

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        return 1;
    }

    server = gethostbyname(host);
    if (server == NULL) {
        printf("ERROR, no such host\n");
        return 1;
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(port);

    if (connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) < 0) {
        printf("ERROR connecting\n");
        return 1;
    }

    ssl = ssl_connect(sockfd);

    num_bytes = recv(sockfd, reply, sizeof(reply), 0);
    if (num_bytes < 0) {
        printf("ERROR reading from socket\n");
        return 1;
    }
    reply[num_bytes] = '\0';

    printf("Server response: %s\n", reply);

    sprintf(buf, "1 LOGIN %s %s" CRLF, user, pass);
    SSL_write(ssl, buf, strlen(buf));

    num_bytes = SSL_read(ssl, reply, sizeof(reply));
    if (num_bytes < 0) {
        printf("ERROR reading from socket\n");
        return 1;
    }
    reply[num_bytes] = '\0';

    printf("Server response: %s\n", reply);

    sprintf(buf, "2 SELECT %s" CRLF, mailbox);
    SSL_write(ssl, buf, strlen(buf));

    num_bytes = SSL_read(ssl, reply, sizeof(reply));
    if (num_bytes < 0) {
        printf("ERROR reading from socket\n");
        return 1;
    }
    reply[num_bytes] = '\0';

    // Paranoid check
    if (strstr(reply, "UIDVALIDITY") == NULL || 
        strstr(reply, "PERMANENTFLAGS") == NULL || 
        strstr(reply, "EXISTS") == NULL || 
        strstr(reply, "RECENT") == NULL) {
        printf("ERROR: invalid mailbox\n");
        return 1;
    }

    printf("Server response: %s\n", reply);

    sprintf(buf, "3 LOGOUT" CRLF);
    SSL_write(ssl, buf, strlen(buf));

    num_bytes = SSL_read(ssl, reply, sizeof(reply));
    if (num_bytes < 0) {
        printf("ERROR reading from socket\n");
        return 1;
    }
    reply[num_bytes] = '\0';

    printf("Server response: %s\n", reply);

    ssl_disconnect(ssl, sockfd);

    return 0;
}