//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>

#define POP3_PORT 995
#define BUFF_SIZE 1024

int main(int argc, char **argv) {
    // Check if hostname is provided
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    int sockfd;
    struct hostent *host;
    struct sockaddr_in addr;
    char buffer[BUFF_SIZE + 1] = {0};
    int bytes;

    // Get host IP address
    if ((host = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set socket address
    addr.sin_family = AF_INET;
    addr.sin_port = htons(POP3_PORT);
    addr.sin_addr = *((struct in_addr *)host->h_addr);

    // Connect to POP3 server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Create SSL context
    SSL_CTX *ctx;
    SSL *ssl;
    const SSL_METHOD *method;
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    method = SSLv23_client_method();
    ctx = SSL_CTX_new(method);

    // Create SSL socket
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    // Connect to POP3 server using SSL socket
    if (SSL_connect(ssl) <= 0) {
        perror("SSL_connect");
        exit(EXIT_FAILURE);
    }

    // Receive banner from POP3 server
    if ((bytes = SSL_read(ssl, buffer, BUFF_SIZE)) <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[bytes] = '\0';
    printf("%s", buffer);

    // Send user command to POP3 server
    char user_cmd[BUFF_SIZE];
    printf("User: ");
    fgets(user_cmd, BUFF_SIZE, stdin);
    user_cmd[strcspn(user_cmd, "\n")] = '\0';
    strcat(user_cmd, "\r\n");
    SSL_write(ssl, user_cmd, strlen(user_cmd));

    // Receive response from POP3 server
    if ((bytes = SSL_read(ssl, buffer, BUFF_SIZE)) <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[bytes] = '\0';
    printf("%s", buffer);

    // Send pass command to POP3 server
    char pass_cmd[BUFF_SIZE];
    printf("Password: ");
    fgets(pass_cmd, BUFF_SIZE, stdin);
    pass_cmd[strcspn(pass_cmd, "\n")] = '\0';
    strcat(pass_cmd, "\r\n");
    SSL_write(ssl, pass_cmd, strlen(pass_cmd));

    // Receive response from POP3 server
    if ((bytes = SSL_read(ssl, buffer, BUFF_SIZE)) <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[bytes] = '\0';
    printf("%s", buffer);

    // Send list command to POP3 server
    char list_cmd[] = "LIST\r\n";
    SSL_write(ssl, list_cmd, strlen(list_cmd));

    // Receive response from POP3 server
    if ((bytes = SSL_read(ssl, buffer, BUFF_SIZE)) <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[bytes] = '\0';
    printf("%s", buffer);

    // Send quit command to POP3 server
    char quit_cmd[] = "QUIT\r\n";
    SSL_write(ssl, quit_cmd, strlen(quit_cmd));

    // Receive response from POP3 server
    if ((bytes = SSL_read(ssl, buffer, BUFF_SIZE)) <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[bytes] = '\0';
    printf("%s", buffer);

    // Close SSL socket and socket
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return EXIT_SUCCESS;
}