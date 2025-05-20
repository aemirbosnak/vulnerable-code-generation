//Falcon-180B DATASET v1.0 Category: Chat server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int master_socket, client_socket, addrlen, new_socket, max_fd, activity, i;
    struct sockaddr_in server_addr, client_addr;
    fd_set master_fds, read_fds;

    if (argc!= 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(errno);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(errno);
    }

    if (listen(master_socket, BACKLOG) < 0) {
        perror("listen");
        exit(errno);
    }

    printf("Chat server started on IP %s and port %d\n", argv[1], PORT);

    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    FD_SET(master_socket, &master_fds);
    max_fd = master_socket;

    while (1) {
        read_fds = master_fds;

        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(errno);
        }

        for (i = 0; i <= max_fd; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == master_socket) {
                    addrlen = sizeof(client_addr);
                    if ((new_socket = accept(master_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
                        perror("accept");
                        exit(errno);
                    }

                    printf("New connection from IP %s and port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

                    FD_SET(new_socket, &master_fds);
                    max_fd = max_fd > new_socket? max_fd : new_socket;
                } else {
                    if ((activity = recv(i, NULL, 0, 0)) == 0) {
                        close(i);
                        FD_CLR(i, &master_fds);

                        printf("Connection closed on socket %d\n", i);
                    } else if (activity < 0) {
                        perror("recv");
                        exit(errno);
                    }
                }
            }
        }
    }

    return 0;
}