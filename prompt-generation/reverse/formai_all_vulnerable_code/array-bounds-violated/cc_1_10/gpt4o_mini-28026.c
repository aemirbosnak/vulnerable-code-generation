//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 465
#define BUFFER_SIZE 512

// Function declarations
void handle_error(const char *msg);
void send_command(SSL *ssl, const char *cmd);
void send_email(SSL *ssl, const char *from, const char *to, const char *subject, const char *body);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    SSL_CTX *ctx;
    SSL *ssl;

    // Initialize OpenSSL
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    ctx = SSL_CTX_new(TLS_client_method());

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Could not create socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, SMTP_SERVER, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address");
    }

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    // Create SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) <= 0) {
        handle_error("SSL connect failed");
    }

    // Start the email sending process
    send_command(ssl, "EHLO localhost");
    send_command(ssl, "AUTH LOGIN"); // Authentication login
    send_command(ssl, "base64-encoded-username");
    send_command(ssl, "base64-encoded-password");
    
    // Send Email
    send_email(ssl, "from@example.com", "to@example.com", "SMTP Test Email", "Hello, this is a test email sent from a C program!");

    // Close connection
    send_command(ssl, "QUIT");
    
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    EVP_cleanup();
    return 0;
}

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(SSL *ssl, const char *cmd) {
    char buffer[BUFFER_SIZE];
    int len;

    // Send the command
    SSL_write(ssl, cmd, strlen(cmd));
    SSL_write(ssl, "\r\n", 2);

    // Read the response
    len = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[len] = '\0'; // Null terminate the buffer
    printf("Server response: %s", buffer);
}

void send_email(SSL *ssl, const char *from, const char *to, const char *subject, const char *body) {
    send_command(ssl, "MAIL FROM:<from@example.com>");
    send_command(ssl, "RCPT TO:<to@example.com>");
    send_command(ssl, "DATA");
    
    char data[BUFFER_SIZE];
    snprintf(data, sizeof(data), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(ssl, data);
}