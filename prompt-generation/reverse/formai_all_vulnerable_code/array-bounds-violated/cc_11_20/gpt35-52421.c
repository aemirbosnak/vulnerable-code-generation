//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER_IP "mail.example.com"
#define SERVER_PORT 995
#define BUFFER_SIZE 1024

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket creation failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr) <= 0) {
        perror("invalid server IP address");
        return EXIT_FAILURE;
    }

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connection failed");
        return EXIT_FAILURE;
    }

    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    const SSL_METHOD *ssl_method = SSLv23_client_method();
    SSL_CTX *ssl_ctx = SSL_CTX_new(ssl_method);
    if (ssl_ctx == NULL) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    SSL *ssl = SSL_new(ssl_ctx);
    if (ssl == NULL) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    if (!SSL_set_fd(ssl, sock)) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    if (SSL_connect(ssl) != 1) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    char response[BUFFER_SIZE];
    int bytes_received = SSL_read(ssl, response, sizeof(response) - 1);
    if (bytes_received < 0) {
        perror("reading response failed");
        return EXIT_FAILURE;
    }

    response[bytes_received] = '\0';
    printf("Server response: %s\n", response);

    char user_command[BUFFER_SIZE];
    printf("Enter user name: ");
    fgets(user_command, sizeof(user_command), stdin);
    user_command[strcspn(user_command, "\n")] = '\0';

    char pass_command[BUFFER_SIZE];
    printf("Enter password: ");
    fgets(pass_command, sizeof(pass_command), stdin);
    pass_command[strcspn(pass_command, "\n")] = '\0';

    char user_request[BUFFER_SIZE];
    snprintf(user_request, sizeof(user_request), "USER %s\r\n", user_command);
    if (SSL_write(ssl, user_request, strlen(user_request)) < 0) {
        perror("sending user name failed");
        return EXIT_FAILURE;
    }

    bytes_received = SSL_read(ssl, response, sizeof(response) - 1);
    if (bytes_received < 0) {
        perror("reading response failed");
        return EXIT_FAILURE;
    }

    response[bytes_received] = '\0';
    printf("Server response: %s\n", response);

    char pass_request[BUFFER_SIZE];
    snprintf(pass_request, sizeof(pass_request), "PASS %s\r\n", pass_command);
    if (SSL_write(ssl, pass_request, strlen(pass_request)) < 0) {
        perror("sending password failed");
        return EXIT_FAILURE;
    }

    bytes_received = SSL_read(ssl, response, sizeof(response) - 1);
    if (bytes_received < 0) {
        perror("reading response failed");
        return EXIT_FAILURE;
    }

    response[bytes_received] = '\0';
    printf("Server response: %s\n", response);

    if (SSL_write(ssl, "LIST\r\n", strlen("LIST\r\n")) < 0) {
        perror("sending list command failed");
        return EXIT_FAILURE;
    }

    bytes_received = SSL_read(ssl, response, sizeof(response) - 1);
    if (bytes_received < 0) {
        perror("reading response failed");
        return EXIT_FAILURE;
    }

    response[bytes_received] = '\0';
    printf("Server response:\n%s\n", response);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sock);

    return EXIT_SUCCESS;
}