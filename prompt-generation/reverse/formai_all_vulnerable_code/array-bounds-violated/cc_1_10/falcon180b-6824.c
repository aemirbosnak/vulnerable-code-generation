//Falcon-180B DATASET v1.0 Category: Networking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#define PORT 8080
#define BACKLOG 5
#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        error("socket failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("bind failed");
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        error("listen");
    }

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addr_size);
        if (conn_fd == -1) {
            error("accept");
        }

        char buffer[BUF_SIZE];
        int bytes_received = 0;

        while ((bytes_received = recv(conn_fd, buffer, BUF_SIZE, 0)) > 0) {
            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            if (send(conn_fd, buffer, strlen(buffer), 0) == -1) {
                error("send");
            }
        }

        close(conn_fd);
    }

    return 0;
}