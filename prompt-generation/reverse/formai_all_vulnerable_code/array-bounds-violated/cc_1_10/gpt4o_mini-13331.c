//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

SSL* initializeSSL() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    SSL_CTX* ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) handleErrors();
    return ctx;
}

int connectToServer(const char* hostname) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

void imapSend(SSL* ssl, const char* command) {
    SSL_write(ssl, command, strlen(command));
}

void imapReceive(SSL* ssl) {
    char buffer[BUFFER_SIZE];
    int bytesRead = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    if (bytesRead > 0) {
        buffer[bytesRead] = '\0';
        printf("%s", buffer);
    } else {
        perror("Failed to read from server");
    }
}

void login(SSL* ssl, const char* username, const char* password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "a1 LOGIN %s %s\r\n", username, password);
    imapSend(ssl, command);
    imapReceive(ssl);
}

void selectMailbox(SSL* ssl, const char* mailbox) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "a2 SELECT %s\r\n", mailbox);
    imapSend(ssl, command);
    imapReceive(ssl);
}

void fetchEmails(SSL* ssl) {
    imapSend(ssl, "a3 FETCH 1:* (ENVELOPE)\r\n");
    imapReceive(ssl);
}

int main() {
    // Input your IMAP server credentials
    const char* hostname = "imap.example.com"; // Change this to your IMAP server
    const char* username = "your_email@example.com"; // Change to your email
    const char* password = "your_password"; // Change to your password

    SSL* ssl = initializeSSL();
    int sockfd = connectToServer(hostname);

    SSL* ssl_conn = SSL_new(ssl);
    SSL_set_fd(ssl_conn, sockfd);
    if (SSL_connect(ssl_conn) <= 0) handleErrors();

    imapReceive(ssl_conn);
    login(ssl_conn, username, password);
    selectMailbox(ssl_conn, "INBOX");
    fetchEmails(ssl_conn);

    // Clean up
    SSL_free(ssl_conn);
    close(sockfd);
    SSL_CTX_free(ssl);
    EVP_cleanup();

    return 0;
}