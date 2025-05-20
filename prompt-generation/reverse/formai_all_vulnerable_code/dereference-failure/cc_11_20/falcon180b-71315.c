//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    int max_fd, conn_fd;
    fd_set master_fds, read_fds;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        return 1;
    }

    if (listen(listen_socket, MAX_CONNECTIONS) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        return 1;
    }

    FD_ZERO(&master_fds);
    FD_SET(listen_socket, &master_fds);
    max_fd = listen_socket;

    while (1) {
        read_fds = master_fds;
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) == -1) {
            printf("Error selecting sockets: %s\n", strerror(errno));
            return 1;
        }

        for (conn_fd = 0; conn_fd <= max_fd; conn_fd++) {
            if (FD_ISSET(conn_fd, &read_fds)) {
                if (conn_fd == listen_socket) {
                    addrlen = sizeof(client_addr);
                    client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen);
                    if (client_socket == -1) {
                        printf("Error accepting connection: %s\n", strerror(errno));
                        return 1;
                    }

                    FD_SET(client_socket, &master_fds);
                    max_fd = client_socket;
                } else {
                    memset(buffer, 0, BUFFER_SIZE);
                    if (recv(conn_fd, buffer, BUFFER_SIZE, 0) <= 0) {
                        close(conn_fd);
                        FD_CLR(conn_fd, &master_fds);
                    } else {
                        send(conn_fd, buffer, strlen(buffer), 0);
                    }
                }
            }
        }
    }

    return 0;
}