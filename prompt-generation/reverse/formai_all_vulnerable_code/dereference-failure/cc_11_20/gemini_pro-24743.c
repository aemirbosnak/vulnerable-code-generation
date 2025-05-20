//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 993
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, err;
    struct sockaddr_in serv_addr;
    char *hostname, *username, *password;
    char buf[BUFSIZE];
    SSL *ssl;
    SSL_CTX *ctx;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    hostname = argv[1];
    username = argv[2];
    password = argv[3];

    // Initialize OpenSSL
    SSL_library_init();
    SSL_load_error_strings();

    // Create a new SSL context
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        fprintf(stderr, "SSL_CTX_new() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    // Create a new SSL connection
    ssl = SSL_new(ctx);
    if (!ssl) {
        fprintf(stderr, "SSL_new() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "connect() failed: %s\n", strerror(errno));
        close(sockfd);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Set the SSL connection to use the socket
    SSL_set_fd(ssl, sockfd);

    // Perform the SSL handshake
    err = SSL_connect(ssl);
    if (err != 1) {
        fprintf(stderr, "SSL_connect() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        close(sockfd);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Send the LOGIN command
    snprintf(buf, BUFSIZE, "LOGIN %s %s\r\n", username, password);
    err = SSL_write(ssl, buf, strlen(buf));
    if (err < 0) {
        fprintf(stderr, "SSL_write() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        close(sockfd);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Read the response from the server
    err = SSL_read(ssl, buf, BUFSIZE);
    if (err < 0) {
        fprintf(stderr, "SSL_read() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        close(sockfd);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Print the response from the server
    printf("%s", buf);

    // Perform the LIST command
    snprintf(buf, BUFSIZE, "LIST \"\" *\r\n");
    err = SSL_write(ssl, buf, strlen(buf));
    if (err < 0) {
        fprintf(stderr, "SSL_write() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        close(sockfd);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Read the response from the server
    err = SSL_read(ssl, buf, BUFSIZE);
    if (err < 0) {
        fprintf(stderr, "SSL_read() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        close(sockfd);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Print the response from the server
    printf("%s", buf);

    // Perform the QUIT command
    snprintf(buf, BUFSIZE, "QUIT\r\n");
    err = SSL_write(ssl, buf, strlen(buf));
    if (err < 0) {
        fprintf(stderr, "SSL_write() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        close(sockfd);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Read the response from the server
    err = SSL_read(ssl, buf, BUFSIZE);
    if (err < 0) {
        fprintf(stderr, "SSL_read() failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        close(sockfd);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Print the response from the server
    printf("%s", buf);

    // Close the SSL connection
    SSL_shutdown(ssl);

    // Close the socket
    close(sockfd);

    // Free the SSL connection
    SSL_free(ssl);

    // Free the SSL context
    SSL_CTX_free(ctx);

    return EXIT_SUCCESS;
}