//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

// Max buffer size for reading/writing
#define BUF_SIZE 1024

// HTTP status codes and messages
#define HTTP_OK "HTTP/1.1 200 OK\r\n"
#define HTTP_NOT_FOUND "HTTP/1.1 404 Not Found\r\n"
#define HTTP_INTERNAL_SERVER_ERROR "HTTP/1.1 500 Internal Server Error\r\n"

// MIME types for common file extensions
#define MIME_HTML "text/html"
#define MIME_CSS "text/css"
#define MIME_JS "text/javascript"
#define MIME_JPEG "image/jpeg"
#define MIME_PNG "image/png"

// Main function
int main() {
    // Create a socket for listening
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the socket to non-blocking
    int flags = fcntl(listenfd, F_GETFL, 0);
    flags |= O_NONBLOCK;
    if (fcntl(listenfd, F_SETFL, flags) < 0) {
        perror("fcntl");
        exit(1);
    }

    // Bind the socket to an address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);
    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listenfd, 10) < 0) {
        perror("listen");
        exit(1);
    }

    // Select loop for handling multiple clients
    while (1) {
        // Set up the select set
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(listenfd, &read_fds);

        // Select for ready sockets
        int maxfd = listenfd;
        if (select(maxfd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(1);
        }

        // Handle incoming connections
        if (FD_ISSET(listenfd, &read_fds)) {
            // Accept the connection
            int connfd = accept(listenfd, NULL, NULL);
            if (connfd < 0) {
                perror("accept");
                continue;
            }

            // Create a buffer for the request
            char buf[BUF_SIZE];
            memset(buf, 0, BUF_SIZE);

            // Read the request
            int nread = read(connfd, buf, BUF_SIZE - 1);
            if (nread < 0) {
                perror("read");
                close(connfd);
                continue;
            }

            // Parse the request
            char *method = strtok(buf, " ");
            char *path = strtok(NULL, " ");
            char *version = strtok(NULL, "\r\n");

            // Ignore unsupported methods
            if (strcmp(method, "GET") != 0) {
                close(connfd);
                continue;
            }

            // Handle the root path
            if (strcmp(path, "/") == 0) {
                path = "/index.html";
            }

            // Get the file extension
            char *ext = strrchr(path, '.');

            // Determine the MIME type
            char *mime_type;
            if (strcmp(ext, ".html") == 0) {
                mime_type = MIME_HTML;
            } else if (strcmp(ext, ".css") == 0) {
                mime_type = MIME_CSS;
            } else if (strcmp(ext, ".js") == 0) {
                mime_type = MIME_JS;
            } else if (strcmp(ext, ".jpg") == 0) {
                mime_type = MIME_JPEG;
            } else if (strcmp(ext, ".png") == 0) {
                mime_type = MIME_PNG;
            } else {
                mime_type = "text/plain";
            }

            // Open the file
            int fd = open(path, O_RDONLY);
            if (fd < 0) {
                // Send a 404 Not Found response
                write(connfd, HTTP_NOT_FOUND, strlen(HTTP_NOT_FOUND));
                close(connfd);
                continue;
            }

            // Get the file size
            struct stat sb;
            if (fstat(fd, &sb) < 0) {
                // Send a 500 Internal Server Error response
                write(connfd, HTTP_INTERNAL_SERVER_ERROR, strlen(HTTP_INTERNAL_SERVER_ERROR));
                close(connfd);
                continue;
            }

            // Create a memory-mapped file
            char *file_data = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
            if (file_data == MAP_FAILED) {
                // Send a 500 Internal Server Error response
                write(connfd, HTTP_INTERNAL_SERVER_ERROR, strlen(HTTP_INTERNAL_SERVER_ERROR));
                close(connfd);
                continue;
            }

            // Send the response header
            char header[BUF_SIZE];
            snprintf(header, BUF_SIZE, "%sContent-Type: %s\r\nContent-Length: %ld\r\n\r\n", HTTP_OK, mime_type, sb.st_size);
            write(connfd, header, strlen(header));

            // Send the file data
            write(connfd, file_data, sb.st_size);

            // Unmap the memory-mapped file
            munmap(file_data, sb.st_size);

            // Close the file
            close(fd);

            // Close the connection
            close(connfd);
        }
    }

    // Close the listening socket
    close(listenfd);

    return 0;
}