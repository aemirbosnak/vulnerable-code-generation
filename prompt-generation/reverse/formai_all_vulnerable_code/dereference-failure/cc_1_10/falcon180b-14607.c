//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int max_clients = 5;
    int listener = 0;

    if (argc < 3) {
        printf("Usage: %s <port> <message>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);
    strcpy(buffer, argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, max_clients);
    printf("Server is listening on port %d\n", portno);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        if (listener == 0) {
            listener = newsockfd;
            printf("Listener connected on port %d\n", portno);
        } else {
            send(listener, buffer, strlen(buffer), 0);
            send(newsockfd, buffer, strlen(buffer), 0);
        }

        close(newsockfd);
    }

    return 0;
}