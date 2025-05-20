//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 4096
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char line[MAX_LINE];
    char request[MAX_LINE];
    char response[MAX_LINE];
    int client_len;

    if (argc!= 3) {
        printf("Usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Proxy server started on port %s\n", argv[1]);

    while (1) {
        client_len = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_len);

        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        memset(request, 0, MAX_LINE);
        memset(response, 0, MAX_LINE);

        while (1) {
            bzero(line, MAX_LINE);
            if (recv(client_socket, line, MAX_LINE, 0) <= 0) {
                printf("Connection closed by client\n");
                break;
            }

            printf("Received: %s", line);

            strcat(request, line);

            if (strstr(request, "\r\n\r\n")!= NULL) {
                break;
            }
        }

        strcat(request, "\r\n");

        send(client_socket, request, strlen(request), 0);

        bzero(line, MAX_LINE);
        bzero(response, MAX_LINE);

        while (1) {
            if (recv(client_socket, line, MAX_LINE, 0) <= 0) {
                printf("Connection closed by client\n");
                break;
            }

            printf("Received: %s", line);

            strcat(response, line);

            if (strstr(response, "\r\n\r\n")!= NULL) {
                break;
            }
        }

        send(client_socket, response, strlen(response), 0);

        close(client_socket);
    }

    return 0;
}