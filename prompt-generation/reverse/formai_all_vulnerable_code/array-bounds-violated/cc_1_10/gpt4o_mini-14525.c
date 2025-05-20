//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "imap.example.com"
#define PORT 993
#define BUFSIZE 4096

void handle_SSL_error() {
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
}

void send_command(SSL *ssl, const char *cmd) {
    SSL_write(ssl, cmd, strlen(cmd));
}

void read_response(SSL *ssl) {
    char buffer[BUFSIZE];
    int bytes;

    memset(buffer, 0, sizeof(buffer));
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (bytes > 0) {
        buffer[bytes] = '\0';
        printf("%s\n", buffer);
    } else {
        fprintf(stderr, "Error reading from server\n");
    }
}

void list_mailboxes(SSL *ssl) {
    send_command(ssl, "A001 LIST \"\" \"*\"\r\n");
    read_response(ssl);
}

void fetch_email_subjects(SSL *ssl, const char *mailbox) {
    char cmd[BUFSIZE];
    snprintf(cmd, sizeof(cmd), "A002 SELECT \"%s\"\r\n", mailbox);
    send_command(ssl, cmd);
    read_response(ssl);
    
    send_command(ssl, "A003 FETCH 1:* (ENVELOPE)\r\n");
    read_response(ssl);
}

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd;
    struct sockaddr_in server_addr;

    // Initialize OpenSSL
    SSL_library_init();
    OpenSSL_add_ssl_algorithms();
    SSL_load_error_strings();

    // Create SSL context
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        handle_SSL_error();
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Cannot create socket");
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Create SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    
    if (SSL_connect(ssl) <= 0) {
        handle_SSL_error();
    }

    printf("Connected to IMAP server\n");
    
    // List mailboxes
    list_mailboxes(ssl);

    // Fetch email subjects from a specific mailbox
    fetch_email_subjects(ssl, "INBOX");
    
    // Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    EVP_cleanup();

    return EXIT_SUCCESS;
}