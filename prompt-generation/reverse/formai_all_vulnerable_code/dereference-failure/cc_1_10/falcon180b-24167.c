//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[MAX];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket");
        exit(1);
    }

    server = gethostbyname("127.0.0.1");
    if (server == NULL) {
        printf("Error finding server");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(1234);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, MAX);
        n = read(sockfd, buffer, MAX);
        buffer[n] = '\0';
        printf("Received message: %s", buffer);
    }

    close(sockfd);
    return 0;
}