//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE   1
#define FALSE  0
#define BACKLOG 5

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    int opt = TRUE;
    int addrlen = sizeof(struct sockaddr_in);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd == -1) {
        perror("socket failed");
        exit(1);
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    memset(&server_addr, 0, sizeof(struct sockaddr_in));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);

        if (conn_fd < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[1024];
        bzero(buffer, sizeof(buffer));

        while (TRUE) {
            memset(buffer, 0, sizeof(buffer));

            int bytes_received = recv(conn_fd, buffer, sizeof(buffer), 0);

            if (bytes_received <= 0) {
                break;
            }

            buffer[bytes_received] = '\0';

            printf("Received: %s", buffer);

            send(conn_fd, buffer, strlen(buffer), 0);
        }

        close(conn_fd);
    }

    close(listen_fd);

    return 0;
}