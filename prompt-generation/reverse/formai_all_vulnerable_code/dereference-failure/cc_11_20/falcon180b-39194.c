//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_LINE 4096
#define BACKLOG 10

int main(int argc, char **argv) {
    int listen_fd, conn_fd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_LINE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        addrlen = sizeof(cli_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &addrlen);
        if (conn_fd < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection from: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            int bytes_received = recv(conn_fd, buffer, MAX_LINE, 0);

            if (bytes_received <= 0) {
                break;
            }

            char *request = strtok(buffer, "\r\n");

            if (request == NULL) {
                continue;
            }

            printf("Received request: %s", request);

            char *method = strtok(request, " ");
            char *path = strtok(NULL, " ");

            if (method == NULL || path == NULL) {
                continue;
            }

            if (strcmp(method, "GET")!= 0) {
                continue;
            }

            char response[1024];
            sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", strlen("Hello, world!"));

            send(conn_fd, response, strlen(response), 0);

            char *body = "Hello, world!";
            send(conn_fd, body, strlen(body), 0);

            break;
        }

        close(conn_fd);
    }

    return 0;
}