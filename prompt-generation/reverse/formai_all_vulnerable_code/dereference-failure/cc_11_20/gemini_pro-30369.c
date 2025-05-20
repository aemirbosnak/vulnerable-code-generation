//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 4096

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <target_host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    char* target_host = argv[2];

    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    int client_fd;
    while ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len)) != -1) {
        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buf[BUF_SIZE];
        int bytes_read;
        while ((bytes_read = read(client_fd, buf, BUF_SIZE)) > 0) {
            // Parse the request
            char* method = strtok(buf, " ");
            char* path = strtok(NULL, " ");
            char* version = strtok(NULL, "\r\n");

            // Construct the request to the target host
            char request[BUF_SIZE];
            snprintf(request, BUF_SIZE, "%s %s %s\r\n", method, path, version);

            // Send the request to the target host
            int target_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (target_fd == -1) {
                perror("socket");
                exit(EXIT_FAILURE);
            }

            struct sockaddr_in target_addr;
            target_addr.sin_family = AF_INET;
            target_addr.sin_addr.s_addr = inet_addr(target_host);
            target_addr.sin_port = htons(80);

            if (connect(target_fd, (struct sockaddr*)&target_addr, sizeof(target_addr)) == -1) {
                perror("connect");
                exit(EXIT_FAILURE);
            }

            if (write(target_fd, request, strlen(request)) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }

            // Read the response from the target host
            char response[BUF_SIZE];
            int bytes_written;
            while ((bytes_written = read(target_fd, response, BUF_SIZE)) > 0) {
                // Write the response to the client
                if (write(client_fd, response, bytes_written) == -1) {
                    perror("write");
                    exit(EXIT_FAILURE);
                }
            }

            close(target_fd);
        }

        close(client_fd);
    }

    close(server_fd);

    return EXIT_SUCCESS;
}