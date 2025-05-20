//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, valread, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];
    char *host = "127.0.0.1";
    int opt = 1;

    if (argc > 1) {
        host = argv[1];
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
        if (sockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while ((valread = recv(sockfd, buffer, 256, 0)) > 0) {
            buffer[valread] = '\0';
            printf("Received: %s\n", buffer);
            send(sockfd, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", 46, 0);
            send(sockfd, "<html><body>Hello World!</body></html>", 48, 0);
            printf("Sent: %s\n", buffer);
        }

        close(sockfd);
    }

    return 0;
}