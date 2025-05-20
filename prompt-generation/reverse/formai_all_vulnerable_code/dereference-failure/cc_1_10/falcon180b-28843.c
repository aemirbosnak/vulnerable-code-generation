//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define CLIENT_PORT 8081
#define SERVER_CERTIFICATE "server.crt"
#define SERVER_KEY "server.key"

SSL_CTX *ctx;
SSL *ssl;
int sock_client;
int sock_server;

void *handle_client(void *arg);

int main() {
    ctx = SSL_CTX_new(SSLv23_server_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);

    SSL_CTX_set_mode(ctx, SSL_MODE_ENABLE_PARTIAL_WRITE);

    SSL *ssl_server = SSL_new(ctx);
    SSL_set_fd(ssl_server, sock_server);

    SSL_set_accept_state(ssl_server);

    SSL_CTX_free(ctx);

    while (1) {
        sock_client = accept(sock_server, NULL, NULL);
        if (sock_client == -1) {
            perror("accept");
            exit(1);
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)sock_client);
    }

    close(sock_client);
    close(sock_server);

    return 0;
}

void *handle_client(void *arg) {
    int sock = *((int *) arg);

    SSL *ssl_client = SSL_new(ctx);
    SSL_set_fd(ssl_client, sock);

    SSL_set_connect_state(ssl_client);

    if (SSL_connect(ssl_client) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = SSL_read(ssl_client, buffer, BUFFER_SIZE);
        if (bytes_received <= 0) {
            break;
        }
        printf("Received: %s\n", buffer);
    }

    SSL_shutdown(ssl_client);
    SSL_free(ssl_client);

    close(sock);
}