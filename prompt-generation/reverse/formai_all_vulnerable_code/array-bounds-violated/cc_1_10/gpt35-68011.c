//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Command line check
    if (argc != 4) {
        printf("Usage: %s <server> <port> <user email>\n", argv[0]);
        return 1;
    }
    
    char *server = argv[1];
    char *port = argv[2];
    char *email = argv[3];
    
    // Connecting to the server
    int client_sock;
    struct sockaddr_in server_addr;
    struct hostent *server_host;
    server_host = gethostbyname(server);
    if ((client_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        printf("Socket creation failed\n");
        return 1;
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr = *((struct in_addr *)server_host->h_addr);
    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed\n");
        return 1;
    }
    
    // Connection successful, now SSL setup
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_CTX *ssl_context = SSL_CTX_new(TLS_client_method());
    if (ssl_context == NULL) {
        printf("SSL context creation failed\n");
        return 1;
    }
    SSL *ssl_connection = SSL_new(ssl_context);
    SSL_set_fd(ssl_connection, client_sock);
    if (SSL_connect(ssl_connection) != 1) {
        printf("SSL connection failed\n");
        return 1;
    }
    
    // Logging in
    char buffer[BUFFER_SIZE];
    int recv_count;
    recv_count = SSL_read(ssl_connection, buffer, BUFFER_SIZE);
    buffer[recv_count] = '\0';
    printf("%s", buffer);
    sprintf(buffer, "a001 LOGIN %s\r\n", email);
    SSL_write(ssl_connection, buffer, strlen(buffer));
    recv_count = SSL_read(ssl_connection, buffer, BUFFER_SIZE);
    buffer[recv_count] = '\0';
    printf("%s", buffer);
    
    // Listing all mails
    sprintf(buffer, "a002 LIST \"\" *\r\n");
    SSL_write(ssl_connection, buffer, strlen(buffer));
    recv_count = SSL_read(ssl_connection, buffer, BUFFER_SIZE);
    buffer[recv_count] = '\0';
    printf("%s", buffer);
    
    // Retrieving mail
    sprintf(buffer, "a003 EXAMINE INBOX\r\n");
    SSL_write(ssl_connection, buffer, strlen(buffer));
    recv_count = SSL_read(ssl_connection, buffer, BUFFER_SIZE);
    buffer[recv_count] = '\0';
    printf("%s", buffer);
    sprintf(buffer, "a004 FETCH 1 BODY[TEXT]\r\n");
    SSL_write(ssl_connection, buffer, strlen(buffer));
    recv_count = SSL_read(ssl_connection, buffer, BUFFER_SIZE);
    buffer[recv_count] = '\0';
    printf("%s", buffer);
    
    // Logging out
    sprintf(buffer, "a005 LOGOUT\r\n");
    SSL_write(ssl_connection, buffer, strlen(buffer));
    recv_count = SSL_read(ssl_connection, buffer, BUFFER_SIZE);
    buffer[recv_count] = '\0';
    printf("%s", buffer);
    
    // Cleaning up
    SSL_shutdown(ssl_connection);
    SSL_free(ssl_connection);
    SSL_CTX_free(ssl_context);
    close(client_sock);
    
    return 0;
}