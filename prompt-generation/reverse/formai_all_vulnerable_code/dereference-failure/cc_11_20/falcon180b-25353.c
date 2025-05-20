//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clilen, len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    int i, j;
    char *message;
    int msg_len;
    int client_count = 0;

    if (argc!= 2) {
        printf("Usage:./server <port_number>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);
    printf("Server is listening on port %d\n", atoi(argv[1]));

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        printf("New connection with client %d\n", ++client_count);

        while (1) {
            bzero(buffer, sizeof(buffer));
            len = recv(newsockfd, buffer, MAX, 0);
            if (len <= 0) {
                if (len == 0) {
                    printf("Client %d disconnected\n", client_count);
                } else {
                    perror("recv");
                }
                close(newsockfd);
                break;
            }

            buffer[len] = '\0';
            printf("Client %d sent message: %s\n", client_count, buffer);

            for (i = 0; i < client_count; i++) {
                if (i!= newsockfd) {
                    send(i, buffer, strlen(buffer), 0);
                }
            }
        }
    }

    return 0;
}