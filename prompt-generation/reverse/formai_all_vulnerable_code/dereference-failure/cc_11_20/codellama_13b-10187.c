//Code Llama-13B DATASET v1.0 Category: Simple Web Server ; Style: minimalist
/* A minimalist C Simple Web Server example program
 *
 * Usage: ./web_server <port>
 *
 * Listens on the specified port and serves static files
 * from the current directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sock, new_sock;
    struct sockaddr_in addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFSIZE];

    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Set address and port
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(atoi(argv[1]));

    // Bind socket to address and port
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server listening on port %s\n", argv[1]);

    // Accept incoming connections
    new_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (new_sock < 0) {
        perror("accept");
        exit(1);
    }

    // Handle incoming request
    int n = read(new_sock, buffer, BUFSIZE);
    if (n < 0) {
        perror("read");
        exit(1);
    }

    // Print request
    printf("Request: %s\n", buffer);

    // Check if request is for a static file
    if (strstr(buffer, ".html") || strstr(buffer, ".css") || strstr(buffer, ".js")) {
        // Open file
        int fd = open(buffer, O_RDONLY);
        if (fd < 0) {
            perror("open");
            exit(1);
        }

        // Read file contents
        char file_buffer[BUFSIZE];
        int file_size = read(fd, file_buffer, BUFSIZE);
        if (file_size < 0) {
            perror("read");
            exit(1);
        }

        // Send file contents
        if (write(new_sock, file_buffer, file_size) < 0) {
            perror("write");
            exit(1);
        }

        // Close file
        if (close(fd) < 0) {
            perror("close");
            exit(1);
        }
    } else {
        // Send error message
        char error_message[] = "HTTP/1.1 404 Not Found\r\n\r\n";
        if (write(new_sock, error_message, strlen(error_message)) < 0) {
            perror("write");
            exit(1);
        }
    }

    // Close connection
    if (close(new_sock) < 0) {
        perror("close");
        exit(1);
    }

    // Close server socket
    if (close(sock) < 0) {
        perror("close");
        exit(1);
    }

    return 0;
}