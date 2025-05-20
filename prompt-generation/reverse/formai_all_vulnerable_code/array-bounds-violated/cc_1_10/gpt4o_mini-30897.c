//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "pop.your-email-provider.com"
#define PORT 995
#define MAX_BUFFER 1024

void handleError(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

SSL_CTX *initializeSSLContext() {
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        handleError("Unable to create SSL context");
    }
    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);
    return ctx;
}

void cleanupSSL(SSL *ssl, SSL_CTX *ctx) {
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
}

void retrieveEmails(SSL *ssl) {
    char buffer[MAX_BUFFER];
    int bytes;

    // Send USER command
    snprintf(buffer, sizeof(buffer), "USER your-email@example.com\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Response: %s", buffer);

    // Send PASS command
    snprintf(buffer, sizeof(buffer), "PASS your-password\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Response: %s", buffer);

    // Send LIST command to retrieve email list
    SSL_write(ssl, "LIST\r\n", strlen("LIST\r\n"));
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Email list: %s\n", buffer);

    // Retrieve specific email
    int email_id;
    printf("Enter email ID to retrieve: ");
    scanf("%d", &email_id);
    
    snprintf(buffer, sizeof(buffer), "RETR %d\r\n", email_id);
    SSL_write(ssl, buffer, strlen(buffer));
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Email content: %s\n", buffer);

    // Send QUIT command to end session
    SSL_write(ssl, "QUIT\r\n", strlen("QUIT\r\n"));
    bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    printf("Response: %s", buffer);
}

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sock;
    struct sockaddr_in server_addr;
    
    // Initialize SSL
    SSL_library_init();
    ctx = initializeSSLContext();
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handleError("Failed to create socket");
    }

    // Setup server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("your.pop.server.ip"); // replace with actual IP

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handleError("Connection failed");
    }

    // Create an SSL structure and connect
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) != 1) {
        handleError("SSL connection failed");
    }

    printf("Connected to POP3 server\n");

    retrieveEmails(ssl);

    // Clean up SSL
    cleanupSSL(ssl, ctx);
    
    // Close the socket
    close(sock);
    
    return 0;
}