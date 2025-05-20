//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    pid_t childpid;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
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

    printf("Server is listening on port %d\n", portno);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        printf("New connection with IP: %s and Port: %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        childpid = fork();
        if (childpid < 0) {
            perror("fork");
            exit(1);
        } else if (childpid > 0) {
            close(newsockfd);
        } else {
            close(sockfd);

            while (1) {
                valread = read(newsockfd, buffer, BUFFER_SIZE);
                if (valread <= 0) {
                    break;
                }
                write(STDOUT_FILENO, buffer, valread);
            }

            close(newsockfd);
            exit(0);
        }
    }

    return 0;
}