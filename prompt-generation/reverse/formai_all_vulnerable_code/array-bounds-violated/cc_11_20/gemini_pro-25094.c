//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <assert.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT "995"
#define HOST "pop.example.com"
#define USERNAME "username"
#define PASSWORD "password"

void usage() {
    fprintf(stderr, "Usage: %s [host] [port] [username] [password]\n", "pop3_client");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, port;
    struct sockaddr_in servaddr;
    char hostname[1024];
    SSL *ssl;
    SSL_CTX *ctx;

    // Initialize SSL library
    SSL_library_init();
    SSL_load_error_strings();

    // Create a new SSL context
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ctx == NULL) {
        perror("SSL_CTX_new");
        exit(EXIT_FAILURE);
    }

    // Create a new SSL connection
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        perror("SSL_new");
        exit(EXIT_FAILURE);
    }

    // Get hostname and port number
    if (argc >= 2) {
        strcpy(hostname, argv[1]);
    } else {
        strcpy(hostname, HOST);
    }

    if (argc >= 3) {
        port = atoi(argv[2]);
    } else {
        port = atoi(PORT);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(hostname);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Set the SSL socket
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        perror("SSL_connect");
        exit(EXIT_FAILURE);
    }

    // Verify the server's certificate
    int ret = SSL_get_verify_result(ssl);
    if (ret != X509_V_OK) {
        fprintf(stderr, "Certificate verification failed: %s\n", X509_verify_cert_error_string(ret));
        exit(EXIT_FAILURE);
    }

    // Send the USER command
    char cmd[1024];
    sprintf(cmd, "USER %s\r\n", USERNAME);
    if (SSL_write(ssl, cmd, strlen(cmd)) == -1) {
        perror("SSL_write");
        exit(EXIT_FAILURE);
    }

    // Read the server's response
    char buf[1024];
    int n = SSL_read(ssl, buf, sizeof(buf));
    if (n == -1) {
        perror("SSL_read");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid response: %s\n", buf);
        exit(EXIT_FAILURE);
    }

    // Send the PASS command
    sprintf(cmd, "PASS %s\r\n", PASSWORD);
    if (SSL_write(ssl, cmd, strlen(cmd)) == -1) {
        perror("SSL_write");
        exit(EXIT_FAILURE);
    }

    // Read the server's response
    n = SSL_read(ssl, buf, sizeof(buf));
    if (n == -1) {
        perror("SSL_read");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid response: %s\n", buf);
        exit(EXIT_FAILURE);
    }

    // Send the STAT command
    sprintf(cmd, "STAT\r\n");
    if (SSL_write(ssl, cmd, strlen(cmd)) == -1) {
        perror("SSL_write");
        exit(EXIT_FAILURE);
    }

    // Read the server's response
    n = SSL_read(ssl, buf, sizeof(buf));
    if (n == -1) {
        perror("SSL_read");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid response: %s\n", buf);
        exit(EXIT_FAILURE);
    }

    // Print the number of messages
    int num_messages = atoi(buf + 4);
    printf("Number of messages: %d\n", num_messages);

    // Send the QUIT command
    sprintf(cmd, "QUIT\r\n");
    if (SSL_write(ssl, cmd, strlen(cmd)) == -1) {
        perror("SSL_write");
        exit(EXIT_FAILURE);
    }

    // Read the server's response
    n = SSL_read(ssl, buf, sizeof(buf));
    if (n == -1) {
        perror("SSL_read");
        exit(EXIT_FAILURE);
    }
    buf[n] = '\0';
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid response: %s\n", buf);
        exit(EXIT_FAILURE);
    }

    // Close the connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);

    return EXIT_SUCCESS;
}