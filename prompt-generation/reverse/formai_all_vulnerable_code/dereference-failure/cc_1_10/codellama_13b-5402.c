//Code Llama-13B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
/*
 * C Network Quality of Service (QoS) monitor example program
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 1500

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[MAX_PACKET_SIZE];
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t clientlen = sizeof(clientaddr);
    char server[256], port[6];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    strcpy(server, argv[1]);
    strcpy(port, argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(server);
    serveraddr.sin_port = htons(atoi(port));

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        n = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *) &clientaddr, &clientlen);
        if (n < 0) {
            perror("recvfrom");
            exit(1);
        }

        printf("Received packet from %s:%d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
    }

    close(sockfd);
    return 0;
}