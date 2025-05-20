//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVERNAME "imap.gmail.com"
#define PORT "993"

int main(int argc, char *argv[]) {
    int sockfd, err, len;
    struct addrinfo hints, *servinfo, *p;
    SSL_CTX *ctx;
    SSL *ssl;
    char buffer[1024];
    char user[128], pass[128], command[1024];

    // Prompt user for login credentials
    printf("Enter your email address: ");
    scanf("%s", user);
    printf("Enter your password: ");
    scanf("%s", pass);

    // Initialize SSL library
    SSL_library_init();

    // Create SSL context
    ctx = SSL_CTX_new(SSLv23_client_method());

    // Load CA certificates
    SSL_CTX_set_default_verify_paths(ctx);

    // Create socket file descriptor
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if ((err = getaddrinfo(SERVERNAME, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(err));
        exit(1);
    }

    // Loop through all the results and connect to the first one that works
    for (p = servinfo; p != NULL; p = p->ai_next) {
        // Create socket
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        // Connect to server
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        // Successfully connected
        break;
    }

    // Free servinfo
    freeaddrinfo(servinfo);

    if (p == NULL) {
        // Failed to connect to any server
        fprintf(stderr, "Failed to connect\n");
        exit(2);
    }

    // Create SSL object
    ssl = SSL_new(ctx);

    // Attach SSL object to socket file descriptor
    SSL_set_fd(ssl, sockfd);

    // Connect SSL object to server
    if (SSL_connect(ssl) == -1) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // Receive server greeting
    len = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[len] = '\0';
    printf("%s\n", buffer);

    // Log in to server
    sprintf(command, "LOGIN %s %s\r\n", user, pass);
    SSL_write(ssl, command, strlen(command));
    len = SSL_read(ssl, buffer, sizeof(buffer) - 1);
    buffer[len] = '\0';
    printf("%s\n", buffer);

    // Exit gracefully
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return 0;
}