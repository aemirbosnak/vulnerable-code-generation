//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: peaceful
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

int main() {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    portno = 8080;
    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error getting hostname\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1) {
        bzero(buffer, sizeof(buffer));
        fgets(buffer, 1024, stdin);
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            printf("Error sending data\n");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}