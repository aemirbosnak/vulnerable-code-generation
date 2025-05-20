//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 995  // Standard POP3S port

void initialize_ssl() {
    SSL_load_error_strings();
    SSL_library_init();
    OpenSSL_add_all_algorithms();
}

void cleanup_ssl() {
    EVP_cleanup();
}

SSL* create_ssl_connection(int socket) {
    const SSL_METHOD *method;
    SSL_CTX *ctx;
    SSL *ssl;

    method = SSLv23_client_method();
    ctx = SSL_CTX_new(method);
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, socket);

    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    }
    
    SSL_CTX_free(ctx);
    return ssl;
}

void pop3_command(SSL *ssl, const char *command) {
    char buffer[BUFFER_SIZE];
    SSL_write(ssl, command, strlen(command));
    SSL_write(ssl, "\r\n", 2);

    int bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (bytes > 0) {
        buffer[bytes] = '\0'; // Null-terminate
        printf("%s", buffer);
    }
}

void retrieve_email_list(SSL *ssl) {
    pop3_command(ssl, "USER your_username"); // use your POP3 username
    pop3_command(ssl, "PASS your_password");  // use your POP3 password
    pop3_command(ssl, "LIST"); // list all messages
    pop3_command(ssl, "QUIT"); // gracefully exit
}

int main() {
    int socket_desc;
    struct sockaddr_in server_addr;

    // Initialize OpenSSL
    initialize_ssl();

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        fprintf(stderr, "Could not create socket\n");
        return 1;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    // Replace with your POP3 server address
    inet_pton(AF_INET, "your.pop3.server", &server_addr.sin_addr);

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Connection failed\n");
        return 1;
    }

    // Create SSL connection
    SSL *ssl = create_ssl_connection(socket_desc);
    
    // Retrieve list of emails
    retrieve_email_list(ssl);

    // Clean up and close
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(socket_desc);
    
    // Cleanup OpenSSL
    cleanup_ssl();

    return 0;
}