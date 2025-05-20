//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }
    char *hostname = argv[1];
    int port = 993;
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd;

    // Initialize OpenSSL
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    // Create SSL context
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (!ctx) {
        printf("Error creating SSL context.\n");
        return 1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket.\n");
        return 1;
    }

    // Set server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(hostname);
    serv_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server.\n");
        return 1;
    }

    // Create SSL object
    ssl = SSL_new(ctx);
    if (!ssl) {
        printf("Error creating SSL object.\n");
        return 1;
    }

    // Connect SSL object to socket
    SSL_set_fd(ssl, sockfd);

    // Start SSL handshake
    if (SSL_connect(ssl) != 1) {
        printf("Error starting SSL handshake.\n");
        return 1;
    }

    // Receive server greeting
    char buffer[BUFFER_SIZE + 1];
    int bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Login
    char login_command[BUFFER_SIZE];
    printf("Username:");
    char username[BUFFER_SIZE];
    fgets(username, BUFFER_SIZE, stdin);
    char *pos;
    if ((pos = strchr(username, '\n')) != NULL) {
        *pos = '\0';
    }
    sprintf(login_command, "LOGIN %s ", username);
    SSL_write(ssl, login_command, strlen(login_command));
    char password[BUFFER_SIZE];
    printf("Password:");
    fgets(password, BUFFER_SIZE, stdin);
    if ((pos = strchr(password, '\n')) != NULL) {
        *pos = '\0';
    }
    SSL_write(ssl, password, strlen(password));
    bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Select mailbox
    char select_command[BUFFER_SIZE];
    sprintf(select_command, "SELECT INBOX\r\n");
    SSL_write(ssl, select_command, strlen(select_command));
    bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // List messages
    char list_command[BUFFER_SIZE];
    sprintf(list_command, "UID SEARCH ALL\r\n");
    SSL_write(ssl, list_command, strlen(list_command));
    bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Logout
    char logout_command[BUFFER_SIZE];
    sprintf(logout_command, "LOGOUT\r\n");
    SSL_write(ssl, logout_command, strlen(logout_command));
    bytes_received = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Clean up
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}