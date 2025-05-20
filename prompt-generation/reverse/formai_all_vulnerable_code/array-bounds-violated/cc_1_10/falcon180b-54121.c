//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, recv_len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int opt = 1;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8888);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8888\n");

    while (1) {
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, \
                (socklen_t*)&clilen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            memset(buffer, '\0', BUFFER_SIZE);
            recv_len = recv(newsockfd, buffer, BUFFER_SIZE, 0);

            if (recv_len <= 0) {
                break;
            }

            buffer[recv_len] = '\0';
            printf("Received message: %s\n", buffer);

            send(newsockfd, buffer, strlen(buffer), 0);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}