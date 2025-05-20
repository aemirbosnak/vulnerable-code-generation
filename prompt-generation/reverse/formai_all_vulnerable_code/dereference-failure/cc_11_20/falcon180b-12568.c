//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd;
    int newsockfd;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    int opt = 1;
    int addrlen = sizeof(cli_addr);
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen);

        if (newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            memset(buffer, 0, sizeof(buffer));

            if (recv(newsockfd, buffer, sizeof(buffer), 0) <= 0) {
                if (errno!= EWOULDBLOCK) {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }
                break;
            }

            printf("Received message: %s\n", buffer);

            if (send(newsockfd, buffer, strlen(buffer), 0) < 0) {
                perror("send");
                exit(EXIT_FAILURE);
            }
        }

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}