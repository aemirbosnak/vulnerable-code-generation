//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024
#define SERVER "pop3.example.com"
#define PORT 995

SSL_CTX *ctx;
SSL *ssl;
int sock;

void init_ssl() {
    SSL_library_init();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }
    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }
    SSL_set_fd(ssl, sock);
}

void connect_to_server() {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }
}

void send_command(char *cmd) {
    SSL_write(ssl, cmd, strlen(cmd));
}

void receive_response() {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE - 1);
    if (bytes_received <= 0) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("%s\n", buffer);
}

int main() {
    init_ssl();
    connect_to_server();

    send_command("USER username");
    receive_response();

    send_command("PASS password");
    receive_response();

    send_command("STAT");
    receive_response();

    close(sock);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    return 0;
}