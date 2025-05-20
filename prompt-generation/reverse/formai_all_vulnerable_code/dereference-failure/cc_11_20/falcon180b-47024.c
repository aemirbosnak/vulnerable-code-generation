//Falcon-180B DATASET v1.0 Category: Firewall ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, new_socket, client_socket[MAX_CLIENTS], max_clients = 0;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];
    fd_set master_fds, read_fds;
    int max_fd, retval;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    FD_ZERO(&master_fds);
    FD_SET(server_socket, &master_fds);
    max_fd = server_socket;

    while (1) {
        read_fds = master_fds;
        retval = select(max_fd + 1, &read_fds, NULL, NULL, NULL);

        if (retval == -1) {
            printf("Error with select()\n");
            exit(1);
        }

        for (int i = 0; i <= max_fd; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == server_socket) {
                    addr_size = sizeof(client_addr);
                    new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);

                    if (new_socket!= -1) {
                        FD_SET(new_socket, &master_fds);
                        max_clients++;

                        if (max_clients == MAX_CLIENTS) {
                            printf("Maximum number of clients reached\n");
                            close(new_socket);
                            continue;
                        }

                        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                    } else {
                        printf("Error accepting connection\n");
                    }
                } else {
                    if (read(i, buffer, BUFFER_SIZE) <= 0) {
                        close(i);
                        FD_CLR(i, &master_fds);
                        printf("Client disconnected: %d\n", i);
                        max_clients--;
                    } else {
                        write(i, buffer, strlen(buffer));
                    }
                }
            }
        }
    }

    return 0;
}