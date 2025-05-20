//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFERSIZE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return EXIT_FAILURE;
    }

    memset((char*)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy((char*)&serv_addr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFERSIZE);
    if (recv(sockfd, buffer, BUFFERSIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s\n", buffer);

    memset(buffer, 0, BUFFERSIZE);
    sprintf(buffer, "USER username\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFERSIZE);
    if (recv(sockfd, buffer, BUFFERSIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s\n", buffer);

    memset(buffer, 0, BUFFERSIZE);
    sprintf(buffer, "PASS password\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFERSIZE);
    if (recv(sockfd, buffer, BUFFERSIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s\n", buffer);

    memset(buffer, 0, BUFFERSIZE);
    sprintf(buffer, "LIST\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFERSIZE);
    if (recv(sockfd, buffer, BUFFERSIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s\n", buffer);

    memset(buffer, 0, BUFFERSIZE);
    sprintf(buffer, "RETR 1\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFERSIZE);
    if (recv(sockfd, buffer, BUFFERSIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s\n", buffer);

    memset(buffer, 0, BUFFERSIZE);
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    memset(buffer, 0, BUFFERSIZE);
    if (recv(sockfd, buffer, BUFFERSIZE, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s\n", buffer);

    close(sockfd);

    return EXIT_SUCCESS;
}