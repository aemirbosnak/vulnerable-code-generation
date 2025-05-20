//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = TRUE;
    int addrlen = sizeof(cli_addr);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_fd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (TRUE) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen);

        if (conn_fd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        char buffer[1024];
        int bytes_received;

        while ((bytes_received = recv(conn_fd, buffer, sizeof(buffer), 0)) > 0) {
            buffer[bytes_received] = '\0';
            printf("Received message: %s", buffer);
            send(conn_fd, buffer, strlen(buffer), 0);
        }

        close(conn_fd);
    }

    return 0;
}