//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "imap.example.com"
#define PORT 993
#define BUFFER_SIZE 1024

SSL_CTX *create_context() {
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        perror("Unable to create SSL context");
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    // Set the minimum TLS version
    SSL_CTX_set_min_proto_version(ctx, TLS1_2_VERSION);
}

void send_command(SSL *ssl, const char *cmd) {
    SSL_write(ssl, cmd, strlen(cmd));
}

void read_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int read_bytes;
    
    while ((read_bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[read_bytes] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL) {
            break;
        }
    }
}

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sock;
    struct sockaddr_in server_addr;

    // Initialize OpenSSL
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();
    ERR_load_BIO_strings();
    SSL_load_error_strings();

    // Create and configure SSL context
    ctx = create_context();
    configure_context(ctx);

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER); // Replace with the server IP 

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
        perror("Connection to server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Create SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    }

    // Welcome message
    read_response(ssl);

    // Login
    char username[50];
    char password[50];
    printf("Enter your email: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "A01 LOGIN %s %s\r\n", username, password);
    send_command(ssl, cmd);
    read_response(ssl);

    // List mailboxes
    send_command(ssl, "A02 LIST \"\" \"*\"\r\n");
    read_response(ssl);

    // Select INBOX
    send_command(ssl, "A03 SELECT INBOX\r\n");
    read_response(ssl);

    // Fetch email subjects
    send_command(ssl, "A04 FETCH 1:* (ENVELOPE)\r\n");
    read_response(ssl);

    // Logout
    send_command(ssl, "A05 LOGOUT\r\n");
    read_response(ssl);

    // Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    EVP_cleanup();

    return 0;
}