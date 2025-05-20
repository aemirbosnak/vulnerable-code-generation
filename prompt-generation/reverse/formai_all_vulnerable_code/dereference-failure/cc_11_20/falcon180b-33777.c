//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int master_socket, client_socket[MAX_CLIENTS], max_clients = 0;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    fd_set master_fds, read_fds;

    if (argc!= 3) {
        printf("Usage: %s <port> <max_clients>\n", argv[0]);
        return 1;
    }

    master_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (master_socket == -1) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(master_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        return 1;
    }

    FD_ZERO(&master_fds);
    FD_SET(master_socket, &master_fds);
    max_clients = atoi(argv[2]);

    while (1) {
        read_fds = master_fds;
        if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            return 1;
        }

        for (int i = 0; i < FD_SETSIZE; ++i) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == master_socket) {
                    struct sockaddr_in client_addr;
                    socklen_t addr_len = sizeof(client_addr);
                    int new_client = accept(master_socket, (struct sockaddr *)&client_addr, &addr_len);

                    if (new_client!= -1) {
                        FD_SET(new_client, &master_fds);
                        ++max_clients;
                    } else {
                        perror("accept");
                    }
                } else {
                    int bytes_received = recv(i, buffer, BUFFER_SIZE, 0);

                    if (bytes_received <= 0) {
                        close(i);
                        FD_CLR(i, &master_fds);
                        --max_clients;
                    } else {
                        buffer[bytes_received] = '\0';
                        printf("Client %d sent: %s\n", i, buffer);
                    }
                }
            }
        }
    }

    return 0;
}