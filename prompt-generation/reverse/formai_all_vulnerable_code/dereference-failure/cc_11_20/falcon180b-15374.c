//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <openssl/ssl.h>

#define PORT 443
#define HOST "www.example.com"
#define PATH "/"

int main(int argc, char *argv[]) {
    SSL_CTX *ctx;
    SSL *ssl;
    BIO *bio;
    int sock;
    struct hostent *he;
    struct sockaddr_in addr;
    char *request;
    char *response;
    int len;

    // Initialize SSL context
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "SSL_CTX_new failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(1);
    }

    // Load trusted CA certificates
    if (!SSL_CTX_load_verify_locations(ctx, NULL, "/etc/ssl/certs")) {
        fprintf(stderr, "SSL_CTX_load_verify_locations failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(1);
    }

    // Set verify mode to require peer certificate verification
    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, NULL);

    // Create SSL object
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        fprintf(stderr, "SSL_new failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(1);
    }

    // Create BIO object for SSL connection
    bio = BIO_new_socket(sock, BIO_NOCLOSE);
    SSL_set_bio(ssl, bio, bio);

    // Connect to server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "socket failed: %s\n", strerror(errno));
        exit(1);
    }

    he = gethostbyname(HOST);
    if (he == NULL) {
        fprintf(stderr, "gethostbyname failed: %s\n", strerror(errno));
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr.s_addr, he->h_addr, he->h_length);
    addr.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "connect failed: %s\n", strerror(errno));
        exit(1);
    }

    // Send HTTP request
    request = "GET " PATH " HTTP/1.1\r\nHost: " HOST "\r\nConnection: close\r\n\r\n";
    len = strlen(request);
    if (SSL_write(ssl, request, len) <= 0) {
        fprintf(stderr, "SSL_write failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(1);
    }

    // Read HTTP response
    response = NULL;
    len = 0;
    while (1) {
        char buf[4096];
        int n;

        n = SSL_read(ssl, buf, sizeof(buf));
        if (n <= 0) {
            if (SSL_get_error(ssl, n) == SSL_ERROR_ZERO_RETURN) {
                break;
            } else {
                fprintf(stderr, "SSL_read failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
                exit(1);
            }
        }

        response = realloc(response, len + n);
        memcpy(response + len, buf, n);
        len += n;
    }

    // Print HTTP response
    printf("HTTP response:\n%s", response);

    // Clean up
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);

    return 0;
}