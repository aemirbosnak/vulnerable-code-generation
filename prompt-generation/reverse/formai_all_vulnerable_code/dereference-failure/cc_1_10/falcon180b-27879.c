//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 4096
#define BACKLOG 10

typedef struct {
    int sock;
    struct sockaddr_in addr;
} client_t;

int main(int argc, char *argv[]) {
    int listen_sock, client_sock, new_sock;
    struct sockaddr_in listen_addr, client_addr;
    socklen_t addr_size;
    char buffer[MAX_LINE];
    client_t *clients = NULL;
    int max_clients = 0;

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket");
        exit(1);
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "0.0.0.0", &listen_addr.sin_addr);

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_sock, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Proxy server started on port 8080\n");

    while (1) {
        addr_size = sizeof(client_addr);
        if ((client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addr_size)) == -1) {
            perror("accept");
            continue;
        }

        if (max_clients >= BACKLOG) {
            send(client_sock, "Proxy server is full\r\n", 24, 0);
            close(client_sock);
            continue;
        }

        clients = realloc(clients, sizeof(client_t) * ++max_clients);
        clients[max_clients - 1].sock = client_sock;
        clients[max_clients - 1].addr = client_addr;

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    return 0;
}