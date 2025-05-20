//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main(int argc, char *argv[])
{
    SSL_CTX *ctx;
    SSL *ssl;
    BIO *bio;
    int sockfd;
    struct sockaddr_in server_addr;
    char *host, *port;
    int port_num;
    char buf[1024];
    int len;
    
    if (argc!= 4) {
        printf("Usage: %s <host> <port> <username>\n", argv[0]);
        return 1;
    }
    
    host = argv[1];
    port = argv[2];
    port_num = atoi(port);
    buf[0] = '\0';
    
    SSL_library_init();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(SSLv23_client_method());
    
    if (ctx == NULL) {
        printf("Error creating SSL context\n");
        return 1;
    }
    
    ssl = SSL_new(ctx);
    
    if (ssl == NULL) {
        printf("Error creating SSL object\n");
        return 1;
    }
    
    SSL_set_fd(ssl, 0);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);
    
    if (SSL_connect(ssl) <= 0) {
        printf("Error connecting to server\n");
        return 1;
    }
    
    bio = BIO_new_socket(sockfd, BIO_NOCLOSE);
    SSL_set_bio(ssl, bio, bio);
    
    snprintf(buf, sizeof(buf), "LOGIN %s\r\n", argv[3]);
    SSL_write(ssl, buf, strlen(buf));
    
    while ((len = SSL_read(ssl, buf, sizeof(buf))) > 0) {
        buf[len] = '\0';
        printf("%s", buf);
    }
    
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    
    return 0;
}