//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024
#define GMAIL_IMAP_SERVER "imap.gmail.com"
#define GMAIL_IMAP_PORT "993"

int main(int argc, char **argv) {
    // Connect to IMAP server using TCP/IP
    int sockfd;
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    // Resolve hostname to IP address
    int error = getaddrinfo(GMAIL_IMAP_SERVER, GMAIL_IMAP_PORT, &hints, &res);
    if (error != 0) {
        printf("getaddrinfo error: %s\n", gai_strerror(error));
        return 1;
    }
    // Create socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }
    // Connect to server
    error = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (error == -1) {
        perror("connect");
        return 1;
    }
    freeaddrinfo(res);
    printf("Connected to %s:%s\n", GMAIL_IMAP_SERVER, GMAIL_IMAP_PORT);

    // Use SSL/TLS for secure connection
    SSL_library_init();
    SSL_CTX *ssl_ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ssl_ctx) {
        printf("SSL_CTX_new error\n");
        return 1;
    }
    SSL *ssl = SSL_new(ssl_ctx);
    if (!ssl) {
        printf("SSL_new error\n");
        return 1;
    }
    error = SSL_set_fd(ssl, sockfd);
    if (error == 0) {
        printf("SSL_set_fd error\n");
        return 1;
    }
    error = SSL_connect(ssl);
    if (error != 1) {
        printf("SSL_connect error: %d\n", SSL_get_error(ssl, error));
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ssl_ctx);
        return 1;
    }
    printf("SSL/TLS handshake completed\n");

    // Login to mailbox using IMAP protocol
    char *username = "your_username@gmail.com";
    char *password = "your_password";
    char buffer[BUF_SIZE];
    int nread = SSL_read(ssl, buffer, sizeof(buffer)-1);
    buffer[nread] = '\0';
    printf("%s", buffer);
    sprintf(buffer, "A001 LOGIN %s %s\r\n", username, password);
    error = SSL_write(ssl, buffer, strlen(buffer));
    if (error <= 0) {
        printf("SSL_write error\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ssl_ctx);
        return 1;
    }
    nread = SSL_read(ssl, buffer, sizeof(buffer)-1);
    buffer[nread] = '\0';
    printf("%s", buffer);
    if (strstr(buffer, "FAILED") != NULL) {
        printf("Login failed\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ssl_ctx);
        return 1;
    }
    printf("Login successfully\n");

    // List all mailboxes
    sprintf(buffer, "A002 LIST \"\" \"*\"\r\n");
    error = SSL_write(ssl, buffer, strlen(buffer));
    if (error <= 0) {
        printf("SSL_write error\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ssl_ctx);
        return 1;
    }
    nread = SSL_read(ssl, buffer, sizeof(buffer)-1);
    buffer[nread] = '\0';
    printf("%s", buffer);

    // Select the INBOX mailbox
    sprintf(buffer, "A003 SELECT INBOX\r\n");
    error = SSL_write(ssl, buffer, strlen(buffer));
    if (error <= 0) {
        printf("SSL_write error\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ssl_ctx);
        return 1;
    }
    nread = SSL_read(ssl, buffer, sizeof(buffer)-1);
    buffer[nread] = '\0';
    printf("%s", buffer);

    // Fetch the first message
    sprintf(buffer, "A004 FETCH 1 BODY[TEXT]\r\n");
    error = SSL_write(ssl, buffer, strlen(buffer));
    if (error <= 0) {
        printf("SSL_write error\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ssl_ctx);
        return 1;
    }
    while (1) {
        nread = SSL_read(ssl, buffer, sizeof(buffer)-1);
        if (nread <= 0) {
            break;
        }
        buffer[nread] = '\0';
        printf("%s", buffer);
    }

    // Logout and close connection
    sprintf(buffer, "A005 LOGOUT\r\n");
    error = SSL_write(ssl, buffer, strlen(buffer));
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sockfd);
    return 0;
}