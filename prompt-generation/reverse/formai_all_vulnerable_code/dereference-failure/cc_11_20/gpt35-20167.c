//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <fcntl.h>

#define PORT 993 // IMAP SSL port

int main(int argc, char *argv[]) {
    SSL_CTX *ctx; // SSL context
    SSL *ssl; // SSL connection object
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buffer[4096];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Get server information
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Set server address and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    memcpy(&servaddr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Initialize OpenSSL library
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(TLSv1_2_client_method());

    // Create SSL connection object
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    // Connect SSL connection object to server
    if (SSL_connect(ssl) < 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Set non-blocking mode for socket
    int flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

    // Send login command
    sprintf(buffer, "LOGIN %s password\n", argv[2]);
    SSL_write(ssl, buffer, strlen(buffer));

    // Wait for response
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int n = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (n > 0) {
            printf("Received: %s", buffer);
            if (strstr(buffer, "OK") != NULL) {
                printf("Authentication successful");
                break;
            }
        }
    }

    // Send fetch command
    sprintf(buffer, "FETCH 1 BODY[TEXT]\n");
    SSL_write(ssl, buffer, strlen(buffer));

    // Wait for response
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int n = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (n > 0) {
            printf("%s", buffer);
            if (strstr(buffer, "OK FETCH") != NULL) {
                break;
            }
        }
    }

    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}