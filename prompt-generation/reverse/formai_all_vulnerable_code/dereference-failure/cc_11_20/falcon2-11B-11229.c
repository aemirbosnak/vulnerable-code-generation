//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>

#define PORT 8080

int main() {
    int sockfd, valread;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    struct timeval tv;
    fd_set readfds;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 3) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    while (1) {
        select(sockfd + 1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(sockfd, &readfds)) {
            socklen_t clientlen = sizeof(cli_addr);

            if ((valread = accept(sockfd, (struct sockaddr *) &cli_addr, &clientlen)) == -1) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            tv.tv_sec = 0;
            tv.tv_usec = 100000;

            while (1) {
                if ((valread = recv(sockfd, buffer, 255, 0)) == -1) {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }

                printf("Received: %s\n", buffer);

                tv.tv_sec = 0;
                tv.tv_usec = 100000;

                if (sendto(sockfd, buffer, valread, 0, (struct sockaddr *) &cli_addr, sizeof(cli_addr)) == -1) {
                    perror("sendto");
                    exit(EXIT_FAILURE);
                }

                tv.tv_sec = 0;
                tv.tv_usec = 100000;

                if (sendto(sockfd, buffer, valread, 0, (struct sockaddr *) &cli_addr, sizeof(cli_addr)) == -1) {
                    perror("sendto");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    close(sockfd);
    return 0;
}