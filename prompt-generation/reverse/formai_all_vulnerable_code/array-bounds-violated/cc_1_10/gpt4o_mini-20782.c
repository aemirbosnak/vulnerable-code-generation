//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER_PORT 993
#define BUFFER_SIZE 1024

void init_openssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl() {
    EVP_cleanup();
}

SSL_CTX *create_context() {
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        perror("Unable to create SSL context");
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void connect_ssl(SSL *ssl, int sock) {
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    }
}

void send_imap_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
}

void read_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;
    while ((bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "A001 OK")) {  // Check if the command is done
            break;
        }
    }
}

void authenticate(SSL *ssl, const char *username, const char *password) {
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "A001 LOGIN %s %s\r\n", username, password);
    send_imap_command(ssl, cmd);
    read_response(ssl);
}

void list_mailboxes(SSL *ssl) {
    send_imap_command(ssl, "A002 LIST \"\" \"*\"\r\n");
    read_response(ssl);
}

void fetch_email_subjects(SSL *ssl, const char *mailbox) {
    char cmd[BUFFER_SIZE];
    snprintf(cmd, sizeof(cmd), "A003 SELECT \"%s\"\r\n", mailbox);
    send_imap_command(ssl, cmd);
    read_response(ssl);
    
    // Fetch the subjects
    send_imap_command(ssl, "A004 FETCH 1:* (ENVELOPE)\r\n");
    read_response(ssl);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <imap_server> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock;
    struct sockaddr_in server_addr;

    init_openssl();
    SSL_CTX *ctx = create_context();
    SSL *ssl = SSL_new(ctx);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return EXIT_FAILURE;
    }

    // Establish SSL connection
    connect_ssl(ssl, sock);
    
    // Authenticate user
    authenticate(ssl, username, password);

    // List mailboxes
    list_mailboxes(ssl);

    // Fetch emails from inbox
    fetch_email_subjects(ssl, "INBOX");

    // Clean up
    SSL_shutdown(ssl);
    close(sock);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    cleanup_openssl();

    return EXIT_SUCCESS;
}