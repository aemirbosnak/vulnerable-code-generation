//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, i, val;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];
    int maxfd;
    fd_set readfds;
    struct timeval tv;

    /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    /* Set options on the socket */
    val = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
    setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof(val));

    /* Connect to remote server */
    server = gethostbyname("google.com");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    /* Establish connection */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    /* Set up select call */
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    maxfd = sockfd;

    /* Monitor network quality of service */
    while (1) {
        tv.tv_sec = 5;
        tv.tv_usec = 0;
        select(maxfd + 1, &readfds, NULL, NULL, &tv);

        /* Check for data on socket */
        if (FD_ISSET(sockfd, &readfds)) {
            i = recv(sockfd, buffer, 1024, 0);
            if (i <= 0) {
                perror("recv failed");
                exit(1);
            }
            write(1, buffer, i);
        }
    }

    close(sockfd);
    return 0;
}