//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_NAME_LEN 256
#define MAX_DATA_SIZE 1024
#define MAX_PORT_NUMBER_LEN 6
#define QOS_MONITOR_PORT "3000"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, addrlen, clilen, retval, i, maxfd;
    char buffer[MAX_DATA_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    fd_set readfds;

    if (argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error getting host information.\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(QOS_MONITOR_PORT));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    maxfd = sockfd;

    while (1) {
        retval = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        if (retval == -1) {
            printf("Error in select function.\n");
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            memset(buffer, 0, MAX_DATA_SIZE);
            retval = read(sockfd, buffer, MAX_DATA_SIZE);
            if (retval <= 0) {
                printf("Error reading from socket.\n");
                exit(1);
            }

            printf("Received data: %s", buffer);
        }
    }

    close(sockfd);
    exit(0);
}