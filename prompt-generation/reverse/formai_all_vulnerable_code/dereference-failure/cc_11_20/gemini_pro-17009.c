//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 512

typedef struct {
    int fd;
    char name[32];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        return 1;
    }

    fd_set readfds;
    int maxfd = sockfd;
    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        for (int i = 0; i < num_clients; i++) {
            FD_SET(clients[i].fd, &readfds);
            if (clients[i].fd > maxfd) {
                maxfd = clients[i].fd;
            }
        }

        if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0) {
            perror("select");
            return 1;
        }

        if (FD_ISSET(sockfd, &readfds)) {
            struct sockaddr_in cli_addr;
            socklen_t cli_addr_len = sizeof(cli_addr);
            int newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_addr_len);
            if (newsockfd < 0) {
                perror("accept");
                continue;
            }

            if (num_clients == MAX_CLIENTS) {
                close(newsockfd);
                continue;
            }

            clients[num_clients].fd = newsockfd;
            strcpy(clients[num_clients].name, "Anonymous");
            num_clients++;
        }

        for (int i = 0; i < num_clients; i++) {
            if (FD_ISSET(clients[i].fd, &readfds)) {
                char buf[MAX_MSG_LEN];
                ssize_t n = read(clients[i].fd, buf, MAX_MSG_LEN - 1);
                if (n <= 0) {
                    close(clients[i].fd);
                    clients[i] = clients[num_clients - 1];
                    num_clients--;
                    continue;
                }

                buf[n] = '\0';
                printf("%s: %s\n", clients[i].name, buf);

                for (int j = 0; j < num_clients; j++) {
                    if (j == i) {
                        continue;
                    }

                    if (write(clients[j].fd, buf, n) < 0) {
                        perror("write");
                        continue;
                    }
                }
            }
        }
    }

    return 0;
}