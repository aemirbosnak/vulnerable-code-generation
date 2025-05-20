//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

// Function to initialize OpenSSL
void init_openssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

// Function to clean up OpenSSL
void cleanup_openssl() {
    EVP_cleanup();
}

// Function to connect to the IMAP server
SSL* connect_to_imap(const char* hostname, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr;

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    if (connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("Socket connection failed");
        exit(EXIT_FAILURE);
    }

    SSL* ssl = SSL_new(SSL_CTX_new(TLS_client_method()));
    SSL_set_fd(ssl, sock);

    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        close(sock);
        exit(EXIT_FAILURE);
    }

    return ssl;
}

// Function to send a command to the IMAP server
void send_command(SSL* ssl, const char* command) {
    SSL_write(ssl, command, strlen(command));
}

// Function to receive a response from the IMAP server
void receive_response(SSL* ssl) {
    char buffer[4096];
    int bytes;

    while ((bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes] = '\0'; // null-terminate
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "BYE")) {
            break; // stop if we get OK or BYE response
        }
    }
}

// Main function
int main() {
    const char* hostname = "imap.example.com";
    int port = 993; // IMAP over SSL

    init_openssl();

    SSL* ssl = connect_to_imap(hostname, port);
    printf("Connected to %s on port %d! 😊\n", hostname, port);

    // Authentication
    const char* username = "your_username";
    const char* password = "your_password";
    char command[256];

    snprintf(command, sizeof(command), "a001 LOGIN %s %s\r\n", username, password);
    send_command(ssl, command);
    receive_response(ssl);

    // Fetch mailboxes
    printf("Fetching mailboxes...\n");
    send_command(ssl, "a002 LIST \"\" \"*\"\r\n");
    receive_response(ssl);

    // Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    cleanup_openssl();

    printf("Thank you for using the cheerful IMAP client! Have a great day! 🌼\n");
    return 0;
}