//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen = sizeof(serv_addr);

    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        if ((newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &addrlen)) < 0) {
            perror("accept");
            exit(1);
        }

        char buffer[MAXLINE];
        bzero(buffer, MAXLINE);

        while (1) {
            int n = recv(newsockfd, buffer, MAXLINE, 0);
            if (n < 0) {
                perror("recv");
                exit(1);
            } else if (n == 0)
                break;

            printf("Client(%d.%d.%d.%d:%d): %s\n",
                   ntohs(cli_addr.sin_addr.s_addr),
                   ntohs(cli_addr.sin_port),
                   ntohs(cli_addr.sin_addr.s_addr),
                   ntohs(cli_addr.sin_port),
                   ntohs(cli_addr.sin_port),
                   buffer);

            if (n == 0)
                break;

            int m = snprintf(buffer, MAXLINE, "HTTP/1.1 200 OK\r\n\
                Content-Type: text/html\r\n\
                Connection: close\r\n\r\n\
                <html>\r\n\
                <head>\r\n\
                <title>Web Server</title>\r\n\
                </head>\r\n\
                <body>\r\n\
                <h1>Hello, World!</h1>\r\n\
                </body>\r\n\
                </html>\r\n");
            if (m < 0) {
                perror("snprintf");
                exit(1);
            }

            if (send(newsockfd, buffer, m, 0) < 0) {
                perror("send");
                exit(1);
            }
        }

        close(newsockfd);
    }

    return 0;
}