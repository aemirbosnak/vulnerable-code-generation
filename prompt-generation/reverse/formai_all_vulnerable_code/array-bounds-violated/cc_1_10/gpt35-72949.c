//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024
#define IMAP_PORT 993

void handle_error(const char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char* server = argv[1];
    const char* username = argv[2];
    const char* password = argv[3];
    
    // Initialize OpenSSL
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    
    // Create TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == -1) {
        handle_error("Failed to create socket");
    }
    
    // Resolve server address
    struct hostent* server_ent = gethostbyname(server);
    if (server_ent == NULL) {
        handle_error("Failed to resolve server address");
    }
    
    // Create address structure and connect
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, server_ent->h_addr, server_ent->h_length);
    
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        handle_error("Failed to connect to server");
    }
    
    // Create SSL context and SSL object
    SSL_CTX* ssl_ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ssl_ctx == NULL) {
        handle_error("Failed to create SSL context");
    }
    SSL* ssl = SSL_new(ssl_ctx);
    if (ssl == NULL) {
        handle_error("Failed to create SSL object");
    }
    
    // Attach SSL object to socket
    if (SSL_set_fd(ssl, sockfd) == 0) {
        handle_error("Failed to attach SSL object to socket");
    }
    
    // Initialize SSL handshake
    if (SSL_connect(ssl) == -1) {
        handle_error("Failed to initialize SSL handshake");
    }
    
    // Allocate buffer for data
    char buf[BUF_SIZE];
    
    // Receive greeting from server
    int num_bytes = SSL_read(ssl, buf, BUF_SIZE-1);
    if (num_bytes <= 0) {
        handle_error("Failed to receive greeting from server");
    }
    buf[num_bytes] = '\0';
    printf("%s", buf);
    
    // Send login command to server
    sprintf(buf, "a1 LOGIN %s %s\r\n", username, password);
    if (SSL_write(ssl, buf, strlen(buf)) <= 0) {
        handle_error("Failed to send login command to server");
    }
    
    // Receive response from server
    num_bytes = SSL_read(ssl, buf, BUF_SIZE-1);
    if (num_bytes <= 0) {
        handle_error("Failed to receive response from server");
    }
    buf[num_bytes] = '\0';
    printf("%s", buf);
    
    // Send select command to server
    sprintf(buf, "a2 SELECT inbox\r\n");
    if (SSL_write(ssl, buf, strlen(buf)) <= 0) {
        handle_error("Failed to send select command to server");
    }
    
    // Receive response from server
    num_bytes = SSL_read(ssl, buf, BUF_SIZE-1);
    if (num_bytes <= 0) {
        handle_error("Failed to receive response from server");
    }
    buf[num_bytes] = '\0';
    printf("%s", buf);
    
    // Send logout command to server
    sprintf(buf, "a3 LOGOUT\r\n");
    if (SSL_write(ssl, buf, strlen(buf)) <= 0) {
        handle_error("Failed to send logout command to server");
    }
    
    // Receive response from server
    num_bytes = SSL_read(ssl, buf, BUF_SIZE-1);
    if (num_bytes <= 0) {
        handle_error("Failed to receive response from server");
    }
    buf[num_bytes] = '\0';
    printf("%s", buf);
    
    // Close SSL connection and socket
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ssl_ctx);
    close(sockfd);
    
    // Clean up OpenSSL
    EVP_cleanup();
    
    return EXIT_SUCCESS;
}