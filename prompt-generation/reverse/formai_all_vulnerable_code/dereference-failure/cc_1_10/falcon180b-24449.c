//Falcon-180B DATASET v1.0 Category: Networking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int addrlen;
    int opt = 1;
    int n;

    if (argc!= 3) {
        printf("usage:./server <port> <message>\n");
        exit(0);
    }

    portno = atoi(argv[1]);
    strcpy(buffer, argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("socket failed\n");
        exit(0);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("bind failed\n");
        exit(0);
    }

    listen(sockfd, 5);
    printf("server listening on port %d\n", portno);

    while (1) {
        addrlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
        if (newsockfd < 0) {
            printf("accept failed\n");
            exit(0);
        }

        send(newsockfd, buffer, strlen(buffer), 0);
        close(newsockfd);
    }

    return 0;
}