//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define BUF_SIZE 1024

int main() {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buf[BUF_SIZE];

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("socket failed: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("bind failed: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        printf("listen failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        socklen_t addr_len = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (conn_fd == -1) {
            printf("accept failed: %s\n", strerror(errno));
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((recv(conn_fd, buf, BUF_SIZE, 0)) > 0) {
            buf[recv(conn_fd, buf, BUF_SIZE, 0)] = '\0';
            printf("Received data: %s\n", buf);
            send(conn_fd, buf, strlen(buf), 0);
        }

        close(conn_fd);
    }

    return 0;
}