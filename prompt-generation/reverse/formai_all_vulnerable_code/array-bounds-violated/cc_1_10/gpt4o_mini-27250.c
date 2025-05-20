//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

SSL_CTX *initSSL() {
    SSL_METHOD *method;
    SSL_CTX *ctx;

    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();
    ERR_load_SSL_strings();
    method = SSLv23_client_method();
    ctx = SSL_CTX_new(method);
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}

void cleanupSSL(SSL_CTX *ctx) {
    SSL_CTX_free(ctx);
    EVP_cleanup();
}

void sendIMAPCommand(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
    SSL_write(ssl, "\r\n", 2);
}

void receiveIMAPResponse(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;

    while (1) {
        bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (bytes <= 0) {
            break;
        }
        buffer[bytes] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") || strstr(buffer, "NO") || strstr(buffer, "BAD")) {
            break;
        }
    }
}

void connectToIMAPServer(char *hostname, int port, char *username, char *password) {
    int sock;
    struct sockaddr_in server_addr;
    SSL_CTX *ctx;
    SSL *ssl;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handleError("Error creating socket");
    }

    // Setup server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handleError("Connection failed");
    }

    // Initialize SSL
    ctx = initSSL();
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
    }

    // Receive server greeting
    receiveIMAPResponse(ssl);

    // Login to the server
    char loginCommand[BUFFER_SIZE];
    snprintf(loginCommand, sizeof(loginCommand), "A001 LOGIN \"%s\" \"%s\"", username, password);
    sendIMAPCommand(ssl, loginCommand);
    receiveIMAPResponse(ssl);

    // List mailboxes
    sendIMAPCommand(ssl, "A002 LIST \"\" \"*\"");
    receiveIMAPResponse(ssl);
    
    // Select a mailbox (you can specify the mailbox if you like)
    sendIMAPCommand(ssl, "A003 SELECT \"INBOX\"");
    receiveIMAPResponse(ssl);

    // Clean up
    SSL_free(ssl);
    close(sock);
    cleanupSSL(ctx);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    connectToIMAPServer(hostname, port, username, password);

    return EXIT_SUCCESS;
}