//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int receive_response(SSL *ssl, char **response) {
    char buffer[BUFFER_SIZE];
    int bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE);
    if (bytes_received <= 0) {
        fprintf(stderr, "Failed to receive response: %d\n", SSL_get_error(ssl, bytes_received));
        return -1;
    }
    *response = (char*)malloc((bytes_received + 1) * sizeof(char));
    memcpy(*response, buffer, bytes_received);
    (*response)[bytes_received] = '\0';
    return 0;
}

int main() {
    // Establishing connection to the server
    char *server_name = "imap.mail.com";
    char *server_port = "993";
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(server_name, server_port, &hints, &res);
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        fprintf(stderr, "Failed to connect to the server.\n");
        return 1;
    }

    // Creating SSL context
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Failed to create SSL context.\n");
        return 1;
    }
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        fprintf(stderr, "Failed to establish SSL connection.\n");
        ERR_print_errors_fp(stderr);
        SSL_CTX_free(ctx);
        return 1;
    }

    // Logging in with user credentials
    char *email = "example@mail.com";
    char *password = "password";
    char *login_command;
    asprintf(&login_command, "LOGIN %s %s\r\n", email, password);
    SSL_write(ssl, login_command, strlen(login_command));
    free(login_command);
    char *response;
    receive_response(ssl, &response);
    printf("Server's response: %s\n", response);
    free(response);

    // Sending a command to the server
    char *command = "LIST \"\" *\r\n";
    SSL_write(ssl, command, strlen(command));
    receive_response(ssl, &response);
    printf("Server's response: %s\n", response);
    free(response);

    // Logging out and closing connection
    char *logout_command = "LOGOUT\r\n";
    SSL_write(ssl, logout_command, strlen(logout_command));
    receive_response(ssl, &response);
    printf("Server's response: %s\n", response);
    free(response);
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    return 0;
}