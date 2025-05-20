//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <openssl/ssl.h>

#define BUFFER_SIZE 4096
#define USERNAME "your_username"
#define PASSWORD "your_password"
#define SERVER_ADDRESS "pop.gmail.com"
#define SERVER_PORT "995"

#define CHECK_SSL_RETURN(x) if ((x) <= 0) { fprintf(stderr, "SSL error.\n");goto cleanup; }

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd, ret;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUFFER_SIZE];
    char username[256];
    char password[256];

    // ask for username and password
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // initialize SSL
    SSL_library_init();
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Failed to initialize SSL context.\n");
        return EXIT_FAILURE;
    }

    // load trusted root certificates
    if (!SSL_CTX_load_verify_locations(ctx, NULL, "/etc/ssl/certs")) {
        fprintf(stderr, "Failed to load trusted root certificates.\n");
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // resolve server address
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if ((ret = getaddrinfo(SERVER_ADDRESS, SERVER_PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "Failed to resolve server address: %s\n", gai_strerror(ret));
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // connect to server
    for (p = servinfo; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }
        break;
    }
    freeaddrinfo(servinfo);
    if (p == NULL) {
        fprintf(stderr, "Failed to connect to server.\n");
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // initialize SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) == -1) {
        fprintf(stderr, "Failed to initialize SSL connection.\n");
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // receive and print server greeting
    memset(buffer, 0, sizeof(buffer));
    CHECK_SSL_RETURN(SSL_read(ssl, buffer, BUFFER_SIZE - 1));
    printf("%s", buffer);

    // send login command
    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    CHECK_SSL_RETURN(SSL_write(ssl, buffer, strlen(buffer)));
    memset(buffer, 0, sizeof(buffer));
    CHECK_SSL_RETURN(SSL_read(ssl, buffer, BUFFER_SIZE - 1));
    printf("%s", buffer);
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid username.\n");
        goto cleanup;
    }

    // send password command
    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    CHECK_SSL_RETURN(SSL_write(ssl, buffer, strlen(buffer)));
    memset(buffer, 0, sizeof(buffer));
    CHECK_SSL_RETURN(SSL_read(ssl, buffer, BUFFER_SIZE - 1));
    printf("%s", buffer);
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid password.\n");
        goto cleanup;
    }

    // send list command
    snprintf(buffer, BUFFER_SIZE, "LIST\r\n");
    CHECK_SSL_RETURN(SSL_write(ssl, buffer, strlen(buffer)));
    memset(buffer, 0, sizeof(buffer));
    CHECK_SSL_RETURN(SSL_read(ssl, buffer, BUFFER_SIZE - 1));
    printf("%s", buffer);
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Failed to list emails.\n");
        goto cleanup;
    }

    // retrieve and print emails
    while (1) {
        printf("Enter email number (or -1 to exit): ");
        int email_num;
        scanf("%d", &email_num);
        if (email_num == -1) {
            break;
        }
        snprintf(buffer, BUFFER_SIZE, "RETR %d\r\n", email_num);
        CHECK_SSL_RETURN(SSL_write(ssl, buffer, strlen(buffer)));
        memset(buffer, 0, sizeof(buffer));
        CHECK_SSL_RETURN(SSL_read(ssl, buffer, BUFFER_SIZE - 1));
        printf("%s", buffer);
    }

    // send quit command
    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    CHECK_SSL_RETURN(SSL_write(ssl, buffer, strlen(buffer)));
    memset(buffer, 0, sizeof(buffer));
    CHECK_SSL_RETURN(SSL_read(ssl, buffer, BUFFER_SIZE - 1));
    printf("%s", buffer);

cleanup:
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    return EXIT_SUCCESS;
}