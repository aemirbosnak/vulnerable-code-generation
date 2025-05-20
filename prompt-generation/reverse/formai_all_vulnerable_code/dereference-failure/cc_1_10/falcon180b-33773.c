//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char sendline[1024];
    char recvline[1024];
    struct hostent *host;
    struct sockaddr_in serveraddr;
    int err;
    time_t starttime, endtime;
    double elapsedtime;

    if(argc!= 3) {
        printf("Usage:./ping hostname/IP address\n");
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if(host == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Socket creation failed\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(53);
    memcpy(&serveraddr.sin_addr, host->h_addr, host->h_length);

    if(connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Connection failed\n");
        exit(1);
    }

    printf("Connected to server\n");

    err = 0;
    while(err == 0) {
        sprintf(sendline, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
        numbytes = send(sockfd, sendline, strlen(sendline), 0);
        if(numbytes == -1) {
            printf("Send failed\n");
            exit(1);
        }

        memset(recvline, 0, sizeof(recvline));
        numbytes = recv(sockfd, recvline, sizeof(recvline), 0);
        if(numbytes == -1) {
            printf("Recv failed\n");
            exit(1);
        }

        printf("Received: %s", recvline);

        starttime = time(NULL);
        while(numbytes > 0) {
            printf("%s", recvline);
            numbytes -= strlen(recvline);
        }
        endtime = time(NULL);
        elapsedtime = difftime(endtime, starttime);
        printf("Elapsed time: %.2lf seconds\n", elapsedtime);

        err = 1;
    }

    close(sockfd);
    printf("Disconnected from server\n");

    return 0;
}