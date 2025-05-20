//FormAI DATASET v1.0 Category: Socket programming ; Style: futuristic
// This is a futuristic example program that uses C Socket programming to 
// establish a secure and encrypted connection between two parties over a
// virtual private network.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 12345     // the port to connect
#define BUF_SIZE 2048  // the maximum buffer size

int main(int argc, char *argv[]) {

    SSL_CTX *ctx;
    SSL *ssl; 

    // initializing OpenSSL library
    SSL_library_init();
    ctx = SSL_CTX_new(TLS_client_method());

    // loading CA certificate to verify server validity
    if (!SSL_CTX_load_verify_locations(ctx, "ca-cert.pem", NULL)) {
        fprintf(stderr, "Error: can't load CA certificate!\n");
        exit(1);
    }

    // setting up socket connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: can't create socket!\n");
        exit(1);
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    // connecting to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: can't connect to server!\n");
        exit(1);
    }

    // initiating SSL connection on top of socket connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        fprintf(stderr, "Error: can't establish SSL connection!\n");
        ERR_print_errors_fp(stderr);
        exit(1);
    }
    printf("SSL connection established!\n");
    
    // sending data to server
    char *data = "Hello, server!";
    SSL_write(ssl, data, strlen(data));
    printf("Data sent to server: %s\n", data);

    // receiving data from server
    char buf[BUF_SIZE];
    int len = SSL_read(ssl, buf, sizeof(buf)-1);
    buf[len] = '\0';
    printf("Data received from server: %s\n", buf);

    // closing SSL connection and freeing memory
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);

    return 0;
}