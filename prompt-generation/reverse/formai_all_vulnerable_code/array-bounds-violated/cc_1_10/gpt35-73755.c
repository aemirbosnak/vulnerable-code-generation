//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>

#define MAX_BUFFER_SIZE 1024

int open_connection(const char *hostname, const char *port) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(hostname, port, &hints, &servinfo);

    for (p = servinfo; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }
        break;
    }

    freeaddrinfo(servinfo);

    if (p == NULL) {
        perror("Unable to open connection");
        exit(1);
    }

    return sockfd;
}

SSL_CTX* init_ssl_ctx() {
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        perror("Unable to create SSL context");
        exit(1);
    }
    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);

    return ctx;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <hostname> <port> <username>\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    const char *port = argv[2];
    const char *username = argv[3];

    SSL_load_error_strings();
    SSL_library_init();

    int sockfd = open_connection(hostname, port);
    SSL_CTX *ctx = init_ssl_ctx();
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    SSL_connect(ssl);

    char buffer[MAX_BUFFER_SIZE];
    int num_bytes;

    // Send the LOGIN command
    sprintf(buffer, "LOGIN %s PASSWORD\n", username);
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive the response from the server
    num_bytes = SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    buffer[num_bytes] = '\0';
    printf("Server response: %s", buffer);

    // Send the SELECT command
    sprintf(buffer, "SELECT INBOX\n");
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive the response from the server
    num_bytes = SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    buffer[num_bytes] = '\0';
    printf("Server response: %s", buffer);

    // Send the FETCH command
    sprintf(buffer, "FETCH 1 BODY[TEXT]\n");
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive the response from the server
    num_bytes = SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    buffer[num_bytes] = '\0';
    printf("Server response: %s", buffer);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}