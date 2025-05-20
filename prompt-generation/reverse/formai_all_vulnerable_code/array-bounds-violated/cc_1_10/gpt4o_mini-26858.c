//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "imap.example.com"
#define PORT 993

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

SSL_CTX *initialize_ssl_context() {
    SSL_CTX *ctx;
    const SSL_METHOD *method;

    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    method = SSLv23_client_method();
    ctx = SSL_CTX_new(method);
    if (!ctx) {
        handle_error("Unable to create SSL context");
    }
    return ctx;
}

int establish_connection(const char *server_ip, int port, SSL_CTX *ctx) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("Unable to create socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        handle_error("SSL connection failed");
    }
    
    return sock;
}

void send_command(SSL *ssl, const char *command) {
    SSL_write(ssl, command, strlen(command));
    SSL_write(ssl, "\r\n", 2);
}

void receive_response(SSL *ssl) {
    char buffer[1024];
    int bytes;

    while ((bytes = SSL_read(ssl, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes] = '\0';
        printf("%s", buffer);
        if (strstr(buffer, "OK") != NULL) break;
    }
}

void fetch_mailboxes(SSL *ssl) {
    send_command(ssl, "A001 LIST \"\" \"*\"");
    receive_response(ssl);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *username = argv[1];
    const char *password = argv[2];

    SSL_CTX *ctx = initialize_ssl_context();
    int sock = establish_connection(SERVER, PORT, ctx);

    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    SSL_connect(ssl);

    // Send the login command
    char login_command[256];
    snprintf(login_command, sizeof(login_command), "A000 LOGIN \"%s\" \"%s\"", username, password);
    send_command(ssl, login_command);
    receive_response(ssl);

    // Fetch the list of mailboxes
    fetch_mailboxes(ssl);

    // Send the logout command
    send_command(ssl, "A002 LOGOUT");
    receive_response(ssl);

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    EVP_cleanup();

    return 0;
}