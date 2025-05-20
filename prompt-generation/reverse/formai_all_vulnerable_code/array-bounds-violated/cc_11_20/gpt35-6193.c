//FormAI DATASET v1.0 Category: Socket programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT "1234"
#define BACKLOG 10

int main() {
    int sockfd, newfd;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage client_addr;
    socklen_t sin_size;
    char buf[1024];
    int bytes;
    
    // Initialize SSL library
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_server_method());
    
    // Load server certificate and private key
    SSL_CTX_use_certificate_file(ctx, "server.crt", SSL_FILETYPE_PEM);
    SSL_CTX_use_PrivateKey_file(ctx, "server.key", SSL_FILETYPE_PEM);
    
    // Set up hints for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    
    // Get server info
    if (getaddrinfo(NULL, PORT, &hints, &servinfo) != 0) {
        perror("getaddrinfo");
        exit(1);
    }
    
    // Loop through all results and bind to the first available
    for (p = servinfo; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1)
            continue;
        
        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == 0)
            break;
        
        close(sockfd);
    }
    if (p == NULL) {
        perror("bind");
        exit(1);
    }
    freeaddrinfo(servinfo);
    
    // Listen on socket for incoming connections
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }
    printf("Server listening for incoming connections on port %s...\n", PORT);
    
    // Accept incoming connections and handle them in separate threads
    sin_size = sizeof(client_addr);
    while (1) {
        newfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
        if (newfd == -1) {
            perror("accept");
            continue;
        }
        
        // Set up SSL connection
        SSL *ssl = SSL_new(ctx);
        SSL_set_fd(ssl, newfd);
        if (SSL_accept(ssl) != 1) {
            ERR_print_errors_fp(stderr);
            SSL_shutdown(ssl);
            close(newfd);
            continue;
        }
        printf("Secure connection established with client %s\n", inet_ntoa(((struct sockaddr_in *)&client_addr)->sin_addr));
        
        // Receive data from client and send back a response
        bytes = SSL_read(ssl, buf, sizeof(buf) - 1);
        if (bytes > 0) {
            buf[bytes] = '\0';
            printf("Received message from client: %s\n", buf);
            
            char *response = "Hello, client! This is a secure server.";
            SSL_write(ssl, response, strlen(response));
        } else {
            ERR_print_errors_fp(stderr);
        }
        
        // Clean up SSL connection and close socket
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(newfd);
    }
    
    SSL_CTX_free(ctx);
    
    return 0;
}