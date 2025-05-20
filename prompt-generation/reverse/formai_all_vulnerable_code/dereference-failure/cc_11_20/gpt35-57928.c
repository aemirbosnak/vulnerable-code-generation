//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <resolv.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s hostname port username password\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    // Initialize SSL library
    SSL_library_init();
    SSL_CTX *ssl_context = SSL_CTX_new(SSLv23_client_method());
    if (ssl_context == NULL) {
        fprintf(stderr, "Failed to create SSL context.\n");
        return 1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to create socket.\n");
        return 1;
    }

    // Resolve hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Failed to resolve hostname: %s\n", hostname);
        return 1;
    }

    // Connect to server
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    bcopy((char *) host->h_addr, (char *) &server_addr.sin_addr.s_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Failed to connect to server.\n");
        return 1;
    }

    // Create SSL connection
    SSL *ssl = SSL_new(ssl_context);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        fprintf(stderr, "Failed to establish SSL connection: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return 1;
    }

    // Send login command
    char login_cmd[BUF_SIZE];
    snprintf(login_cmd, BUF_SIZE, "LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, login_cmd, strlen(login_cmd));

    // Read response
    char buf[BUF_SIZE];
    SSL_read(ssl, buf, BUF_SIZE);

    // Check response
    if (strstr(buf, "OK") == NULL) {
        fprintf(stderr, "Failed to login: %s\n", buf);
        return 1;
    }

    // Send list command
    SSL_write(ssl, "LIST \"\" \"*\"\r\n", strlen("LIST \"\" \"*\"\r\n"));

    // Read response
    bzero(buf, BUF_SIZE);
    SSL_read(ssl, buf, BUF_SIZE);

    // Check response
    if (strstr(buf, "OK") == NULL) {
        fprintf(stderr, "Failed to list mailboxes: %s\n", buf);
        return 1;
    }

    // Print mailboxes
    char *mailbox_start = strchr(buf, '(');
    char *mailbox_end = strchr(buf, ')');
    if (mailbox_start != NULL && mailbox_end != NULL) {
        *mailbox_end = '\0';
        char *mailbox_str = mailbox_start + 1;

        printf("Mailboxes:\n");

        char *mailbox = strtok(mailbox_str, " ");
        while (mailbox != NULL) {
            printf("- %s\n", mailbox);
            mailbox = strtok(NULL, " ");
        }
    }

    // Cleanup and exit
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_context);
    close(sockfd);

    return 0;
}