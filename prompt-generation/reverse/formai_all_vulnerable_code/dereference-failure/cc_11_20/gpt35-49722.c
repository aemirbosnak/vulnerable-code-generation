//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_REQUEST_LEN 4096
#define MAX_RESPONSE_LEN 65535

int proxy(int client_socket) {
    char request[MAX_REQUEST_LEN];
    ssize_t request_len = recv(client_socket, request, MAX_REQUEST_LEN, 0);
    if (request_len < 0) {
        perror("recv");
        return -1;
    }

    char *host = NULL;
    char *path = NULL;
    int port = 80;

    char *line = strtok(request, "\n");
    while (line != NULL) {
        if (strncmp(line, "Host: ", 6) == 0) {
            host = strdup(line + 6);
            if (host[strlen(host) - 1] == '\r') {
                host[strlen(host) - 1] = '\0';
            }

            char *colon = strchr(host, ':');
            if (colon != NULL) {
                *colon = '\0';
                port = atoi(colon + 1);
            }
        } else if (strncmp(line, "GET ", 4) == 0) {
            path = strdup(line + 4);
            char *space = strchr(path, ' ');

            if (space != NULL) {
                *space = '\0';
            }
        }

        line = strtok(NULL, "\n");
    }

    if (host == NULL || path == NULL) {
        return -1;
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);
    server_addr.sin_port = htons(port);

    if (connect(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return -1;
    }

    char modified_request[MAX_REQUEST_LEN];
    snprintf(modified_request, MAX_REQUEST_LEN, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    if (send(server_socket, modified_request, strlen(modified_request), 0) < 0) {
        perror("send");
        return -1;
    }

    char response[MAX_RESPONSE_LEN];
    ssize_t response_len = recv(server_socket, response, MAX_RESPONSE_LEN, 0);
    if (response_len < 0) {
        perror("recv");
        return -1;
    }

    if (send(client_socket, response, response_len, 0) < 0) {
        perror("send");
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [port]\n", argv[0]);
        return -1;
    }

    int port = atoi(argv[1]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return -1;
    }

    int enable = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) < 0) {
        perror("setsockopt");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return -1;
    }

    if (listen(server_socket, 10) < 0) {
        perror("listen");
        return -1;
    }

    while (1) {
        struct sockaddr_in client_addr;
        memset(&client_addr, 0, sizeof(client_addr));
        socklen_t client_len = sizeof(client_addr);

        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        int pid = fork();
        if (pid == 0) {
            close(server_socket);
            proxy(client_socket);
            close(client_socket);
            exit(0);
        } else if (pid < 0) {
            perror("fork");
            close(client_socket);
        }
    }

    return 0;
}