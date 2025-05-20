//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int master_socket, client_socket[MAX_CLIENTS];
    int opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(client_addr);
    int max_fd;
    fd_set master_fds, read_fds;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(master_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    FD_ZERO(&master_fds);
    FD_SET(master_socket, &master_fds);
    max_fd = master_socket;

    while (1) {
        read_fds = master_fds;
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(1);
        }

        for (int i = 0; i <= max_fd; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == master_socket) {
                    if ((client_socket[FD_SETSIZE - 1] = accept(master_socket, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
                        perror("accept");
                        exit(1);
                    }
                    FD_SET(client_socket[FD_SETSIZE - 1], &master_fds);
                    max_fd = client_socket[FD_SETSIZE - 1];
                    printf("Client %d connected\n", client_socket[FD_SETSIZE - 1]);
                } else {
                    int bytes_received = recv(i, buffer, BUFFER_SIZE, 0);
                    if (bytes_received <= 0) {
                        close(i);
                        FD_CLR(i, &master_fds);
                        printf("Client %d disconnected\n", i);
                    } else {
                        send(i, buffer, bytes_received, 0);
                    }
                }
            }
        }
    }

    return 0;
}