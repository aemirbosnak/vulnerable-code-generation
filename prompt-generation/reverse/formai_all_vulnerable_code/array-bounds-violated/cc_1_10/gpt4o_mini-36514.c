//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "imap.example.com"  // Change to your IMAP Server
#define USER "your_email@example.com"  // Change to your email
#define PASS "your_password"  // Change to your password
#define PORT 993  // Default IMAP SSL port

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

SSL_CTX *initialize_ssl() {
    SSL_CTX *ctx;

    OpenSSL_add_all_algorithms();  /* Load cryptos, et.al. */
    SSL_load_error_strings();       /* Load error strings for libcrypto & libssl */
    const SSL_METHOD *method = SSLv23_client_method(); /* SSLv23 is backward compatible */
    ctx = SSL_CTX_new(method);
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}

SSL *create_ssl_connection(SSL_CTX *ctx, int sock) {
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ssl;
}

void send_imap_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
    SSL_write(ssl, "\r\n", 2);
}

void read_response(SSL *ssl) {
    char buffer[1024];
    int bytes;
    
    while (1) {
        bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (bytes <= 0) break;
        buffer[bytes] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO")) break; 
    }
}

void list_mailboxes(SSL *ssl) {
    send_imap_command(ssl, "A001 LIST \"\" \"*\"");
    read_response(ssl);
}

void check_inbox(SSL *ssl) {
    send_imap_command(ssl, "A002 SELECT INBOX");
    read_response(ssl);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    SSL_CTX *ctx;
    SSL *ssl;

    ctx = initialize_ssl();

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) handle_error("Socket creation failed");
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34");  // IP address for example.com; this should be the server IP

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    ssl = create_ssl_connection(ctx, sock);

    // Login to the IMAP server
    char login_command[512];
    snprintf(login_command, sizeof(login_command), "A0001 LOGIN \"%s\" \"%s\"", USER, PASS);
    send_imap_command(ssl, login_command);
    read_response(ssl);

    // List mailboxes
    list_mailboxes(ssl);

    // Check Inbox
    check_inbox(ssl);

    // Logout
    send_imap_command(ssl, "A0002 LOGOUT");
    read_response(ssl);

    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    EVP_cleanup();  // Clean up the EVP layer

    return 0;
}