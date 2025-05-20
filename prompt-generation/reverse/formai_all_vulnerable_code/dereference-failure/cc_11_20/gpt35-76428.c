//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define READ_BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    SSL_library_init();
    SSL_CTX *ssl_ctx = SSL_CTX_new(TLS_client_method());
    if (ssl_ctx == NULL) {
        printf("Failed to create SSL context.\n");
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket.\n");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect to server.\n");
        return EXIT_FAILURE;
    }

    SSL* ssl = SSL_new(ssl_ctx);
    if (ssl == NULL) {
        printf("Failed to create SSL object.\n");
        return EXIT_FAILURE;
    }

    if (!SSL_set_fd(ssl, sockfd)) {
        printf("Failed to set SSL file descriptor.\n");
        return EXIT_FAILURE;
    }

    if (SSL_connect(ssl) != 1) {
        printf("Failed to establish SSL connection with server.\n");
        return EXIT_FAILURE;
    }

    char username[100];
    sprintf(username, "%s", argv[3]);

    char command_buffer[READ_BUFFER_SIZE];
    char reply_buffer[READ_BUFFER_SIZE];
    int reply_bytes;

    sprintf(command_buffer, "LOGIN %s password\r\n", username, username);

    if (SSL_write(ssl, command_buffer, strlen(command_buffer)) < strlen(command_buffer)) {
        printf("Failed to send LOGIN command to server.\n");
        return EXIT_FAILURE;
    }

    reply_bytes = SSL_read(ssl, reply_buffer, READ_BUFFER_SIZE);
    printf("%.*s", reply_bytes, reply_buffer);

    sprintf(command_buffer, "SELECT INBOX\r\n");

    if (SSL_write(ssl, command_buffer, strlen(command_buffer)) < strlen(command_buffer)) {
        printf("Failed to send SELECT command to server.\n");
        return EXIT_FAILURE;
    }

    reply_bytes = SSL_read(ssl, reply_buffer, READ_BUFFER_SIZE);
    printf("%.*s", reply_bytes, reply_buffer);

    sprintf(command_buffer, "FETCH 1 BODY[TEXT]\r\n");

    if (SSL_write(ssl, command_buffer, strlen(command_buffer)) < strlen(command_buffer)) {
        printf("Failed to send FETCH command to server.\n");
        return EXIT_FAILURE;
    }

    reply_bytes = SSL_read(ssl, reply_buffer, READ_BUFFER_SIZE);
    printf("%.*s", reply_bytes, reply_buffer);

    sprintf(command_buffer, "LOGOUT\r\n");

    if (SSL_write(ssl, command_buffer, strlen(command_buffer)) < strlen(command_buffer)) {
        printf("Failed to send LOGOUT command to server.\n");
        return EXIT_FAILURE;
    }

    reply_bytes = SSL_read(ssl, reply_buffer, READ_BUFFER_SIZE);
    printf("%.*s", reply_bytes, reply_buffer);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);

    SSL_CTX_free(ssl_ctx);

    return EXIT_SUCCESS;
}