//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int fd, new_socket, addrlen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    ret = bind(fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        perror("bind failed");
        exit(1);
    }

    ret = listen(fd, BACKLOG);
    if (ret == -1) {
        perror("listen failed");
        exit(1);
    }

    addrlen = sizeof(cli_addr);
    while (TRUE) {
        new_socket = accept(fd, (struct sockaddr *)&cli_addr, &addrlen);
        if (new_socket == -1) {
            perror("accept failed");
            exit(1);
        }

        printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (TRUE) {
            memset(buffer, 0, BUF_SIZE);
            ret = recv(new_socket, buffer, BUF_SIZE, 0);
            if (ret <= 0) {
                if (ret == 0) {
                    printf("Client disconnected\n");
                } else {
                    printf("recv failed with error %d\n", errno);
                }
                close(new_socket);
                break;
            }

            printf("Received message: %s\n", buffer);

            ret = send(new_socket, buffer, strlen(buffer), 0);
            if (ret == -1) {
                printf("send failed with error %d\n", errno);
                close(new_socket);
                break;
            }
        }
    }

    close(fd);
    return 0;
}