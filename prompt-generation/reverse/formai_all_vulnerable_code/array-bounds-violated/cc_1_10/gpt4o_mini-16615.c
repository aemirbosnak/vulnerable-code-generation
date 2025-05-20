//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define POP3_PORT 995
#define BUFFER_SIZE 1024

void initialize_openssl() {
    SSL_load_error_strings();
    SSL_library_init();
}

SSL_CTX *create_context() {
    const SSL_METHOD *method;
    SSL_CTX *ctx;

    method = SSLv23_client_method();
    ctx = SSL_CTX_new(method);
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}

void clean_context(SSL_CTX *ctx) {
    SSL_CTX_free(ctx);
}

void handle_errors() {
    ERR_print_errors_fp(stderr);
    abort();
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    char password[100];

    printf("Enter password for %s: ", username);
    scanf("%s", password);

    initialize_openssl();
    SSL_CTX *ctx = create_context();

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sockfd);
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    if (SSL_connect(ssl) <= 0) {
        handle_errors();
    }

    char buffer[BUFFER_SIZE];
    int bytes;

    // Receive greeting
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Server: %s", buffer);

    // Send USER command
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive response
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Server: %s", buffer);

    // Send PASS command
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive response
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Server: %s", buffer);

    // Send LIST command
    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    SSL_write(ssl, buffer, strlen(buffer));

    // Receive response
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Server: %s", buffer);

    // End session
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    SSL_write(ssl, buffer, strlen(buffer));

    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    clean_context(ctx);
    return EXIT_SUCCESS;
}