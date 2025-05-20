//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Claude Shannon
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
#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) {
    int listen_sock, conn_sock;
    struct sockaddr_in server_addr, client_addr;
    int addr_len, new_sock;
    char buffer[MAX_LINE_LEN];

    if ((listen_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_sock, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (TRUE) {
        addr_len = sizeof(client_addr);
        if ((new_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            memset(buffer, 0, sizeof(buffer));
            if (recv(new_sock, buffer, MAX_LINE_LEN, 0) <= 0) {
                if (errno!= EAGAIN) {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }
                break;
            }

            printf("Received message: %s", buffer);

            if (send(new_sock, buffer, strlen(buffer), 0) < 0) {
                perror("send");
                exit(EXIT_FAILURE);
            }
        }

        close(new_sock);
    }

    return 0;
}