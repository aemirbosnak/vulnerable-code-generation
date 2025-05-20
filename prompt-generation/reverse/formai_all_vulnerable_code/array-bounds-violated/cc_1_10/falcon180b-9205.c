//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, retval;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(SERVER_PORT);

    retval = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (retval == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            retval = recv(newsockfd, buffer, BUFFER_SIZE, 0);
            if (retval == 0) {
                printf("Connection closed by client\n");
                break;
            } else if (retval == -1) {
                printf("Error receiving data\n");
                exit(1);
            }

            buffer[retval] = '\0';
            printf("Received message: %s\n", buffer);

            retval = send(newsockfd, buffer, strlen(buffer), 0);
            if (retval == -1) {
                printf("Error sending data\n");
                exit(1);
            }
        }

        close(newsockfd);
    }

    return 0;
}