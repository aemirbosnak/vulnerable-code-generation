//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_BUFFER_SIZE 1024
#define SERVER_PORT 993
#define SERVER_ADDR "imap.gmail.com"

void handle_error(const char *file, int lineno, const char *msg)
{
    fprintf(stderr, "ERROR: %s:%d: %s\n", file, lineno, msg);
    exit(EXIT_FAILURE);
}

SSL_CTX* initialize_ssl_context()
{
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    SSL_CTX *ssl_context;
    const SSL_METHOD *ssl_method = TLSv1_2_client_method();
    ssl_context = SSL_CTX_new(ssl_method);
    if (ssl_context == NULL) handle_error(__FILE__, __LINE__, "Could not create SSL context.");
    return ssl_context;
}

void print_incoming_message(SSL *ssl)
{
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received = SSL_read(ssl, buffer, MAX_BUFFER_SIZE);
    if (bytes_received < 0) handle_error(__FILE__, __LINE__, "Could not read data from socket.");
    if (bytes_received == 0) handle_error(__FILE__, __LINE__, "Server disconnected.");
    printf("Incoming message: %s\n", buffer);
}

int main(int argc, char *argv[])
{
    SSL_CTX *ssl_ctx = initialize_ssl_context();
    SSL *ssl = NULL;
    int sock = -1;
    struct sockaddr_in server_addr;
    char server_reply[MAX_BUFFER_SIZE];
    char buffer[MAX_BUFFER_SIZE];
    char username[MAX_BUFFER_SIZE];
    char password[MAX_BUFFER_SIZE];
    printf("Enter your email address: ");
    fgets(username, MAX_BUFFER_SIZE, stdin);
    printf("Enter your password: ");
    fgets(password, MAX_BUFFER_SIZE, stdin);
    username[strlen(username)-1] = '\0';
    password[strlen(password)-1] = '\0';
    strcpy(buffer, "a001 LOGIN ");
    strcat(buffer, username);
    strcat(buffer, " ");
    strcat(buffer, password);
    strcat(buffer, "\r\n");
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) handle_error(__FILE__, __LINE__, "Could not create socket.");
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) handle_error(__FILE__, __LINE__, "Could not connect to server.");
    ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) < 0) handle_error(__FILE__, __LINE__, "Could not establish SSL connection.");
    printf("Successfully connected to server.\n");
    if (SSL_write(ssl, buffer, strlen(buffer)) < 0) handle_error(__FILE__, __LINE__, "Could not send message to server.");
    memset(server_reply, 0, MAX_BUFFER_SIZE);
    int bytes_received = SSL_read(ssl, server_reply, MAX_BUFFER_SIZE);
    if (bytes_received < 0) handle_error(__FILE__, __LINE__, "Could not read data from socket.");
    if (bytes_received == 0) handle_error(__FILE__, __LINE__, "Server disconnected.");
    if (strstr(server_reply, "OK") == NULL) handle_error(__FILE__, __LINE__, "Server login failed.");
    printf("Successfully logged in.\n");
    memset(buffer, 0, MAX_BUFFER_SIZE);
    strcpy(buffer, "a002 SELECT INBOX\r\n");
    if (SSL_write(ssl, buffer, strlen(buffer)) == -1) handle_error(__FILE__, __LINE__, "Could not send SELECT command to server.");
    memset(server_reply, 0, MAX_BUFFER_SIZE);
    bytes_received = SSL_read(ssl, server_reply, MAX_BUFFER_SIZE);
    if (bytes_received < 0) handle_error(__FILE__, __LINE__, "Could not read data from socket.");
    if (bytes_received == 0) handle_error(__FILE__, __LINE__, "Server disconnected.");
    printf("Server replied: %s\n", server_reply);
    while (1)
    {
        printf("Enter the command to be sent to server (type 'exit' to finish): ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        buffer[strlen(buffer)-1] = '\0';
        if (strcmp(buffer, "exit") == 0) break;
        if (SSL_write(ssl, buffer, strlen(buffer)) < 0) handle_error(__FILE__, __LINE__, "Could not send message to server.");
        print_incoming_message(ssl);
    }
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sock);
    exit(EXIT_SUCCESS);
}