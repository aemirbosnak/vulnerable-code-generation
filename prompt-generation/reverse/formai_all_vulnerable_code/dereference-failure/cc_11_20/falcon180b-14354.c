//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_socket;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buf[BUF_SIZE];
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);
    fd_set read_fds;

    if (argc!= 2) {
        printf("Usage:./qos_monitor <port>\n");
        return 1;
    }

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        return 1;
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error listening on socket\n");
        return 1;
    }

    FD_ZERO(&read_fds);
    FD_SET(server_socket, &read_fds);
    max_socket = server_socket;

    while (1) {
        int retval, i;

        retval = select(max_socket + 1, &read_fds, NULL, NULL, NULL);

        if (retval < 0) {
            printf("Error with select()\n");
            return 1;
        }

        for (i = 0; i <= max_socket; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == server_socket) {
                    addrlen = sizeof(struct sockaddr_in);
                    if ((client_socket[MAX_CLIENTS - 1] = accept(server_socket, (struct sockaddr *)&client_addr[MAX_CLIENTS - 1], &addrlen)) < 0) {
                        printf("Error accepting connection\n");
                        return 1;
                    }
                    FD_SET(client_socket[MAX_CLIENTS - 1], &read_fds);
                    max_socket++;
                } else {
                    memset(buf, 0, BUF_SIZE);
                    retval = recv(i, buf, BUF_SIZE, 0);

                    if (retval <= 0) {
                        close(i);
                        FD_CLR(i, &read_fds);
                        continue;
                    }

                    printf("Received message: %s\n", buf);
                }
            }
        }
    }

    return 0;
}