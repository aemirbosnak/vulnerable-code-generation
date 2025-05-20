//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    portno = 8080;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    while (1) {
        if ((n = accept(sockfd, (struct sockaddr *)NULL, NULL)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("Got connection\n");

        char buf[1024];
        bzero(buf, sizeof(buf));

        while (1) {
            n = recv(n, buf, sizeof(buf) - 1, 0);
            if (n < 0) {
                perror("recv");
                exit(EXIT_FAILURE);
            }

            if (n == 0)
                break;

            buf[n] = '\0';
            printf("Received: %s\n", buf);

            if (strcmp(buf, "GET / HTTP/1.0\r\n\r\n") == 0) {
                printf("HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n");
                printf("<!DOCTYPE HTML>\n<html>\n<head>\n<title>Hello World</title>\n</head>\n<body>\n<h1>Hello World!</h1>\n</body>\n</html>\n");
                break;
            } else {
                printf("HTTP/1.0 404 Not Found\r\n\r\n");
                printf("<!DOCTYPE HTML>\n<html>\n<head>\n<title>404 Not Found</title>\n</head>\n<body>\n<h1>404 Not Found</h1>\n</body>\n</html>\n");
            }
        }

        close(n);
    }

    return 0;
}