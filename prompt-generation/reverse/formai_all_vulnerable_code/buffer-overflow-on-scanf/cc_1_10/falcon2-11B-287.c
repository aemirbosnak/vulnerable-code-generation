//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char s[INET6_ADDRSTRLEN];

    if (socket(AF_INET, SOCK_STREAM, 0) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(80);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    while (1) {
        socklen_t clilen = sizeof(struct sockaddr);
        int newsockfd = accept(sockfd, (struct sockaddr *) &serv_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept failed");
            continue;
        }

        printf("Connected by %s\n", inet_ntoa(serv_addr.sin_addr));
        char buffer[100];
        printf("Please enter your message: ");
        scanf("%s", buffer);
        send(newsockfd, buffer, strlen(buffer), 0);

        printf("Message Sent!\n");
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}