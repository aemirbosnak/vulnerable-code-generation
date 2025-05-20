//Falcon-180B DATASET v1.0 Category: Chat server ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define TRUE    1
#define FALSE   0
#define PORT    8080
#define BACKLOG 10
#define BUF_SIZE 512

int main(int argc, char *argv[])
{
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buf[BUF_SIZE];
    int addrlen;
    int opt = TRUE;
    int client_socket;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return -1;
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_fd, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (TRUE) {
        addrlen = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (conn_fd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            memset(buf, 0, sizeof(buf));
            if (recv(conn_fd, buf, BUF_SIZE - 1, 0) <= 0) {
                if (errno!= EAGAIN) {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }
                break;
            }

            buf[strcspn(buf, "\r\n")] = '\0';
            printf("Received: %s", buf);

            if (strcasecmp(buf, "/quit") == 0) {
                printf("Client %s:%d disconnected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                close(conn_fd);
                break;
            }

            if (send(conn_fd, buf, strlen(buf), 0)!= strlen(buf)) {
                perror("send");
                exit(EXIT_FAILURE);
            }
        }

        close(conn_fd);
    }

    return 0;
}