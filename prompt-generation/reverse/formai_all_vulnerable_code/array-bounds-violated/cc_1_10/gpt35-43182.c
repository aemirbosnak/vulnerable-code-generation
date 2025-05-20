//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    char *server_address = "mail.example.com";
    char *username = "example_user";
    char *password = "example_password";
    int port = 993;

    // Create IMAP connection
    int sock;
    struct sockaddr_in server;
    struct hostent *host;
    SSL_CTX *ctx;
    SSL *ssl;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    host = gethostbyname(server_address);
    if (host == NULL) {
        perror("Error resolving hostname");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = *(long*)host->h_addr;

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Create SSL context and setup connection
    SSL_library_init();
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        perror("Error creating SSL context");
        exit(1);
    }

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        perror("Error establishing SSL connection");
        exit(1);
    }

    // Authenticate user
    char buffer[MAX_BUFFER];
    int len;

    len = snprintf(buffer, MAX_BUFFER, "LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, buffer, len);

    len = SSL_read(ssl, buffer, MAX_BUFFER-1);
    buffer[len] = '\0';

    if (strstr(buffer, "OK") == NULL) {
        printf("Error logging in: %s", buffer);
        exit(1);
    }

    // List all folders
    len = snprintf(buffer, MAX_BUFFER, "LIST \"\" *\r\n");
    SSL_write(ssl, buffer, len);

    len = SSL_read(ssl, buffer, MAX_BUFFER-1);
    buffer[len] = '\0';

    printf("Folders:\n%s\n", buffer);

    // Select INBOX folder and list messages
    len = snprintf(buffer, MAX_BUFFER, "SELECT INBOX\r\n");
    SSL_write(ssl, buffer, len);

    len = SSL_read(ssl, buffer, MAX_BUFFER-1);
    buffer[len] = '\0';

    printf("Messages in INBOX:\n%s\n", buffer);

    // Logout and close connection
    len = snprintf(buffer, MAX_BUFFER, "LOGOUT\r\n");
    SSL_write(ssl, buffer, len);

    len = SSL_read(ssl, buffer, MAX_BUFFER-1);
    buffer[len] = '\0';

    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock);

    return 0;
}