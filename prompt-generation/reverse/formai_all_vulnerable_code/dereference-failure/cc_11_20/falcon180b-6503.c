//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_socket;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    int addrlen = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];
    int bytes_received, total_bytes = 0;
    fd_set master_fds, read_fds;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP> <PORT>\n", argv[0]);
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1) {
        perror("connect");
        close(server_socket);
        return 1;
    }

    FD_ZERO(&master_fds);
    FD_SET(server_socket, &master_fds);
    max_socket = server_socket;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_socket[i] = -1;
    }

    while (1) {
        read_fds = master_fds;
        if (select(max_socket + 1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            return 1;
        }

        for (int i = 0; i <= max_socket; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == server_socket) {
                    bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);
                    if (bytes_received <= 0) {
                        close(server_socket);
                        for (int j = 0; j < MAX_CLIENTS; j++) {
                            if (client_socket[j]!= -1) {
                                close(client_socket[j]);
                            }
                        }
                        return 0;
                    }

                    total_bytes += bytes_received;
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        if (client_socket[j]!= -1) {
                            send(client_socket[j], buffer, bytes_received, 0);
                        }
                    }
                } else {
                    client_socket[total_bytes] = accept(server_socket, (struct sockaddr *)&client_addr[total_bytes], &addrlen);
                    if (client_socket[total_bytes] == -1) {
                        perror("accept");
                        return 1;
                    }

                    FD_SET(client_socket[total_bytes], &master_fds);
                    if (client_socket[total_bytes] > max_socket) {
                        max_socket = client_socket[total_bytes];
                    }
                }
            }
        }
    }

    return 0;
}