//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: authentic
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
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1025];
    int n;
    struct hostent *server;

    if (argc!= 3) {
        fprintf(stderr, "usage:./client <IP address> <port number>\n");
        exit(1);
    }

    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "socket failed\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "connect failed\n");
        exit(1);
    }

    while (1) {
        bzero(buffer, 1025);
        n = read(sockfd, buffer, 1024);
        if (n < 0) {
            fprintf(stderr, "read failed\n");
            exit(1);
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}