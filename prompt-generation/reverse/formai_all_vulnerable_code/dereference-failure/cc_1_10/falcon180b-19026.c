//Falcon-180B DATASET v1.0 Category: Networking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 100

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if (argc < 2) {
        printf("Usage:./client <IP address> <port number>\n");
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Unable to create socket\n");
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Unable to connect\n");
        exit(0);
    }

    while (1) {
        bzero(buffer, MAX);
        n = read(sockfd, buffer, MAX);
        if (n < 0) {
            printf("Error: Unable to read\n");
            exit(0);
        }
        buffer[n] = '\0';
        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}