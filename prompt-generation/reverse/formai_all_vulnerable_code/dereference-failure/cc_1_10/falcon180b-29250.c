//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1025];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        printf("Waiting for connections...\n");
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection established with %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, 1025);
            n = read(newsockfd, buffer, 1024);
            if (n < 0) {
                perror("read");
                exit(1);
            }

            if (n == 0) {
                printf("Client disconnected\n");
                break;
            }

            buffer[n] = '\0';
            printf("Received message: %s\n", buffer);

            send(newsockfd, buffer, strlen(buffer), 0);
        }

        close(newsockfd);
    }

    return 0;
}