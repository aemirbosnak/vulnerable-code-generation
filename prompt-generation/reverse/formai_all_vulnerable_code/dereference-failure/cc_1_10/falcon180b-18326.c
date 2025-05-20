//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/time.h>
#include <time.h>

int main() {
    int sockfd, newsockfd, portno, clilen, len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1025];
    struct hostent *server;
    time_t ticks;
    fd_set readfds;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    portno = 8080;

    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr, "No such host.\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        ticks = time(NULL);

        select(sockfd + 1, &readfds, NULL, NULL, &ticks);

        if (FD_ISSET(sockfd, &readfds)) {
            if ((len = read(sockfd, buffer, sizeof(buffer))) < 0) {
                perror("read");
                exit(EXIT_FAILURE);
            }
            buffer[len] = '\0';
            printf("Received message: %s\n", buffer);
        }
    }

    close(sockfd);

    return 0;
}