//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *server;
    int port;
    char *username;
    char *password;
    char *from;
    char *to;
    char *subject;
    char *body;
} Email;

void initialize_openssl() {
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
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    // Load the trust store (might have to add your certificates)
    // SSL_CTX_load_verify_locations(ctx, "path/to/cert.crt", NULL);
}

void send_email(Email *email) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    SSL *ssl;
    SSL_CTX *ctx;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Unable to create socket");
        return;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(email->port);
    inet_pton(AF_INET, email->server, &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return;
    }

    // Initiate SSL
    ctx = create_context();
    configure_context(ctx);
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    }

    // Prepare email content
    snprintf(buffer, BUFFER_SIZE,
            "EHLO %s\r\n"
            "AUTH LOGIN\r\n"
            "%s\r\n"
            "%s\r\n"
            "MAIL FROM: <%s>\r\n"
            "RCPT TO: <%s>\r\n"
            "DATA\r\n"
            "Subject: %s\r\n\r\n%s\r\n.\r\n"
            "QUIT\r\n",
            email->server, 
            email->username, 
            email->password, 
            email->from, 
            email->to, 
            email->subject, 
            email->body);

    SSL_write(ssl, buffer, strlen(buffer));
    
    // Read response
    int bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (bytes > 0) {
        buffer[bytes] = '\0'; // Null-terminate
        printf("Server response: %s\n", buffer);
    }
    
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
}

int main() {
    initialize_openssl();

    Email email;
    email.server = "smtp.example.com";
    email.port = 587; // or 465 for SSL
    email.username = "your_base64_encoded_username";
    email.password = "your_base64_encoded_password";
    email.from = "from@example.com";
    email.to = "to@example.com";
    email.subject = "Test Email from C Client";
    email.body = "This is a test email sent from a C email client!";

    send_email(&email);

    cleanup_openssl();
    return 0;
}