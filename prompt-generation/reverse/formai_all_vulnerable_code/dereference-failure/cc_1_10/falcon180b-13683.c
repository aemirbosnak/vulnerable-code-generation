//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    char *ip_address;
    struct hostent *hostinfo;
    struct sockaddr_in servaddr;
    char buffer[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage:./ftp_client <hostname> <port>\n");
        exit(1);
    }

    ip_address = argv[1];
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    hostinfo = gethostbyname(ip_address);
    if (hostinfo == NULL) {
        printf("Error: host not found\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy(hostinfo->h_addr, &servaddr.sin_addr.s_addr, hostinfo->h_length);
    servaddr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: connection failed\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        printf("Enter command: ");
        fgets(buffer, BUF_SIZE, stdin);

        if (strncmp(buffer, "QUIT", 4) == 0) {
            send(sockfd, buffer, strlen(buffer), 0);
            break;
        }

        send(sockfd, buffer, strlen(buffer), 0);
        bzero(buffer, BUF_SIZE);
        recv(sockfd, buffer, BUF_SIZE, 0);
        printf("%s\n", buffer);
    }

    close(sockfd);
    exit(0);
}