//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAXLINE 1024
#define PORT 21

char *hostname = "localhost";
int sockfd, portno;
struct sockaddr_in serv_addr;
char send_buffer[MAXLINE], recv_buffer[MAXLINE];

void die(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        die("socket failed");
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        die("connect failed");
    }

    printf("Connected to %s:%d\n", hostname, portno);

    while(1) {
        printf("Enter command: ");
        fgets(send_buffer, MAXLINE, stdin);
        send(sockfd, send_buffer, strlen(send_buffer), 0);

        bzero(recv_buffer, MAXLINE);
        recv(sockfd, recv_buffer, MAXLINE, 0);
        printf("%s\n", recv_buffer);
    }

    return 0;
}