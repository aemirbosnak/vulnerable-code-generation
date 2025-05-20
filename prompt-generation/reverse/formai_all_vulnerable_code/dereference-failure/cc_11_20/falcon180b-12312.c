//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);
    char buffer[BUF_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (TRUE) {
        new_socket = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);
        if (new_socket == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            memset(buffer, 0, BUF_SIZE);
            if (recv(new_socket, buffer, BUF_SIZE, 0) <= 0) {
                if (errno == ECONNRESET) {
                    printf("Connection reset by peer\n");
                }
                close(new_socket);
                break;
            }

            printf("Received message: %s", buffer);

            if (send(new_socket, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                perror("send");
            }
        }
    }

    close(sockfd);
    return 0;
}