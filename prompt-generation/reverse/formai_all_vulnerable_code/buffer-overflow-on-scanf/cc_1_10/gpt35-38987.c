//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port;
    char username[MAX_SIZE], password[MAX_SIZE], server[MAX_SIZE], command[MAX_SIZE];
    socklen_t len;
    struct sockaddr_in serv_addr;
    struct hostent *he;
    SSL_CTX *ctx;
    SSL *ssl;

    // Get user input
    printf("Enter your email username: ");
    scanf("%s", username);
    printf("Enter your email password: ");
    scanf("%s", password);
    printf("Enter your email server: ");
    scanf("%s", server);
    printf("Enter the server port number: ");
    scanf("%d", &port);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR: Failed to create socket.\n");
        exit(1);
    }

    // Get server IP address
    he = gethostbyname(server);
    if (he == NULL) {
        printf("ERROR: Failed to get server hostname.\n");
        exit(1);
    }

    // Set server connection details
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *((struct in_addr*)he->h_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("ERROR: Failed to connect to server.\n");
        exit(1);
    }

    // Initialize SSL context and connection
    SSL_library_init();
    ctx = SSL_CTX_new(SSLv23_client_method());
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) < 0) {
        printf("ERROR: Failed to establish SSL connection.\n");
        exit(1);
    }

    // Authenticate user
    sprintf(command, "1 LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, command, strlen(command));
    char buf[MAX_SIZE];
    SSL_read(ssl, buf, MAX_SIZE);

    // Check for authentication success
    if (strstr(buf, "OK LOGIN completed") != NULL) {
        printf("Authentication successful!\n");

        // Display user's mailbox info
        sprintf(command, "1 LIST \"\" *\r\n");
        SSL_write(ssl, command, strlen(command));
        SSL_read(ssl, buf, MAX_SIZE);
        printf("%s", buf);
    }
    else {
        printf("Authentication failed!\n");
    }

    // Close SSL connection and socket
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}