//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int listen_sock, conn_sock;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen;
    char buffer[MAX_LINE];

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_sock == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    if (bind(listen_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_sock, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is waiting for connections...\n");

    while (TRUE) {
        addrlen = sizeof(cli_addr);
        conn_sock = accept(listen_sock, (struct sockaddr *)&cli_addr, &addrlen);

        if (conn_sock < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (TRUE) {
            memset(buffer, 0, MAX_LINE);

            if (recv(conn_sock, buffer, MAX_LINE, 0) <= 0) {
                if (errno == ECONNRESET) {
                    printf("Connection reset by peer\n");
                } else {
                    perror("recv");
                }

                close(conn_sock);
                break;
            }

            printf("Received message: %s", buffer);

            if (send(conn_sock, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                perror("send");
            }
        }
    }

    close(listen_sock);
    return 0;
}