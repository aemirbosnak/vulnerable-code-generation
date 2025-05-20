//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define TRUE  1
#define FALSE 0
#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, port;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[MAX_LINE];

    if (argc!= 3) {
        printf("Usage: %s <listen_port> <forward_port>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("socket() failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("bind() failed\n");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        printf("listen() failed\n");
        exit(1);
    }

    while (TRUE) {
        addr_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (client_socket == -1) {
            printf("accept() failed\n");
            continue;
        }

        port = ntohs(client_addr.sin_port);
        if (port!= atoi(argv[2])) {
            send(client_socket, "HTTP/1.0 404 Not Found\r\n\r\n", 25, 0);
            close(client_socket);
            continue;
        }

        while (TRUE) {
            memset(buffer, 0, MAX_LINE);
            int bytes_received = recv(client_socket, buffer, MAX_LINE, 0);
            if (bytes_received <= 0) {
                break;
            }

            char *request_line = strstr(buffer, "\r\n");
            if (request_line == NULL) {
                continue;
            }

            *request_line = '\0';
            char *method = strtok(buffer, " ");
            char *uri = strtok(NULL, " ");

            if (strcmp(method, "GET") == 0) {
                char host[1024];
                sprintf(host, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", uri, argv[2]);
                send(client_socket, host, strlen(host), 0);
            }
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}