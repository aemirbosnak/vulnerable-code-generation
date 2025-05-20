//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024

// Global SSL context variable
SSL_CTX *ctx = NULL;

// SSL error handling function
void handleSSLerrors(void) {
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
}

void cleanup(SSL *ssl, int sock) {
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    exit(EXIT_SUCCESS);
}

// Connect to the IMAP server using SSL/TLS
int connectToServer(char *host, char *port, SSL **ssl) {
    // Get host IP address
    struct hostent *hostIP;
    if ((hostIP = gethostbyname(host)) == NULL) {
        printf("Error resolving hostname %s\n", host);
        return -1;
    }
    // Create socket for the connection
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        return -1;
    }
    // Set server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(port));
    serverAddr.sin_addr.s_addr = *((unsigned long*)hostIP->h_addr);
    memset(&(serverAddr.sin_zero), '\0', 8);
    // Connect to the server
    if (connect(sock, (struct sockaddr*)&serverAddr, sizeof(struct sockaddr)) == -1) {
        printf("Error connecting to server\n");
        return -1;
    }
    // Create SSL/TLS context
    if (ctx == NULL) {
        SSL_library_init();
        SSLeay_add_ssl_algorithms();
        SSL_load_error_strings();
        ctx = SSL_CTX_new(SSLv23_method());
        SSL_CTX_set_options(ctx, SSL_OP_SINGLE_DH_USE);
    }
    // Create SSL/TLS connection
    *ssl = SSL_new(ctx);
    SSL_set_fd(*ssl, sock);
    if (SSL_connect(*ssl) == -1) {
        printf("Error creating SSL/TLS connection\n");
        handleSSLerrors();
        return -1;
    }
    return sock;
}

// Send command to server and receive response
int sendCommand(SSL *ssl, char *command, char *response) {
    // Send command
    if (SSL_write(ssl, command, strlen(command)) <= 0) {
        printf("Error sending command: %s\n", command);
        return -1;
    }
    // Receive response
    int bytesRecv, totalBytesRecv = 0;
    char buffer[BUF_SIZE];
    memset(buffer, '\0', BUF_SIZE);
    do {
        bytesRecv = SSL_read(ssl, buffer, BUF_SIZE-1);
        if (bytesRecv <= 0) {
            printf("Error receiving response\n");
            return -1;
        }
        totalBytesRecv += bytesRecv;
        buffer[bytesRecv] = '\0';
        strcat(response, buffer);
    } while (strstr(response, "\r\n") == NULL);
    return totalBytesRecv;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s [IMAP server] [IMAP port] [username]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *host = argv[1];
    char *port = argv[2];
    char *username = argv[3];
    SSL *ssl;
    // Connect to the server
    int sock;
    if ((sock = connectToServer(host, port, &ssl)) == -1) {
        exit(EXIT_FAILURE);
    }
    // Receive server greeting
    char response[BUF_SIZE];
    memset(response, '\0', BUF_SIZE);
    if (sendCommand(ssl, "", response) == -1) {
        cleanup(ssl, sock);
    }
    printf("%s", response);
    // Send login command
    sprintf(response, "login %s\r\n", username);
    if (sendCommand(ssl, response, response) == -1) {
        cleanup(ssl, sock);
    }
    printf("%s", response);
    // Send logout command
    if (sendCommand(ssl, "logout\r\n", response) == -1) {
        cleanup(ssl, sock);
    }
    printf("%s", response);
    // Cleanup and exit
    cleanup(ssl, sock);
    return 0;
}