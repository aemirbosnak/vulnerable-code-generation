//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 5
#define MAX_REQUEST_SIZE 4096
#define MAX_RESPONSE_SIZE 4096

int main(int argc, char *argv[]) {
    int listen_fd, client_fd, port = 8080;
    struct sockaddr_in server_addr, client_addr;
    char request_buffer[MAX_REQUEST_SIZE], response_buffer[MAX_RESPONSE_SIZE];
    socklen_t addr_size;

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (TRUE) {
        addr_size = sizeof(client_addr);
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addr_size);

        if (client_fd == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        memset(request_buffer, 0, MAX_REQUEST_SIZE);
        memset(response_buffer, 0, MAX_RESPONSE_SIZE);

        while (TRUE) {
            int bytes_received = recv(client_fd, request_buffer, MAX_REQUEST_SIZE, 0);

            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                close(client_fd);
                break;
            }

            request_buffer[bytes_received] = '\0';

            char *request_line = strstr(request_buffer, "\r\n\r\n");

            if (request_line == NULL) {
                continue;
            }

            *request_line = '\0';

            char *method = strtok(request_buffer, " ");
            char *path = strtok(NULL, " ");

            if (method == NULL || path == NULL) {
                continue;
            }

            char host[1024];
            sprintf(host, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, path);

            send(client_fd, host, strlen(host), 0);

            char response_line[MAX_RESPONSE_SIZE];

            while (TRUE) {
                int bytes_sent = send(client_fd, response_line, strlen(response_line), 0);

                if (bytes_sent <= 0) {
                    printf("Client disconnected\n");
                    close(client_fd);
                    break;
                }
            }
        }
    }

    close(listen_fd);
    return 0;
}