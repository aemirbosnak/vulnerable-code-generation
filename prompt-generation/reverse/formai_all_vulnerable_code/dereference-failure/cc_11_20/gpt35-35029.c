//FormAI DATASET v1.0 Category: Browser Plugin ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a TCP socket
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the specified address and port
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY; // Use any available address
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 10) < 0) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Listening on port %d...\n", port);

    // Loop indefinitely and handle incoming connections
    while (1) {
        // Accept an incoming connection
        struct sockaddr_in cli_addr;
        socklen_t cli_addr_len = sizeof(cli_addr);
        int cli_sockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &cli_addr_len);
        if (cli_sockfd < 0) {
            perror("accept() failed");
            continue;
        }

        char buffer[BUFFER_SIZE];

        // Read the request from the client
        ssize_t len = read(cli_sockfd, buffer, BUFFER_SIZE);
        if (len < 0) {
            perror("read() failed");
            close(cli_sockfd);
            continue;
        }

        // Parse the request
        char *method = strtok(buffer, " ");
        char *path = strtok(NULL, " ");
        char *protocol = strtok(NULL, "\r\n");

        // Print some information about the request
        fprintf(stdout, "%s %s %s\n", method, path, protocol);

        // Handle the request based on the method
        if (strcmp(method, "GET") == 0) {
            // Open the requested file
            char *filename = path + 1; // Skip the leading slash
            int filefd = open(filename, O_RDONLY);
            if (filefd < 0) {
                perror("open() failed");
                close(cli_sockfd);
                continue;
            }

            // Read the file and send it to the client
            while ((len = read(filefd, buffer, BUFFER_SIZE)) > 0) {
                if (write(cli_sockfd, buffer, len) < 0) {
                    perror("write() failed");
                    close(filefd);
                    close(cli_sockfd);
                    continue;
                }
            }

            close(filefd);
        } else {
            // Unsupported method
            char *response =
                "HTTP/1.1 405 Method Not Allowed\r\n"
                "Allow: GET\r\n"
                "Connection: close\r\n\r\n";
            if (write(cli_sockfd, response, strlen(response)) < 0) {
                perror("write() failed");
                close(cli_sockfd);
                continue;
            }
        }

        // Close the connection
        close(cli_sockfd);
    }

    return 0;
}