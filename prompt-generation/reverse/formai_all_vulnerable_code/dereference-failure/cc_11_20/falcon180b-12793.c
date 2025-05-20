//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 100

int main() {
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    fd_set readfds;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("socket failed");
        exit(0);
    }

    portno = 8080;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(sockfd, 5);

    FD_ZERO(&readfds);

    FD_SET(sockfd, &readfds);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);

        if (newsockfd < 0) {
            printf("accept failed");
            exit(0);
        }

        FD_SET(newsockfd, &readfds);

        if (newsockfd > sockfd) {
            sockfd = newsockfd;
        }
    }

    while (1) {
        FD_ZERO(&readfds);

        for (i = 0; i <= sockfd; i++) {
            sd = accept(i, NULL, NULL);

            if (sd > 0) {
                FD_SET(sd, &readfds);

                if (sd > sockfd) {
                    sockfd = sd;
                }
            }
        }

        select(sockfd + 1, &readfds, NULL, NULL, NULL);

        for (i = 0; i <= sockfd; i++) {
            if (FD_ISSET(i, &readfds)) {
                if (i == sockfd) {
                    valread = read(i, buffer, MAX);
                    if (valread == 0) {
                        close(i);
                        FD_CLR(i, &readfds);
                    }
                } else {
                    valread = read(i, buffer, MAX);
                    if (valread == 0) {
                        close(i);
                        FD_CLR(i, &readfds);
                    } else {
                        write(1, buffer, valread);
                    }
                }
            }
        }
    }

    return 0;
}