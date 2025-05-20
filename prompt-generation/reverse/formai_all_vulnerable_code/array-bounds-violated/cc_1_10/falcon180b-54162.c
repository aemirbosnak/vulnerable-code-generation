//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    while (1) {
        ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (ret <= 0) {
            break;
        }
        buffer[ret] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}