//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char **argv) {
    int sockfd, newsockfd, portno;
    unsigned int clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    portno = 8080;

    server = gethostbyname("127.0.0.1");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        bzero(buffer, sizeof(buffer));
        recv(sockfd, buffer, sizeof(buffer), 0);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}