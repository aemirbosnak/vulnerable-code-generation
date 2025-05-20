//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SERVER "pop.your-email-provider.com"
#define PORT 995
#define BUFFER_SIZE 1024

void ssl_error() {
    ERR_print_errors_fp(stderr);
    abort();
}

void pop3_send_recv(SSL *ssl, const char *msg, char *response) {
    SSL_write(ssl, msg, strlen(msg));
    SSL_read(ssl, response, BUFFER_SIZE);
}

void list_messages(SSL *ssl) {
    char response[BUFFER_SIZE];
    pop3_send_recv(ssl, "STAT\r\n", response);
    printf("%s", response);

    // Fetch individual message
    printf("Enter the message number to retrieve: ");
    int msg_num;
    scanf("%d", &msg_num);
    snprintf(response, sizeof(response), "RETR %d\r\n", msg_num);
    pop3_send_recv(ssl, response, response);
    printf("%s\n", response);
}

int main() {
    SSL_CTX *ctx;
    SSL *ssl;
    int sock;
    struct sockaddr_in server_addr;

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        ssl_error();
    }

    // Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("YOUR_SERVER_IP_ADDRESS");

    // Connecting to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return -1;
    }

    // Establish SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        ssl_error();
    }

    char response[BUFFER_SIZE];

    // Read server's greeting
    SSL_read(ssl, response, BUFFER_SIZE);
    printf("Server: %s\n", response);

    // User Authentication
    char username[100], password[100];
    printf("Enter your email username: ");
    scanf("%s", username);
    printf("Enter your email password: ");
    scanf("%s", password);

    char auth_command[BUFFER_SIZE];
    snprintf(auth_command, sizeof(auth_command), "USER %s\r\n", username);
    pop3_send_recv(ssl, auth_command, response);
    printf("%s", response);

    snprintf(auth_command, sizeof(auth_command), "PASS %s\r\n", password);
    pop3_send_recv(ssl, auth_command, response);
    printf("%s", response);

    list_messages(ssl);

    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sock);
    SSL_CTX_free(ctx);
    return 0;
}