//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 4096

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void init_openssl() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
}

void cleanup_openssl() {
    EVP_cleanup();
}

SSL_CTX *create_context() {
    SSL_CTX *ctx;
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        die("Unable to create SSL context");
    }
    return ctx;
}

void configure_context(SSL_CTX *ctx) {
    SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2);
}

int connect_to_server(const char *hostname) {
    struct sockaddr_in server_addr;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("Could not create socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        die("Invalid address");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection failed");
    }

    return sockfd;
}

void send_command(SSL *ssl, const char *cmd) {
    SSL_write(ssl, cmd, strlen(cmd));
}

void read_response(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    int bytes;

    while (1) {
        bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1);
        if (bytes <= 0) {
            break;
        }
        buffer[bytes] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL || strstr(buffer, "NO") != NULL || strstr(buffer, "BAD") != NULL) {
            break; // Stop reading on end of command response
        }
    }
}

void login(SSL *ssl, const char *username, const char *password) {
    char cmd[BUFFER_SIZE];
    sprintf(cmd, "A001 LOGIN %s %s\r\n", username, password);
    send_command(ssl, cmd);
    read_response(ssl);
}

void fetch_mailboxes(SSL *ssl) {
    char cmd[BUFFER_SIZE];
    sprintf(cmd, "A002 LIST \"\" *\r\n");
    send_command(ssl, cmd);
    read_response(ssl);
}

void select_mailbox(SSL *ssl, const char *mailbox) {
    char cmd[BUFFER_SIZE];
    sprintf(cmd, "A003 SELECT \"%s\"\r\n", mailbox);
    send_command(ssl, cmd);
    read_response(ssl);
}

void fetch_emails(SSL *ssl) {
    char cmd[BUFFER_SIZE];
    sprintf(cmd, "A004 FETCH 1:* (ENVELOPE)\r\n");
    send_command(ssl, cmd);
    read_response(ssl);
}

void logout(SSL *ssl) {
    send_command(ssl, "A005 LOGOUT\r\n");
    read_response(ssl);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    init_openssl();
    SSL_CTX *ctx = create_context();
    configure_context(ctx);

    int sockfd = connect_to_server(hostname);
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s.\n", hostname);
    
    login(ssl, username, password);
    fetch_mailboxes(ssl);

    char mailbox[BUFFER_SIZE];
    printf("Enter mailbox to select: ");
    scanf("%s", mailbox);
    select_mailbox(ssl, mailbox);
    fetch_emails(ssl);

    logout(ssl);
    
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    cleanup_openssl();
    return 0;
}