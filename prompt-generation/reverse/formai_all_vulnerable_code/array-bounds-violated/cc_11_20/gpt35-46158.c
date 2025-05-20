//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 2048

void print_ssl_error(SSL *ssl, int r) {
    switch (SSL_get_error(ssl, r)) {
        case SSL_ERROR_NONE:
            break;
        case SSL_ERROR_ZERO_RETURN:
            fprintf(stderr, "SSL_connect: SSL_ERROR_ZERO_RETURN\n");
            exit(EXIT_FAILURE);
        case SSL_ERROR_SYSCALL:
            fprintf(stderr, "SSL_connect: SSL_ERROR_SYSCALL\n");
            exit(EXIT_FAILURE);
        case SSL_ERROR_SSL:
            fprintf(stderr, "SSL_connect: SSL_ERROR_SSL\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char recv_buf[BUF_SIZE], send_buf[BUF_SIZE], command[BUF_SIZE], username[BUF_SIZE], password[BUF_SIZE], email[BUF_SIZE];
    int recv_len, send_len, i, j, k;
    SSL_CTX *ctx;
    SSL *ssl;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(993); // IMAP over SSL default port

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Initialize SSL
    SSL_library_init();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ctx) {
        fprintf(stderr, "Failed to initialize SSL context\n");
        close(sock);
        exit(EXIT_FAILURE);
    }
    ssl = SSL_new(ctx);
    if (!ssl) {
        fprintf(stderr, "Failed to create SSL object\n");
        close(sock);
        SSL_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) != 1) {
        print_ssl_error(ssl, 0);
        close(sock);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }

    // Wait for server greeting
    recv_len = SSL_read(ssl, recv_buf, BUF_SIZE);
    if (recv_len <= 0) {
        fprintf(stderr, "Server closed connection\n");
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }
    recv_buf[recv_len] = '\0';
    fprintf(stdout, "%s", recv_buf);

    // Authenticate
    fprintf(stdout, "Username: ");
    fgets(username, BUF_SIZE, stdin);
    username[strcspn(username, "\r\n")] = '\0';
    fprintf(stdout, "Password: ");
    fgets(password, BUF_SIZE, stdin);
    password[strcspn(password, "\r\n")] = '\0';

    snprintf(send_buf, BUF_SIZE, "LOGIN %s %s\r\n", username, password);
    send_len = SSL_write(ssl, send_buf, strlen(send_buf));
    if (send_len <= 0) {
        fprintf(stderr, "Failed to send authentication message\n");
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }

    recv_len = SSL_read(ssl, recv_buf, BUF_SIZE);
    if (recv_len <= 0) {
        fprintf(stderr, "Server closed connection\n");
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        exit(EXIT_FAILURE);
    }
    recv_buf[recv_len] = '\0';
    fprintf(stdout, "%s", recv_buf);

    // Parse user commands
    while (1) {
        fprintf(stdout, "Command: ");
        fgets(command, BUF_SIZE, stdin);
        command[strcspn(command, "\r\n")] = '\0';

        if (strcasecmp(command, "logout") == 0) {
            snprintf(send_buf, BUF_SIZE, "LOGOUT\r\n");
            send_len = SSL_write(ssl, send_buf, strlen(send_buf));
            if (send_len <= 0) {
                fprintf(stderr, "Failed to send logout message\n");
                SSL_free(ssl);
                SSL_CTX_free(ctx);
                exit(EXIT_FAILURE);
            }
            break;
        } else if (strcasecmp(command, "list") == 0) {
            snprintf(send_buf, BUF_SIZE, "LIST \"\" *\r\n");
            send_len = SSL_write(ssl, send_buf, strlen(send_buf));
            if (send_len <= 0) {
                fprintf(stderr, "Failed to send list message\n");
                SSL_free(ssl);
                SSL_CTX_free(ctx);
                exit(EXIT_FAILURE);
            }

            recv_len = SSL_read(ssl, recv_buf, BUF_SIZE);
            if (recv_len <= 0) {
                fprintf(stderr, "Server closed connection\n");
                SSL_free(ssl);
                SSL_CTX_free(ctx);
                exit(EXIT_FAILURE);
            }
            recv_buf[recv_len] = '\0';
            fprintf(stdout, "%s", recv_buf);
        } else if (strcasecmp(command, "fetch") == 0) {
            fprintf(stdout, "Email ID: ");
            fgets(email, BUF_SIZE, stdin);
            email[strcspn(email, "\r\n")] = '\0';

            snprintf(send_buf, BUF_SIZE, "FETCH %s BODY[]\r\n", email);
            send_len = SSL_write(ssl, send_buf, strlen(send_buf));
            if (send_len <= 0) {
                fprintf(stderr, "Failed to send fetch message\n");
                SSL_free(ssl);
                SSL_CTX_free(ctx);
                exit(EXIT_FAILURE);
            }

            recv_len = SSL_read(ssl, recv_buf, BUF_SIZE);
            if (recv_len <= 0) {
                fprintf(stderr, "Server closed connection\n");
                SSL_free(ssl);
                SSL_CTX_free(ctx);
                exit(EXIT_FAILURE);
            }
            recv_buf[recv_len] = '\0';
            fprintf(stdout, "%s", recv_buf);
        } else {
            fprintf(stderr, "Invalid command\n");
        }
    }

    // Cleanup
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);
}