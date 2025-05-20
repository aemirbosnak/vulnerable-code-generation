//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_CLIENTS 5
#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[MAX_BUFFER];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, MAX_CLIENTS);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(1);
        }

        bzero(buffer, MAX_BUFFER);
        n = read(newsockfd, buffer, MAX_BUFFER);
        if (n < 0) {
            perror("read failed");
            exit(1);
        }

        printf("Received message from client: %s\n", buffer);

        n = write(newsockfd, buffer, n);
        if (n < 0) {
            perror("write failed");
            exit(1);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}