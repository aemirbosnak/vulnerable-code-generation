//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    int port = 443; // HTTPS default port

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // resolve hostname to IP address
    struct addrinfo hints = {0};
    hints.ai_family = AF_INET;  // IPv4
    hints.ai_socktype = SOCK_STREAM;  // TCP
    hints.ai_flags = AI_NUMERICSERV;  // use numeric port number
    struct addrinfo *result;
    int status = getaddrinfo(hostname, "https", &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo() failed: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    // connect to server
    struct sockaddr_in *server_addr = (struct sockaddr_in *)result->ai_addr;
    server_addr->sin_port = htons(port);  // convert to network byte order
    status = connect(sockfd, (struct sockaddr *)server_addr, sizeof(*server_addr));
    if (status < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // create SSL context
    SSL_CTX *ssl_ctx = SSL_CTX_new(TLS_client_method());
    if (ssl_ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // set trusted CA file
    status = SSL_CTX_load_verify_locations(ssl_ctx, "/etc/ssl/certs/ca-certificates.crt", NULL);
    if (status != 1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // create SSL connection
    SSL *ssl = SSL_new(ssl_ctx);
    if (ssl == NULL) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    status = SSL_set_fd(ssl, sockfd);
    if (status != 1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    status = SSL_connect(ssl);
    if (status != 1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // send HTTP request
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);
    printf("Sending HTTP request:\n%s", buffer);
    status = SSL_write(ssl, buffer, strlen(buffer));
    if (status < 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // receive HTTP response
    memset(buffer, 0, sizeof(buffer));
    status = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (status < 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    printf("Received HTTP response:\n%s", buffer);

    // cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sockfd);
    freeaddrinfo(result);

    return 0;
}