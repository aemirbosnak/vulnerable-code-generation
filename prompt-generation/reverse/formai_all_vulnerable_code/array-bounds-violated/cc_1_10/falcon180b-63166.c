//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFFER_SIZE 1024
#define IMAP_PORT 993

SSL_CTX *ssl_ctx;
SSL *ssl;
BIO *net_bio;
int net_socket;

void init_ssl() {
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    ssl_ctx = SSL_CTX_new(TLSv1_2_client_method());
    SSL_CTX_set_options(ssl_ctx, SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);
    ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, net_socket);
    net_bio = BIO_new_socket(net_socket, BIO_NOCLOSE);
    SSL_set_bio(ssl, net_bio, net_bio);
    SSL_connect(ssl);
    if (SSL_get_verify_result(ssl)!= X509_V_OK) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }
}

void send_command(const char *command) {
    SSL_write(ssl, command, strlen(command));
}

int receive_response() {
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received = SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    if (bytes_received <= 0) {
        int ssl_error = SSL_get_error(ssl, bytes_received);
        if (ssl_error == SSL_ERROR_WANT_READ) {
            return 0;
        } else if (ssl_error == SSL_ERROR_WANT_WRITE) {
            return 1;
        } else {
            ERR_print_errors_fp(stderr);
            exit(1);
        }
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
    return 0;
}

int main() {
    net_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (net_socket == -1) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "imap.gmail.com", &server_addr.sin_addr);
    server_addr.sin_port = htons(IMAP_PORT);
    if (connect(net_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }
    init_ssl();
    send_command("CAPABILITY");
    while (1) {
        int result = receive_response();
        if (result == 1) {
            send_command("OK");
        }
    }
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(net_socket);
    return 0;
}