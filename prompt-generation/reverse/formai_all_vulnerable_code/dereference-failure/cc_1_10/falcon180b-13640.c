//Falcon-180B DATASET v1.0 Category: Networking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX 1000
#define PORT 8888

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    int n, addrlen;

    if (argc < 3) {
        printf("Usage:./server <IP> <Port>\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        exit(0);
    }

    listen(sockfd, 5);
    printf("Server is listening...\n");

    addrlen = sizeof(cli_addr);
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
        if (newsockfd < 0) {
            printf("Error accepting connection\n");
            exit(0);
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, MAX);
            n = read(newsockfd, buffer, MAX);
            if (n < 0) {
                printf("Error reading from socket\n");
                exit(0);
            }
            if (n == 0) {
                printf("Connection closed by client\n");
                close(newsockfd);
                break;
            }
            printf("Received message: %s\n", buffer);

            write(newsockfd, buffer, n);
            if (n < 0) {
                printf("Error writing to socket\n");
                exit(0);
            }
        }
    }

    return 0;
}