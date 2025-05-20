//Falcon-180B DATASET v1.0 Category: Firewall ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netdb.h>
#include <fcntl.h>
#include <poll.h>

#define MAX_CONNECTIONS 100
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    int listen_socket, client_socket, max_socket, addrlen, new_socket, i, valread, sd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    fd_set master_fds, read_fds;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == -1) {
        perror("socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_socket, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Firewall started on port %s\n", argv[1]);

    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    FD_SET(listen_socket, &master_fds);
    max_socket = listen_socket;

    while (1) {
        read_fds = master_fds;

        if (select(max_socket + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(1);
        }

        for (i = 0; i <= max_socket; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == listen_socket) {
                    addrlen = sizeof(client_addr);
                    new_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);

                    if (new_socket < 0) {
                        perror("accept");
                        exit(1);
                    }

                    FD_SET(new_socket, &master_fds);

                    if (new_socket > max_socket)
                        max_socket = new_socket;

                    printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                } else {
                    valread = read(i, buffer, BUFFER_SIZE);

                    if (valread <= 0) {
                        close(i);
                        FD_CLR(i, &master_fds);

                        printf("Connection closed on socket %d\n", i);
                    } else {
                        buffer[valread] = '\0';
                        printf("Received message: %s\n", buffer);
                    }
                }
            }
        }
    }

    return 0;
}