//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 4096

void cleanup(SSL *ssl, int sockfd){
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    exit(1);
}

void print_error(char *error){
    fprintf(stderr, "%s\n", error);
    exit(1);
}

int main(int argc, char *argv[]){

    /* --- Check input parameters --- */
    if(argc != 4){
        printf("Usage: %s [server address] [user] [password]\n", argv[0]);
        return 1;
    }

    /* --- Create socket --- */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        print_error("Could not create socket");
    }

    /* --- Set up server address --- */
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(993);
    if(inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0){
        print_error("Invalid server address");
    }

    /* --- Connect to server --- */
    if(connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0){
        print_error("Could not connect to server");
    }

    /* --- Initialize SSL context --- */
    SSL_library_init();
    SSL_CTX *ssl_ctx = SSL_CTX_new(TLSv1_2_client_method());
    if(ssl_ctx == NULL){
        print_error("Could not initialize SSL context");
    }

    /* --- Allow only strong ciphers --- */
    SSL_CTX_set_cipher_list(ssl_ctx, "HIGH:!aNULL:!MD5");

    /* --- Set up SSL connection --- */
    SSL *ssl = SSL_new(ssl_ctx);
    if(ssl == NULL){
        print_error("Could not create SSL connection");
    }
    SSL_set_fd(ssl, sockfd);
    if(SSL_connect(ssl) < 0){
        cleanup(ssl, sockfd);
        print_error("Could not establish SSL connection");
    }

    /* --- Login --- */
    char buf[BUF_SIZE];
    sprintf(buf, ". login %s %s\n", argv[2], argv[3]);
    SSL_write(ssl, buf, strlen(buf));

    /* --- Check response --- */
    int bytes_read = SSL_read(ssl, buf, BUF_SIZE-1);
    buf[bytes_read] = '\0';
    if(strncmp(buf, ". OK", 4) != 0){
        cleanup(ssl, sockfd);
        print_error("Could not log in");
    }

    /* --- Select mailbox --- */
    sprintf(buf, ". select inbox\n");
    SSL_write(ssl, buf, strlen(buf));

    /* --- Check response --- */
    bytes_read = SSL_read(ssl, buf, BUF_SIZE-1);
    buf[bytes_read] = '\0';
    if(strncmp(buf, ". OK", 4) != 0){
        cleanup(ssl, sockfd);
        print_error("Could not select mailbox");
    }

    /* --- List messages --- */
    sprintf(buf, ". fetch 1:* (flags envelope)\n");
    SSL_write(ssl, buf, strlen(buf));

    /* --- Show response --- */
    while((bytes_read = SSL_read(ssl, buf, BUF_SIZE-1)) > 0){
        buf[bytes_read] = '\0';
        printf("%s", buf);
    }

    /* --- Cleanup --- */
    cleanup(ssl, sockfd);
    return 0;
}