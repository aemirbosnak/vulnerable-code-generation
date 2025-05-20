//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sockfd, newsockfd, portno, clilen, recv_len;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        error_handling("Error opening socket");
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    bzero(&serv_addr, sizeof(serv_addr));
    portno = 8080;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("Error binding socket");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            error_handling("Error accepting connection");
        }

        printf("Connection established with %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, sizeof(buffer));
            recv_len = recv(newsockfd, buffer, sizeof(buffer), 0);
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