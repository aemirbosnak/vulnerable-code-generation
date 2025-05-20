//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Shape shifting program: A simple TCP/IP chat server

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in servaddr = {0};
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 10) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server started and listening on port %d\n", port);

    while (1) {
        int connfd = accept(sockfd, (struct sockaddr *)NULL, NULL);
        if (connfd < 0) {
            perror("accept");
            continue;
        }

        printf("Client connected\n");

        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            continue;
        } else if (pid == 0) {
            close(sockfd);
            char message[1024] = {0};

            while (1) {
                if (read(connfd, message, 1024) == 0) {
                    printf("Client disconnected\n");
                    break;
                }

                char *reply = "OK\n";
                write(connfd, reply, strlen(reply));
            }

            close(connfd);
            exit(0);
        }

        close(connfd);
    }
    close(sockfd);

    return 0;
}