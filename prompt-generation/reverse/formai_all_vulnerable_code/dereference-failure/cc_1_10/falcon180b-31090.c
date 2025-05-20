//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_LINE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
    int listen_sock, conn_sock;
    struct sockaddr_in server_addr, client_addr;
    char line[MAX_LINE];

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_sock, 5) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Proxy server is listening on port %d\n", PORT);

    while (1) {
        socklen_t addr_len;
        conn_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addr_len);
        if (conn_sock == -1) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bzero(line, MAX_LINE);
            if (recv(conn_sock, line, MAX_LINE, 0) <= 0) {
                printf("Client disconnected\n");
                close(conn_sock);
                break;
            }

            char *req_method = strtok(line, " ");
            char *req_uri = strtok(NULL, " ");

            if (strcmp(req_method, "GET") == 0) {
                send(conn_sock, "HTTP/1.1 200 OK\r\n\r\n", 24, 0);
            } else {
                send(conn_sock, "HTTP/1.1 405 Method Not Allowed\r\n\r\n", 31, 0);
            }
        }

        close(conn_sock);
    }

    return 0;
}