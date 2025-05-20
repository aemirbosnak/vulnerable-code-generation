//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

typedef struct {
    int fd;
    struct sockaddr_in addr;
} client_t;

int main(int argc, char **argv) {
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    client_t clients[MAX_CLIENTS];
    int num_clients = 0;
    fd_set readfds;
    int maxfd = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(listenfd, MAX_CLIENTS) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    maxfd = listenfd;

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(listenfd, &readfds);

        for (int i = 0; i < num_clients; i++) {
            FD_SET(clients[i].fd, &readfds);
        }

        if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0) {
            perror("select");
            return EXIT_FAILURE;
        }

        if (FD_ISSET(listenfd, &readfds)) {
            connfd = accept(listenfd, (struct sockaddr *)&clients[num_clients].addr, sizeof(clients[num_clients].addr));
            if (connfd < 0) {
                perror("accept");
                continue;
            }

            clients[num_clients].fd = connfd;
            num_clients++;

            if (num_clients == MAX_CLIENTS) {
                printf("Maximum number of clients reached\n");
                close(connfd);
                continue;
            }

            if (connfd > maxfd) {
                maxfd = connfd;
            }
        }

        for (int i = 0; i < num_clients; i++) {
            if (FD_ISSET(clients[i].fd, &readfds)) {
                char buf[MAX_MSG_SIZE];
                int n = read(clients[i].fd, buf, sizeof(buf));

                if (n == 0) {
                    printf("Client %d disconnected\n", clients[i].fd);
                    close(clients[i].fd);
                    clients[i] = clients[num_clients - 1];
                    num_clients--;
                    continue;
                }

                for (int j = 0; j < num_clients; j++) {
                    if (j != i) {
                        write(clients[j].fd, buf, n);
                    }
                }
            }
        }
    }

    return EXIT_SUCCESS;
}