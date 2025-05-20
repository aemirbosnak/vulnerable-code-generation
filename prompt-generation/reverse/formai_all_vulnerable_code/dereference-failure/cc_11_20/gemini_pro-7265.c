//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <target-host>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char *target_host = argv[2];

    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(port);

    if (bind(listen_sock, (struct sockaddr *) &listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(listen_sock, 10) == -1) {
        perror("listen");
        return 1;
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(listen_sock, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        char request[MAX_BUFFER_SIZE];
        memset(request, 0, sizeof(request));
        int request_len = read(client_sock, request, sizeof(request) - 1);
        if (request_len == -1) {
            perror("read");
            close(client_sock);
            continue;
        }

        char *host = strstr(request, "Host: ");
        if (!host) {
            fprintf(stderr, "Invalid request: no Host header\n");
            close(client_sock);
            continue;
        }

        host += strlen("Host: ");
        char *end_of_host = strchr(host, '\n');
        if (!end_of_host) {
            fprintf(stderr, "Invalid request: no end of Host header\n");
            close(client_sock);
            continue;
        }

        *end_of_host = '\0';

        char *path = strstr(request, "GET ");
        if (!path) {
            fprintf(stderr, "Invalid request: no GET method\n");
            close(client_sock);
            continue;
        }

        path += strlen("GET ");
        char *end_of_path = strchr(path, ' ');
        if (!end_of_path) {
            fprintf(stderr, "Invalid request: no end of GET method\n");
            close(client_sock);
            continue;
        }

        *end_of_path = '\0';

        int target_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (target_sock == -1) {
            perror("socket");
            close(client_sock);
            continue;
        }

        struct sockaddr_in target_addr;
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = inet_addr(target_host);
        target_addr.sin_port = htons(80);

        if (connect(target_sock, (struct sockaddr *) &target_addr, sizeof(target_addr)) == -1) {
            perror("connect");
            close(client_sock);
            close(target_sock);
            continue;
        }

        write(target_sock, request, request_len);

        char response[MAX_BUFFER_SIZE];
        memset(response, 0, sizeof(response));
        int response_len = read(target_sock, response, sizeof(response) - 1);
        if (response_len == -1) {
            perror("read");
            close(client_sock);
            close(target_sock);
            continue;
        }

        close(target_sock);
        write(client_sock, response, response_len);
        close(client_sock);
    }

    close(listen_sock);

    return 0;
}