//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char buffer[BUFFER_SIZE];
    int len;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8080);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        printf("Error listening on socket");
        exit(1);
    }

    while (1) {
        len = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &len);
        if (newsockfd < 0) {
            printf("Error accepting connection");
            exit(1);
        }

        printf("Connection from: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            len = recv(newsockfd, buffer, BUFFER_SIZE, 0);
            if (len <= 0) {
                printf("Client disconnected\n");
                close(newsockfd);
                break;
            }

            buffer[len] = '\0';
            printf("Received: %s\n", buffer);

            if (strncmp(buffer, "time", 4) == 0) {
                time_t now = time(0);
                char *time_str = ctime(&now);
                send(newsockfd, time_str, strlen(time_str), 0);
            } else if (strncmp(buffer, "exit", 4) == 0) {
                printf("Exiting...\n");
                exit(0);
            }
        }
    }

    return 0;
}