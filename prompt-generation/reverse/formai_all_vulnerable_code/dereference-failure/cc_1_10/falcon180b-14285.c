//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Dennis Ritchie
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

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    char buffer[1024];
    struct sockaddr_in server, client;
    struct hostent *he;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    he = gethostbyname(argv[1]);
    if (he == NULL) {
        fprintf(stderr, "Host not found\n");
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(portno);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)he->h_addr), &server.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (ret < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        ret = recv(sockfd, buffer, sizeof(buffer), 0);
        if (ret < 0) {
            perror("recv failed");
            exit(1);
        }
        printf("Received data: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}