//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;

    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset((char *) &serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    for (;;) {
        sockfd = accept(sockfd, (struct sockaddr *) NULL, NULL);

        if (sockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        if (connect(sockfd, (struct sockaddr *) NULL, sizeof(serv_addr)) < 0) {
            perror("connect failed");
            exit(EXIT_FAILURE);
        }

        printf("Connected by %s\n", inet_ntoa(serv_addr.sin_addr));

        char buffer[1024];
        int len;

        while ((len = recv(sockfd, buffer, 1024, 0)) > 0) {
            buffer[len] = '\0';
            printf("Received: %s\n", buffer);
        }

        close(sockfd);
    }

    return 0;
}