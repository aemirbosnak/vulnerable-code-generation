//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024
#define QOS_PORT 8080

int main() {
    int sockfd, newsockfd, portno, clilen, i, n, max_fd;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    fd_set readfds;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error getting host by name\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(QOS_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    max_fd = sockfd;

    while (1) {
        readfds = readfds;
        printf("Waiting for data...\n");
        n = select(max_fd + 1, &readfds, NULL, NULL, NULL);
        if (n == -1) {
            printf("Error selecting\n");
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            n = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
            if (n <= 0) {
                printf("Error receiving data\n");
                exit(1);
            }

            printf("Received data: %s\n", buffer);

            close(sockfd);
            exit(0);
        }
    }

    return 0;
}