//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error in socket creation\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 21;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);

    printf("Server is listening...\n");

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, sizeof(cli_addr));
        printf("Connection accepted\n");

        while (1) {
            bzero(buffer, sizeof(buffer));
            n = recv(newsockfd, buffer, sizeof(buffer), 0);

            if (n <= 0) {
                printf("Connection closed\n");
                break;
            }

            buffer[n] = '\0';
            printf("Received message: %s\n", buffer);

            send(newsockfd, buffer, strlen(buffer), 0);
        }

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}