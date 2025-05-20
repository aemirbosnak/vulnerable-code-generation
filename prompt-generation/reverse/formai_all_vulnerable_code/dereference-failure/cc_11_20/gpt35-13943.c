//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
       printf("Usage: %s <port>\n", argv[0]);
       return 1;
    }

    int PORT = atoi(argv[1]);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0) {
        perror("Socket creation error");
        return 1;
    }

    printf("Socket created successfully.\n");

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Bind error");
        return 1;
    }

    printf("Bind successfully.\n");

    if (listen(server_fd, 10) < 0) {
        perror("Listen error");
        return 1;
    }

    printf("Listening on port %d ...\n", PORT);

    while (1) {

        int client_fd = accept(server_fd, NULL, NULL);

        if (client_fd < 0) {
            perror("Accept error");
            continue;
        }

        printf("Connection accepted.\n");

        int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);

        if (proxy_fd < 0) {
            perror("Proxy socket creation error");
            continue;
        }

        printf("Proxy socket created successfully.\n");

        struct sockaddr_in proxy_addr = {
            .sin_family = AF_INET,
            .sin_port = htons(80)
        };

        char request[1024];
        char response[1024];

        memset(request, 0, sizeof(request));
        memset(response, 0, sizeof(response));

        if (connect(proxy_fd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
            perror("Proxy connect error");
            close(client_fd);
            close(proxy_fd);
            continue;
        }

        printf("Proxy connection established.\n");

        int bytes = recv(client_fd, request, sizeof(request), 0);

        if (bytes < 0) {
            perror("Client recv error");
            close(client_fd);
            close(proxy_fd);
            continue;
        }

        printf("Request received from client: %s\n", request);

        if (send(proxy_fd, request, strlen(request), 0) < 0) {
            perror("Proxy send error");
            close(client_fd);
            close(proxy_fd);
            continue;
        }

        printf("Request sent to the proxy.\n");

        bytes = recv(proxy_fd, response, sizeof(response), 0);

        if (bytes < 0) {
            perror("Proxy recv error");
            close(client_fd);
            close(proxy_fd);
            continue;
        }

        printf("Response received from the proxy: %s\n", response);

        if (send(client_fd, response, strlen(response), 0) < 0) {
            perror("Client send error");
            close(client_fd);
            close(proxy_fd);
            continue;
        }

        printf("Response sent to the client.\n");

        close(client_fd);
        close(proxy_fd);

    }

    return 0;
}