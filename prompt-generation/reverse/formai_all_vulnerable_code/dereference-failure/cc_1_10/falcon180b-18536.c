//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE   1
#define FALSE  0
#define PORT 8080
#define MAX 100

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    if(argc < 3) {
        printf("usage :./a.out <host_ip> <no_of_pings>\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        die("socket failed");
    }

    portno = PORT;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        die("connect failed");
    }

    printf("Connected to %s\n", argv[1]);

    for(i = 0 ; i < atoi(argv[2]) ; i++) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

        if(newsockfd < 0) {
            die("accept failed");
        }

        printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        sd = dup(newsockfd);

        if(sd < 0) {
            die("dup failed");
        }

        close(newsockfd);

        while(TRUE) {
            valread = read(sd, buffer, MAX);

            if(valread <= 0) {
                break;
            }

            write(sd, buffer, strlen(buffer));
        }

        close(sd);
    }

    close(sockfd);

    return 0;
}