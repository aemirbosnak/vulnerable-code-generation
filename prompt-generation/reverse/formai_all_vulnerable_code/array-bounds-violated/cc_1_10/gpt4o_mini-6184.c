//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_SERVER "imap.example.com"
#define IMAP_PORT 993

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void init_openssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl() {
    EVP_cleanup();
}

SSL_CTX *create_context() {
    SSL_CTX *ctx;

    ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        handle_error("Unable to create SSL context");
    }
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    // Load the trusted root certificates.
    if (SSL_CTX_load_verify_locations(ctx, "path/to/cacert.pem", NULL) <= 0) {
        handle_error("Failed to load CA certificates");
    }
}

void imap_connect(SSL *ssl) {
    // Send IMAP LOGIN command
    SSL_write(ssl, "a1 LOGIN your_email@example.com your_password\r\n", strlen("a1 LOGIN your_email@example.com your_password\r\n"));
    
    char buffer[1024];
    int bytes = SSL_read(ssl, buffer, sizeof(buffer));
    buffer[bytes] = 0;
    printf("Response: %s", buffer);

    // Send IMAP SELECT command
    SSL_write(ssl, "a2 SELECT INBOX\r\n", strlen("a2 SELECT INBOX\r\n"));
    bytes = SSL_read(ssl, buffer, sizeof(buffer));
    buffer[bytes] = 0;
    printf("Response: %s", buffer);

    // You can add further IMAP commands to explore, e.g., FETCH, SEARCH, etc.
}

int main(int argc, char **argv) {
    init_openssl();
    SSL_CTX *ctx = create_context();
    configure_context(ctx);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Unable to create socket");
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(IMAP_PORT);
    inet_pton(AF_INET, IMAP_SERVER, &addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
        handle_error("Unable to connect to IMAP server");
    }

    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);

    if (SSL_connect(ssl) <= 0) {
        handle_error("SSL connection failed");
    }

    printf("Connected to IMAP server over SSL\n");

    imap_connect(ssl);

    // Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    cleanup_openssl();

    return 0;
}