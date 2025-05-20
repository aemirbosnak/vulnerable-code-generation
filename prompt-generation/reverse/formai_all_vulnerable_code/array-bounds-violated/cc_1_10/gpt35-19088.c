//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(void) {

    // Set up connection details for IMAP server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(993);
    struct hostent *he = gethostbyname("imap.example.com");
    memcpy(&server_address.sin_addr, he->h_addr_list[0], he->h_length);

    // Create socket and set SSL context
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        handle_error("Error creating socket");
    }
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        handle_error("Error creating SSL context");
    }
    SSL *ssl = SSL_new(ctx);
    if (ssl == NULL) {
        handle_error("Error creating SSL object");
    }
    SSL_set_fd(ssl, client_socket);

    // Connect to server and set up IMAP authentication
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        handle_error("Error connecting to server");
    }
    if (SSL_connect(ssl) != 1) {
        handle_error("Error establishing SSL connection");
    }
    char buffer[BUFFER_SIZE];
    int num_bytes = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[num_bytes] = '\0';
    printf("Server says: %s\n", buffer);

    // Send login credentials to server
    char *login = "LOGIN username@example.com password\r\n";
    if (SSL_write(ssl, login, strlen(login)) < 0) {
        handle_error("Error sending login credentials");
    }
    num_bytes = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[num_bytes] = '\0';
    printf("Server says: %s\n", buffer);

    // Send IMAP command to list folders
    char *list_command = "LIST \"\" \"*\"\r\n";
    if (SSL_write(ssl, list_command, strlen(list_command)) < 0) {
        handle_error("Error sending list command");
    }
    num_bytes = SSL_read(ssl, buffer, BUFFER_SIZE);
    buffer[num_bytes] = '\0';
    printf("Server says: %s\n", buffer);

    // Terminate SSL connection and close socket
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(client_socket);

    return 0;
}