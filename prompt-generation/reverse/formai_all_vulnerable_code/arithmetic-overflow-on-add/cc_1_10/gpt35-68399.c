//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "imap.gmail.com"
#define PORT 993

int receive_data(SSL *ssl) {
    int bytes_received, total_bytes_received = 0;
    char buffer[1024];
    do {
        bytes_received = SSL_read(ssl, buffer, sizeof(buffer));
        if (bytes_received > 0) {
            total_bytes_received += bytes_received;
            printf("%s", buffer);
        }
        memset(buffer, 0, sizeof(buffer));
    } while (bytes_received > 0);
    return total_bytes_received;
}

int main() {
    SSL_library_init(); // Initialize OpenSSL library
    SSL_CTX *ssl_ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ssl_ctx) {
        printf("Error: SSL context could not be created\n");
        return 1;
    }
    SSL *ssl = SSL_new(ssl_ctx);
    if (!ssl) {
        printf("Error: SSL could not be created\n");
        return 1;
    }
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Socket could not be created\n");
        return 1;
    }
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER);
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Connection could not be established\n");
        return 1;
    }
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) < 0) {
        printf("Error: SSL connection could not be established\n");
        return 1;
    }
    receive_data(ssl); // Receive server welcome message
    SSL_write(ssl, "1 LOGIN your_email_address your_password\n", strlen("1 LOGIN your_email_address your_password\n"));
    receive_data(ssl); // Receive login response
    SSL_write(ssl, "2 SELECT INBOX\n", strlen("2 SELECT INBOX\n"));
    receive_data(ssl); // Receive mailbox selection response
    SSL_write(ssl, "3 LOGOUT\n", strlen("3 LOGOUT\n"));
    receive_data(ssl); // Receive logout response
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sock);
    return 0;
}