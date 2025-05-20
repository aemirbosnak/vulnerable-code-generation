//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT "8080"
#define MAX 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("127.0.0.1");
    if (server == NULL) {
        printf("No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(PORT));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        bzero(buffer, MAX);
        fgets(buffer, MAX, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "/quit") == 0) {
            break;
        }
        bzero(buffer, MAX);
        recv(sockfd, buffer, MAX, 0);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}