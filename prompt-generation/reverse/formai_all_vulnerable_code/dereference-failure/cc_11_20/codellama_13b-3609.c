//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(listen_fd, 1) < 0) {
        perror("listen");
        return 1;
    }

    printf("Listening on port %d...\n", port);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        int client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd < 0) {
            perror("accept");
            return 1;
        }

        char buffer[MAX_BUFFER_SIZE];
        ssize_t bytes_read;

        while ((bytes_read = read(client_fd, buffer, MAX_BUFFER_SIZE)) > 0) {
            char *request = strstr(buffer, "GET /");
            if (request) {
                printf("Got a request: %s\n", request);

                char *path = strchr(request, ' ');
                if (path) {
                    path++;
                    char *end = strchr(path, ' ');
                    if (end) {
                        *end = '\0';
                    }

                    printf("Path: %s\n", path);

                    if (strcmp(path, "/") == 0) {
                        write(client_fd, "HTTP/1.1 200 OK\r\n", 15);
                        write(client_fd, "Content-Type: text/html\r\n", 22);
                        write(client_fd, "\r\n", 2);
                        write(client_fd, "<html><body><h1>Hello, World!</h1></body></html>", 51);
                    } else {
                        write(client_fd, "HTTP/1.1 404 Not Found\r\n", 20);
                        write(client_fd, "Content-Type: text/html\r\n", 22);
                        write(client_fd, "\r\n", 2);
                        write(client_fd, "<html><body><h1>Not Found</h1></body></html>", 48);
                    }
                }
            }
        }

        close(client_fd);
    }

    close(listen_fd);
    return 0;
}