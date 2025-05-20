//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

// Define the SSL context
SSL_CTX *ssl_ctx;

// Initialize the SSL context
int init_ssl_context() {
    SSL_library_init();
    SSL_load_error_strings();
    ssl_ctx = SSL_CTX_new(TLS_server_method());
    if (ssl_ctx == NULL) {
        fprintf(stderr, "Error creating SSL context: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return -1;
    }
    if (SSL_CTX_use_certificate_file(ssl_ctx, "server.crt", SSL_FILETYPE_PEM) <= 0) {
        fprintf(stderr, "Error loading certificate: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return -1;
    }
    if (SSL_CTX_use_PrivateKey_file(ssl_ctx, "server.key", SSL_FILETYPE_PEM) <= 0) {
        fprintf(stderr, "Error loading private key: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return -1;
    }
    return 0;
}

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    SSL *ssl;

    // Initialize the SSL context
    if (init_ssl_context() < 0) {
        return -1;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return -1;
    }

    // Set the socket to non-blocking
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags < 0) {
        perror("Error getting socket flags");
        return -1;
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) < 0) {
        perror("Error setting socket flags");
        return -1;
    }

    // Set the server address
    portno = 8080;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        return -1;
    }

    // Listen for connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening on socket");
        return -1;
    }

    // Accept a connection
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                // No connections are currently available, so we can continue to do other tasks
                continue;
            } else {
                perror("Error accepting connection");
                return -1;
            }
        }

        // Create a new SSL connection
        ssl = SSL_new(ssl_ctx);
        if (ssl == NULL) {
            fprintf(stderr, "Error creating SSL connection: %s\n", ERR_error_string(ERR_get_error(), NULL));
            return -1;
        }
        if (SSL_set_fd(ssl, newsockfd) <= 0) {
            fprintf(stderr, "Error setting SSL file descriptor: %s\n", ERR_error_string(ERR_get_error(), NULL));
            return -1;
        }

        // Perform the SSL handshake
        if (SSL_accept(ssl) <= 0) {
            fprintf(stderr, "Error performing SSL handshake: %s\n", ERR_error_string(ERR_get_error(), NULL));
            return -1;
        }

        // Read the request from the client
        memset(buffer, 0, sizeof(buffer));
        if (SSL_read(ssl, buffer, sizeof(buffer) - 1) <= 0) {
            fprintf(stderr, "Error reading request from client: %s\n", ERR_error_string(ERR_get_error(), NULL));
            return -1;
        }

        // Parse the request
        char *method = strtok(buffer, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Check if the request is valid
        if (strcmp(method, "GET") != 0) {
            // The request is not a GET request, so we can ignore it
            SSL_write(ssl, "HTTP/1.1 400 Bad Request\r\n\r\n", 27);
            SSL_shutdown(ssl);
            close(newsockfd);
            continue;
        }
        if (strcmp(version, "HTTP/1.1") != 0) {
            // The request is not an HTTP/1.1 request, so we can ignore it
            SSL_write(ssl, "HTTP/1.1 400 Bad Request\r\n\r\n", 27);
            SSL_shutdown(ssl);
            close(newsockfd);
            continue;
        }

        // Check if the requested file exists
        int fd = open(path, O_RDONLY);
        if (fd < 0) {
            // The file does not exist, so we can send a 404 error
            SSL_write(ssl, "HTTP/1.1 404 Not Found\r\n\r\n", 25);
            SSL_shutdown(ssl);
            close(newsockfd);
            continue;
        }

        // Read the file into a buffer
        char *file_buffer = malloc(1024);
        memset(file_buffer, 0, 1024);
        int bytes_read = read(fd, file_buffer, 1023);
        file_buffer[bytes_read] = '\0';
        close(fd);

        // Send the file to the client
        SSL_write(ssl, "HTTP/1.1 200 OK\r\nContent-Length: ", 31);
        SSL_write(ssl, file_buffer, bytes_read);
        SSL_shutdown(ssl);
        close(newsockfd);

        // Free the file buffer
        free(file_buffer);
    }

    // Clean up
    SSL_CTX_free(ssl_ctx);
    close(sockfd);
    return 0;
}