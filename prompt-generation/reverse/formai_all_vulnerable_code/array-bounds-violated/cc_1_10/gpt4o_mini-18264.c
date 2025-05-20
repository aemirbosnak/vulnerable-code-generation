//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void init_openssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl() {
    EVP_cleanup();
}

SSL_CTX *create_context() {
    SSL_CTX *ctx;
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        fprintf(stderr, "Could not create SSL context\n");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    // Load the certificate
    if (SSL_CTX_load_verify_locations(ctx, NULL, "/etc/ssl/certs") <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
}

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
}

void read_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;
    while (1) {
        bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (bytes <= 0) {
            break;
        }
        buffer[bytes] = 0;
        printf("%s", buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <email> <password> <imap_server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *email = argv[1];
    const char *password = argv[2];
    const char *imap_server = argv[3];

    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    
    host = gethostbyname(imap_server);
    if (host == NULL) {
        die("Unable to resolve host");
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        die("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection failed");
    }

    init_openssl();
    SSL_CTX *ctx = create_context();
    configure_context(ctx);
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);

    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        close(sock);
        SSL_CTX_free(ctx);
        cleanup_openssl();
        exit(EXIT_FAILURE);
    }

    read_response(ssl);

    char command[BUFFER_SIZE];
    sprintf(command, "A001 LOGIN \"%s\" \"%s\"\r\n", email, password);
    send_command(ssl, command);
    read_response(ssl);

    // Fetch list of mailboxes
    send_command(ssl, "A002 LIST \"\" \"*\"\r\n");
    read_response(ssl);

    // Logout command 
    send_command(ssl, "A003 LOGOUT\r\n");
    read_response(ssl);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    cleanup_openssl();

    return 0;
}