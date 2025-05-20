//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX 100
#define PORT 7

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1025];
    char ip[16];
    int opt = 1;
    int addrlen = sizeof(cli_addr);

    if (argc < 3) {
        printf("Usage:./ping <IP Address> <No. of Packets>\n");
        return 0;
    }

    strcpy(ip, argv[1]);
   atoi(argv[2]);

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(PORT);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter the number of data bytes to be sent\n");
    scanf("%d", &sd);

    // send data
    for (i = 0; i < sd; i++) {
        if (send(sockfd, &i, sizeof(i), 0) == -1) {
            perror("send");
        }
    }

    // receive data
    while (TRUE) {
        memset(buffer, 0, sizeof(buffer));
        clilen = sizeof(cli_addr);
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen)) < 0) {
            perror("accept");
        }

        if (recv(newsockfd, buffer, sizeof(buffer), 0) == -1) {
            perror("recv");
        }

        printf("Received: %s\n", buffer);

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}