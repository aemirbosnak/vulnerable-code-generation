//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

// Global variables
int sockfd;
SSL_CTX* ctx;

// Function to read data from socket
int read_socket(int sockfd, char* buf) {
    memset(buf, 0, BUFSIZ);     // Clear buffer before reading
    return recv(sockfd, buf, BUFSIZ, 0);
}

int main(int argc, char** argv) {
    // Check for input arguments
    if (argc < 3) {
        printf("Usage: ./client <hostname> <port>\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Initialize SSL library
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    // Create SSL context
    ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        printf("Failed to create SSL context\n");
        exit(1);
    }

    // Connect to server
    struct hostent* host_info = gethostbyname(argv[1]);
    if (host_info == NULL) {
        printf("Failed to get host info\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *((struct in_addr*)host_info->h_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Connect SSL session
    SSL* ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) < 0) {
        printf("Failed to connect SSL session\n");
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    // Read welcome message from server
    char buf[BUFSIZ];
    int bytes_read = read_socket(sockfd, buf);
    if (bytes_read < 0) {
        perror("Failed to read from socket");
        exit(1);
    }
    printf("%s", buf);

    // Send login command
    char login_command[BUFSIZ];
    char username[BUFSIZ];
    char password[BUFSIZ];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    sprintf(login_command, "LOGIN %s %s\n", username, password);
    SSL_write(ssl, login_command, strlen(login_command));

    // Read login response from server
    bytes_read = read_socket(sockfd, buf);
    if (bytes_read < 0) {
        perror("Failed to read from socket");
        exit(1);
    }
    printf("%s", buf);

    // Send select command to choose mailbox
    char mailbox[BUFSIZ];
    printf("Select mailbox: ");
    scanf("%s", mailbox);
    char select_command[BUFSIZ];
    sprintf(select_command, "SELECT %s\n", mailbox);
    SSL_write(ssl, select_command, strlen(select_command));

    // Read mailbox status from server
    bytes_read = read_socket(sockfd, buf);
    if (bytes_read < 0) {
        perror("Failed to read from socket");
        exit(1);
    }
    printf("%s", buf);

    // Send fetch command to retrieve emails
    char fetch_command[BUFSIZ];
    sprintf(fetch_command, "FETCH 1:* FULL\n");
    SSL_write(ssl, fetch_command, strlen(fetch_command));

    // Read email content from server
    bytes_read = read_socket(sockfd, buf);
    if (bytes_read < 0) {
        perror("Failed to read from socket");
        exit(1);
    }
    printf("%s", buf);

    // Logout from server
    SSL_write(ssl, "LOGOUT\n", strlen("LOGOUT\n"));
    bytes_read = read_socket(sockfd, buf);
    if (bytes_read < 0) {
        perror("Failed to read from socket");
        exit(1);
    }
    printf("%s", buf);

    // Close SSL session and socket
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return 0;
}