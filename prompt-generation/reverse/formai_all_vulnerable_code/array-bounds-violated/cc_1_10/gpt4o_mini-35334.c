//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

void init_openssl() {
    SSL_load_error_strings();   
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl() {
    EVP_cleanup();
}

SSL_CTX *create_context() {
    const SSL_METHOD *method;
    SSL_CTX *ctx;

    method = SSLv23_client_method(); 
    ctx = SSL_CTX_new(method);
    if (!ctx) {
        perror("Unable to create SSL context");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    /* Set minimum client version to TLS 1.2 */
    SSL_CTX_set_min_proto_version(ctx, TLS1_2_VERSION);
    /* Load certificates for verification */
    if (SSL_CTX_load_verify_locations(ctx, "ca-certificates.crt", NULL) <= 0) {
        perror("Failed to load CA certificates");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
}

void handle_connection(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;

    // Use SSL_read and SSL_write instead of normal sockets
    while (1) {
        printf("> ");
        fflush(stdout);
        fgets(buffer, BUFFER_SIZE, stdin);  // Get user input

        if (strcmp(buffer, "quit\n") == 0) {
            break;
        }

        SSL_write(ssl, buffer, strlen(buffer));  // Send command to server

        // Read server response
        bytes = SSL_read(ssl, buffer, sizeof(buffer));
        buffer[bytes] = 0;  // Null-terminate string
        printf("Server: %s", buffer);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    int port = atoi(argv[2]);

    init_openssl();
    SSL_CTX *ctx = create_context();
    configure_context(ctx);

    SSL *ssl;
    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Create SSL object
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);

    // Establish secure connection
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d using SSL\n", server_ip, port);
    handle_connection(ssl);

    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    cleanup_openssl();

    return 0;
}