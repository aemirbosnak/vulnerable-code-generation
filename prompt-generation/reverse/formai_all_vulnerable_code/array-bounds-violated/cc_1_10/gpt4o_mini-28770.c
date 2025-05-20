//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 993 // IMAP over SSL port
#define BUF_SIZE 1024
#define USERNAME "your_email@example.com"
#define PASSWORD "your_password"

void initialize_openssl();
void cleanup_openssl();
SSL_CTX *create_context();
void configure_context(SSL_CTX *ctx);
void handle_error(const char *msg);

int main() {
    // Initialize SSL library
    initialize_openssl();
    
    // Create a new SSL context
    SSL_CTX *ctx = create_context();
    configure_context(ctx);
    
    // Set up a connection to the IMAP server
    int sock = 0;
    struct sockaddr_in server_addr;
    struct hostent *host;

    if ((host = gethostbyname("imap.example.com")) == NULL) {
        handle_error("gethostbyname failed");
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
        handle_error("Connection to IMAP server failed");
    }
    
    // Establish SSL connection
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    
    if (SSL_connect(ssl) <= 0) {
        handle_error("SSL connect failed");
    }

    // Send LOGIN command to the server
    char command[BUF_SIZE];
    snprintf(command, sizeof(command), "a001 LOGIN %s %s\r\n", USERNAME, PASSWORD);
    SSL_write(ssl, command, strlen(command));

    // Now we are reading server responses
    char response[BUF_SIZE];
    int bytes = SSL_read(ssl, response, sizeof(response) - 1);
    if (bytes < 0) {
        handle_error("SSL read failed");
    }
    response[bytes] = '\0'; // Null-terminate the response
    printf("Server response: %s\n", response);
    
    // Send SELECT to select inbox
    snprintf(command, sizeof(command), "a002 SELECT INBOX\r\n");
    SSL_write(ssl, command, strlen(command));
    
    bytes = SSL_read(ssl, response, sizeof(response) - 1);
    response[bytes] = '\0';
    printf("Server response: %s\n", response);
    
    // Continuing with fetching messages
    snprintf(command, sizeof(command), "a003 FETCH 1:* (ENVELOPE)\r\n");
    SSL_write(ssl, command, strlen(command));
    
    bytes = SSL_read(ssl, response, sizeof(response) - 1);
    response[bytes] = '\0';
    printf("Server response: %s\n", response);
    
    // Logout and cleanup
    snprintf(command, sizeof(command), "a004 LOGOUT\r\n");
    SSL_write(ssl, command, strlen(command));

    bytes = SSL_read(ssl, response, sizeof(response) - 1);
    response[bytes] = '\0';
    printf("Server response: %s\n", response);
    
    // Free resources
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    cleanup_openssl();
    
    return 0;
}

void initialize_openssl() {
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl() {
    EVP_cleanup();
}

SSL_CTX *create_context() {
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        handle_error("Unable to create SSL context");
    }
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    // Load the trusted CA certificates
    if (SSL_CTX_load_verify_locations(ctx, NULL, "/etc/ssl/certs") != 1) {
        handle_error("Unable to load CA certificates");
    }
}

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}