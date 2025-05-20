//Falcon-180B DATASET v1.0 Category: Networking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 100

int main() {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error: No such host\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(8000);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    while (1) {
        bzero(buffer, MAX);
        ret = read(sockfd, buffer, MAX);
        if (ret < 0) {
            printf("Error: Failed to read from server\n");
            exit(1);
        }
        buffer[ret] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}