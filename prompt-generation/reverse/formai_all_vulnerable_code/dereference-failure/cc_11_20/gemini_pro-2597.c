//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize OpenSSL.
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    // Create a new SSL context.
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "SSL_CTX_new failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    // Create a new SSL connection.
    SSL *ssl = SSL_new(ctx);
    if (ssl == NULL) {
        fprintf(stderr, "SSL_new failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    // Connect to the IMAP server.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "socket failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "connect failed: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Associate the SSL connection with the socket.
    SSL_set_fd(ssl, sockfd);

    // Perform the SSL handshake.
    if (SSL_connect(ssl) < 0) {
        fprintf(stderr, "SSL_connect failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    // Send the IMAP command.
    const char *cmd = "CAPABILITY\r\n";
    int len = strlen(cmd);
    if (SSL_write(ssl, cmd, len) != len) {
        fprintf(stderr, "SSL_write failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    // Receive the IMAP response.
    char buf[BUFSIZE];
    len = SSL_read(ssl, buf, BUFSIZE);
    if (len < 0) {
        fprintf(stderr, "SSL_read failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    // Parse the IMAP response.
    char *line = strtok(buf, "\r\n");
    while (line != NULL) {
        printf("%s\n", line);
        line = strtok(NULL, "\r\n");
    }

    // Close the SSL connection.
    SSL_shutdown(ssl);
    SSL_free(ssl);

    // Close the socket.
    close(sockfd);

    // Clean up OpenSSL.
    SSL_CTX_free(ctx);
    EVP_cleanup();

    return EXIT_SUCCESS;
}