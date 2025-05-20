//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void ssl_init() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void ssl_cleanup() {
    EVP_cleanup();
}

int create_socket(const char *hostname, int port) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Unable to create socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to SMTP server failed");
    }

    return sock;
}

void send_command(SSL *ssl, const char *cmd) {
    SSL_write(ssl, cmd, strlen(cmd));
}

void receive_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;

    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Response: %s", buffer);
}

void smtp_authenticate(SSL *ssl, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    // Initial HELO command
    send_command(ssl, "EHLO localhost\r\n");
    receive_response(ssl);

    // Auth Login Command
    send_command(ssl, "AUTH LOGIN\r\n");
    receive_response(ssl);

    // Send Username
    sprintf(command, "%s\r\n", username);
    send_command(ssl, command);
    receive_response(ssl);

    // Send Password
    sprintf(command, "%s\r\n", password);
    send_command(ssl, command);
    receive_response(ssl);
}

void send_email(SSL *ssl, const char *from, const char *to, const char *subject, const char *body) {
    char command[BUFFER_SIZE];

    // Specify the sender
    sprintf(command, "MAIL FROM:<%s>\r\n", from);
    send_command(ssl, command);
    receive_response(ssl);

    // Specify the recipient
    sprintf(command, "RCPT TO:<%s>\r\n", to);
    send_command(ssl, command);
    receive_response(ssl);

    // Start mail data
    send_command(ssl, "DATA\r\n");
    receive_response(ssl);

    // Specify subject and body
    sprintf(command, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(ssl, command);
    receive_response(ssl);
}

int main() {
    const char *username = "your_email@example.com";
    const char *password = "your_password";
    const char *from = "your_email@example.com";
    const char *to = "recipient_email@example.com";
    const char *subject = "Test Email";
    const char *body = "Hello, this is a test email from a simple SMTP client.";

    ssl_init();
    
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        handle_error("Unable to create SSL context");
    }

    SSL *ssl = SSL_new(ctx);
    int sock = create_socket(SMTP_SERVER, SMTP_PORT);
    
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        handle_error("SSL connect failed");
    }

    smtp_authenticate(ssl, username, password);
    send_email(ssl, from, to, subject, body);

    // Close connection
    send_command(ssl, "QUIT\r\n");
    receive_response(ssl);

    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    ssl_cleanup();

    return 0;
}