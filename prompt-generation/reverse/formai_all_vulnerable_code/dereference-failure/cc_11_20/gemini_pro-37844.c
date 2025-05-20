//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER_PORT 465
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, rc;
    struct sockaddr_in server_addr;
    SSL *ssl;
    SSL_CTX *ctx;
    char buf[MAX_DATA_SIZE];

    // Initialize the SSL library
    SSL_library_init();
    SSL_load_error_strings();

    // Create a new SSL context
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Error creating SSL context: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    // Create a new SSL object
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        fprintf(stderr, "Error creating SSL object: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    // Connect to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    rc = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (rc == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Set up the SSL connection
    SSL_set_fd(ssl, sockfd);
    rc = SSL_connect(ssl);
    if (rc != 1) {
        fprintf(stderr, "Error connecting to server: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    // Send an email message to the server
    strcpy(buf, "From: me@example.com\r\n");
    rc = SSL_write(ssl, buf, strlen(buf));
    if (rc == -1) {
        fprintf(stderr, "Error sending data to server: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    strcpy(buf, "To: you@example.com\r\n");
    rc = SSL_write(ssl, buf, strlen(buf));
    if (rc == -1) {
        fprintf(stderr, "Error sending data to server: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    strcpy(buf, "Subject: Test email\r\n");
    rc = SSL_write(ssl, buf, strlen(buf));
    if (rc == -1) {
        fprintf(stderr, "Error sending data to server: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    strcpy(buf, "\r\n");
    rc = SSL_write(ssl, buf, strlen(buf));
    if (rc == -1) {
        fprintf(stderr, "Error sending data to server: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    strcpy(buf, "This is a test email.\r\n");
    rc = SSL_write(ssl, buf, strlen(buf));
    if (rc == -1) {
        fprintf(stderr, "Error sending data to server: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    // Close the SSL connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}