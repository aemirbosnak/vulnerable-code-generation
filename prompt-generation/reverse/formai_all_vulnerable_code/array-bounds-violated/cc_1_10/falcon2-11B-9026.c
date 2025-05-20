//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;

    if (argc!= 2) {
        fprintf(stderr, "Usage %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, (struct sockaddr *)&serv_addr, (socklen_t*)&n);
        if (sockfd < 0) {
            perror("accept");
            continue;
        }

        printf("Connected by client with address %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

        char buffer[256];
        int bytes_read;
        while ((bytes_read = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
            buffer[bytes_read] = '\0';
            printf("%s\n", buffer);
        }

        close(sockfd);
    }

    return 0;
}