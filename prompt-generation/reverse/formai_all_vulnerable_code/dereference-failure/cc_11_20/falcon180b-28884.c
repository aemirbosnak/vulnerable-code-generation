//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <openssl/ssl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    SSL_CTX *ssl_ctx;
    SSL *ssl;
    char *hostname;
    char *port;
    char *username;
    char *password;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int bytes_sent;
    int ssl_status;

    if (argc!= 7) {
        printf("Usage: %s hostname port username password\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    port = argv[2];
    username = argv[3];
    password = argv[4];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    ssl_ctx = SSL_CTX_new(SSLv23_client_method());
    if (ssl_ctx == NULL) {
        printf("Error creating SSL context\n");
        return 1;
    }

    ssl = SSL_new(ssl_ctx);
    if (ssl == NULL) {
        printf("Error creating SSL object\n");
        return 1;
    }

    SSL_set_fd(ssl, sockfd);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

    SSL_connect(ssl);
    ssl_status = SSL_get_verify_result(ssl);
    if (ssl_status!= X509_V_OK) {
        printf("SSL verification failed\n");
        return 1;
    }

    printf("Connected to server\n");

    sprintf(buffer, "USER %s\r\n", username);
    bytes_sent = SSL_write(ssl, buffer, strlen(buffer));
    if (bytes_sent <= 0) {
        printf("Error sending USER command\n");
        return 1;
    }

    bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE);
    if (bytes_received <= 0) {
        printf("Error receiving server response\n");
        return 1;
    }

    printf("Server response: %s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    bytes_sent = SSL_write(ssl, buffer, strlen(buffer));
    if (bytes_sent <= 0) {
        printf("Error sending PASS command\n");
        return 1;
    }

    bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE);
    if (bytes_received <= 0) {
        printf("Error receiving server response\n");
        return 1;
    }

    printf("Server response: %s", buffer);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);

    close(sockfd);

    return 0;
}