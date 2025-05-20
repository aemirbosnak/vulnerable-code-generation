//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000);

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        socklen_t clilen = sizeof(cli_addr);
        cli_addr.sin_family = AF_INET;
        cli_addr.sin_port = htons(0);

        if ((sockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen)) < 0) {
            perror("Error on accepting");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while ((n = recv(sockfd, buffer, 256, 0)) > 0) {
            buffer[n] = '\0';
            printf("Received: %s\n", buffer);
            send(sockfd, buffer, strlen(buffer), 0);
        }

        close(sockfd);
        break;
    }

    return 0;
}