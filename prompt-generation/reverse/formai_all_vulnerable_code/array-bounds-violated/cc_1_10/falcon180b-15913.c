//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_DATA_LENGTH 2048

#define SERVER_PORT 443
#define SERVER_IP "localhost"

#define SSL_CTX_FILE "server.crt"
#define SSL_KEY_FILE "server.key"

int main(int argc, char *argv[]) {
    SSL_CTX *ssl_ctx;
    SSL *ssl;
    int ssl_fd;
    int sock;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_LENGTH];
    int bytes_received;
    int bytes_sent;

    ssl_ctx = SSL_CTX_new(SSLv23_client_method());
    if (ssl_ctx == NULL) {
        printf("Error creating SSL context\n");
        exit(1);
    }

    SSL_CTX_set_default_verify_paths(ssl_ctx);
    SSL_CTX_load_verify_locations(ssl_ctx, SSL_CTX_FILE, NULL);

    ssl = SSL_new(ssl_ctx);
    if (ssl == NULL) {
        printf("Error creating SSL\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    SSL_set_fd(ssl, sock);
    SSL_connect(ssl);

    while (1) {
        bytes_received = SSL_read(ssl, data, MAX_DATA_LENGTH);
        if (bytes_received <= 0) {
            printf("Error reading data\n");
            break;
        }

        data[bytes_received] = '\0';
        printf("Received: %s\n", data);
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);

    close(sock);

    return 0;
}