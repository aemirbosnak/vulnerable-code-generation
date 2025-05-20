//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFSIZE 1024

bool init_openssl(void);
void cleanup_openssl(void);
SSL_CTX *create_context(void);
void configure_context(SSL_CTX *ctx);
int valid_hostname(const char *hostname, const char *cert);

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [hostname] [port] [username]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *port = argv[2];
    char *username = argv[3];
    char password[50];

    printf("Enter your password: ");

    if (fgets(password, 50, stdin) == NULL) {
        fprintf(stderr, "Error reading password\n");
        exit(EXIT_FAILURE);
    }

    // Remove '\n' character from password if present
    size_t len = strlen(password);
    if (password[len-1] == '\n') password[len-1] = '\0';

    printf("Establishing connection to server %s:%s...\n", hostname, port);

    // Create TCP socket for IMAP
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get host information
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Create server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    serv_addr.sin_addr = *((struct in_addr *)he->h_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    SSL_CTX *ctx;

    init_openssl();
    ctx = create_context();
    configure_context(ctx);

    // Create new SSL connection for socket
    SSL *ssl = SSL_new(ctx);

    // Assign the socket into the SSL structure (SSL/TLS connection)
    SSL_set_fd(ssl, sockfd);

    // Perform SSL/TLS handshake and get result
    int res = SSL_connect(ssl);
    if (res <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    printf("Connected!\n");

    char buf[BUFSIZE];
    size_t len_read;
    ssize_t len_sent;
    char cmd[100];
    char auth[100];
    char respcode[100];

    // Read greeting from server
    len_read = SSL_read(ssl, buf, BUFSIZE-1);
    if (len_read <= 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buf[len_read] = '\0';
    printf("%s", buf);

    // Send username to server
    sprintf(cmd, "a001 LOGIN %s %s\r\n", username, password);
    len_sent = SSL_write(ssl, cmd, strlen(cmd));
    if (len_sent <= 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read server response
    len_read = SSL_read(ssl, buf, BUFSIZE-1);
    if (len_read <= 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buf[len_read] = '\0';
    printf("%s", buf);

    // Check if login was successful
    sscanf(buf, "%s %s", respcode, auth);

    if (strcmp(respcode, "a001") == 0 && strcmp(auth, "OK") == 0) {
        printf("Login successful!\n");

        // Send command to list all mailboxes
        sprintf(cmd, "a002 LIST \"\" *\r\n");
        len_sent = SSL_write(ssl, cmd, strlen(cmd));
        if (len_sent <= 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Read server response
        len_read = SSL_read(ssl, buf, BUFSIZE-1);
        if (len_read <= 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        buf[len_read] = '\0';
        printf("%s", buf);
    }
    else {
        fprintf(stderr, "Login failed!\n");
        exit(EXIT_FAILURE);
    }

    // Free SSL/TLS resources and close connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    cleanup_openssl();

    return 0;
}

bool init_openssl(void)
{
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    return true;
}

void cleanup_openssl(void)
{
    ERR_free_strings();
    EVP_cleanup();
}

SSL_CTX *create_context(void)
{
    const SSL_METHOD *method;
    SSL_CTX *ctx;

    method = SSLv23_client_method();
    ctx = SSL_CTX_new(method);

    if (!ctx) {
        perror("Unable to create SSL context");
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    return ctx;
}

void configure_context(SSL_CTX *ctx)
{
    SSL_CTX_set_cipher_list(ctx, "DEFAULT");
}

int valid_hostname(const char *hostname, const char *cert_name)
{
    return strcasecmp(hostname, cert_name) == 0;
}