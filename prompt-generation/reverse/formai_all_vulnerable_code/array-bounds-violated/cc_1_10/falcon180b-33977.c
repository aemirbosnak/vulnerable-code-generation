//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define BUFLEN 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, recv_len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFLEN];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    portno = atoi("12345");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        recv_len = recv(newsockfd, buffer, BUFLEN, 0);
        if (recv_len <= 0) {
            printf("Connection closed by client\n");
            break;
        }
        buffer[recv_len] = '\0';
        printf("Received message: %s\n", buffer);

        if (send(newsockfd, "ACK", strlen("ACK"), 0) < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }
    }

    close(sockfd);
    close(newsockfd);
    return 0;
}