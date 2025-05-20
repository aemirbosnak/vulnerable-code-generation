//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(client_addr);
    int opt = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5)) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addrlen);

        if (newsockfd == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);

            if (recv(newsockfd, buffer, BUFFER_SIZE, 0) <= 0) {
                if (errno!= EAGAIN) {
                    perror("recv");
                }
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(newsockfd, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                perror("send");
            }
        }

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}