//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024
#define BUF_SIZE 8192

void error(const char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buf[BUF_SIZE];
    int nbytes;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        error("socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error("bind");
    }

    if (listen(listen_fd, 5) == -1) {
        error("listen");
    }

    printf("Server started on port %s\n", argv[1]);

    while (1) {
        memset(buf, 0, MAX_LINE);
        conn_fd = accept(listen_fd, (struct sockaddr*)&client_addr, sizeof(client_addr));
        if (conn_fd == -1) {
            error("accept");
        }

        while ((nbytes = recv(conn_fd, buf, MAX_LINE, 0)) > 0) {
            send(conn_fd, buf, nbytes, 0);
        }

        close(conn_fd);
    }

    return 0;
}