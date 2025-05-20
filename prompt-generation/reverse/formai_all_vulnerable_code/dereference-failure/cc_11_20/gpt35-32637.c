//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./imapclient [server] [port] [username]\n");
        exit(1);
    }

    // Initialize OpenSSL
    SSL_load_error_strings();
    SSL_library_init();
    
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get server information
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("Error getting server");
        exit(1);
    }

    // Fill in server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Create SSL context
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        perror("Error creating SSL context");
        exit(1);
    }

    // Create SSL object
    SSL *ssl = SSL_new(ctx);
    if (ssl == NULL) {
        perror("Error creating SSL object");
        exit(1);
    }

    // Connect SSL object to socket
    if (SSL_set_fd(ssl, sockfd) == 0) {
        perror("Error setting SSL file descriptor");
        exit(1);
    }

    // Connect SSL object to server
    if (SSL_connect(ssl) != 1) {
        perror("Error connecting with SSL");
        exit(1);
    }

    printf("Connected to IMAP server.\n");

    // Send login command
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "LOGIN %s\r\n", argv[3]);
    if (SSL_write(ssl, buffer, strlen(buffer)) <= 0) {
        perror("Error sending login command");
        exit(1);
    }

    // Receive login response
    memset(buffer, 0, BUFFER_SIZE);
    if (SSL_read(ssl, buffer, BUFFER_SIZE) <= 0) {
        perror("Error receiving login response");
        exit(1);
    }

    // Check for OK response
    if (strstr(buffer, "OK") == NULL) {
        printf("Login failed.\n");
        exit(1);
    }

    printf("Login successful.\n");

    // Send list command
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "LIST \"\" \"*\"\r\n");
    if (SSL_write(ssl, buffer, strlen(buffer)) <= 0) {
        perror("Error sending list command");
        exit(1);
    }

    // Receive list response
    memset(buffer, 0, BUFFER_SIZE);
    if (SSL_read(ssl, buffer, BUFFER_SIZE) <= 0) {
        perror("Error receiving list response");
        exit(1);
    }

    printf("List of folders:\n%s\n", buffer);

    // Logout
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "LOGOUT\r\n");
    if (SSL_write(ssl, buffer, strlen(buffer)) <= 0) {
        perror("Error sending logout command");
        exit(1);
    }

    // Receive logout response
    memset(buffer, 0, BUFFER_SIZE);
    if (SSL_read(ssl, buffer, BUFFER_SIZE) <= 0) {
        perror("Error receiving logout response");
        exit(1);
    }

    printf("Logged out.\n");

    // Free SSL resources
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    // Close socket
    close(sockfd);

    return 0;
}