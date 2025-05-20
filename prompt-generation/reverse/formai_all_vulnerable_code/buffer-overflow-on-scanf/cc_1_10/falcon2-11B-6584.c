//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main() {
    struct sockaddr_in server_addr;
    int sockfd, portno, n;
    char buffer[1000];
    struct hostent* server;

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    portno = htons(10000);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char*) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portno);
    bcopy((char*) server->h_addr, (char*) &server_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        printf("Enter email address to subscribe or unsubscribe: ");
        scanf("%s", buffer);
        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("send");
            exit(1);
        }

        bzero(buffer, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n < 0) {
            perror("recv");
            exit(1);
        }
        printf("%s\n", buffer);
    }

    return 0;
}