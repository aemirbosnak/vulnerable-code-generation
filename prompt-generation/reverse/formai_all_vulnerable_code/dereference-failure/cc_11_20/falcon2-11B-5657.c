//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <proxy_port> <target_host>\n", argv[0]);
        return 1;
    }

    int proxy_port = atoi(argv[1]);
    char *target_host = argv[2];

    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in proxy_addr, client_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(proxy_port);

    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        perror("socket");
        return 1;
    }

    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(proxy_socket, 5) == -1) {
        perror("listen");
        return 1;
    }

    int client_addr_len = sizeof(client_addr);
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(proxy_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock == -1) {
            perror("accept");
            return 1;
        }

        char request[4096];
        int request_len = read(client_sock, request, sizeof(request));
        if (request_len == -1) {
            perror("read");
            close(client_sock);
            continue;
        }

        request[request_len] = '\0';
        printf("Received request: %s\n", request);

        char response[4096];
        int response_len = snprintf(response, sizeof(response), "HTTP/1.1 200 OK\r\n\r\nHello, world!\r\n");
        if (response_len == -1) {
            perror("snprintf");
            return 1;
        }

        if (write(client_sock, response, response_len) == -1) {
            perror("write");
            return 1;
        }

        close(client_sock);
    }

    return 0;
}