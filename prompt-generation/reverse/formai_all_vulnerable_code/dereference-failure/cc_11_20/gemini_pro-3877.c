//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    char buffer[BUFSIZE];
    EVP_CIPHER_CTX *ctx;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <port> <key>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        ctx = EVP_CIPHER_CTX_new();
        if (ctx == NULL) {
            perror("EVP_CIPHER_CTX_new");
            exit(1);
        }

        if (EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *) argv[2], NULL, 0) != 1) {
            perror("EVP_CipherInit_ex");
            exit(1);
        }

        while (1) {
            bzero(buffer, BUFSIZE);
            n = read(newsockfd, buffer, BUFSIZE);
            if (n < 0) {
                perror("read");
                exit(1);
            }

            if (n == 0) {
                break;
            }

            if (EVP_CipherUpdate(ctx, buffer, &n, (unsigned char *) buffer, n) != 1) {
                perror("EVP_CipherUpdate");
                exit(1);
            }

            if (write(newsockfd, buffer, n) < 0) {
                perror("write");
                exit(1);
            }
        }

        if (EVP_CipherFinal_ex(ctx, buffer, &n) != 1) {
            perror("EVP_CipherFinal_ex");
            exit(1);
        }

        if (write(newsockfd, buffer, n) < 0) {
            perror("write");
            exit(1);
        }

        EVP_CIPHER_CTX_free(ctx);
        close(newsockfd);
    }

    close(sockfd);

    return 0;
}