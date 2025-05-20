//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>

#define PORT 4433
#define BACKLOG 10

int main() {
    int sockfd, newsockfd, clientlen;
    struct sockaddr_in serveraddr, clientaddr;
    SSL_CTX *ctx;
    SSL *ssl;

    // Initialize OpenSSL
    SSL_library_init();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(TLSv1_2_server_method());
    if (ctx == NULL) {
        perror("SSL_CTX_new");
        exit(EXIT_FAILURE);
    }
    if (SSL_CTX_use_certificate_file(ctx, "server.crt", SSL_FILETYPE_PEM) <= 0) {
        perror("SSL_CTX_use_certificate_file");
        exit(EXIT_FAILURE);
    }
    if (SSL_CTX_use_PrivateKey_file(ctx, "server.key", SSL_FILETYPE_PEM) <= 0) {
        perror("SSL_CTX_use_PrivateKey_file");
        exit(EXIT_FAILURE);
    }

    // Create server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);

    // Bind server address to socket
    if (bind(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(sockfd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept client connections
    while (1) {
        clientlen = sizeof(clientaddr);
        newsockfd = accept(sockfd, (struct sockaddr *) &clientaddr, &clientlen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        // Create SSL connection
        ssl = SSL_new(ctx);
        if (ssl == NULL) {
            perror("SSL_new");
            close(newsockfd);
            continue;
        }
        if (SSL_set_fd(ssl, newsockfd) <= 0) {
            perror("SSL_set_fd");
            SSL_free(ssl);
            close(newsockfd);
            continue;
        }
        if (SSL_accept(ssl) <= 0) {
            perror("SSL_accept");
            SSL_free(ssl);
            close(newsockfd);
            continue;
        }

        // Receive and send messages
        char buffer[1024];
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            if (SSL_read(ssl, buffer, sizeof(buffer)) <= 0) {
                perror("SSL_read");
                SSL_free(ssl);
                close(newsockfd);
                break;
            }
            printf("Client: %s", buffer);
            memset(buffer, 0, sizeof(buffer));
            scanf("%s", buffer);
            if (SSL_write(ssl, buffer, strlen(buffer)) <= 0) {
                perror("SSL_write");
                SSL_free(ssl);
                close(newsockfd);
                break;
            }
        }

        // Close SSL connection
        SSL_free(ssl);

        // Close client socket
        close(newsockfd);
    }

    // Close server socket
    close(sockfd);

    // Cleanup OpenSSL
    SSL_CTX_free(ctx);
    EVP_cleanup();

    return 0;
}