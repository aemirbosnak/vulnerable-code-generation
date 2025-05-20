//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char* argv[]) {
    int sockfd, recvbytes;
    struct sockaddr_in servaddr;
    char recvbuf[BUFSIZE], sendbuf[BUFSIZE];

    if (argc != 3) {
        fprintf(stderr, "usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // set server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_aton(argv[1], &servaddr.sin_addr) == 0) {
        fprintf(stderr, "invalid IP address\n");
        exit(1);
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("connected to server %s:%s\n", argv[1], argv[2]);

    while (1) {
        printf("Enter message (or type 'exit' to quit): ");
        fgets(sendbuf, BUFSIZE, stdin);

        if (strcmp(sendbuf, "exit\n") == 0) {
            break;
        }

        // send message
        if (send(sockfd, sendbuf, strlen(sendbuf), 0) == -1) {
            perror("send");
            exit(1);
        }

        // receive response
        if ((recvbytes = recv(sockfd, recvbuf, BUFSIZE, 0)) == -1) {
            perror("recv");
            exit(1);
        }
        recvbuf[recvbytes] = '\0';

        printf("Received: %s", recvbuf);
    }

    // close socket
    close(sockfd);

    return 0;
}