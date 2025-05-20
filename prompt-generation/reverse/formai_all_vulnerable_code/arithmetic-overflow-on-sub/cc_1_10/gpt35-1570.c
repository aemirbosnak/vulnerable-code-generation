//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char ip[100];
    struct timeval tv_start, tv_end;
    double elapsed_time;

    printf("Enter the IP address of the website to test: ");
    scanf("%s", ip);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation failed\n");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        return -1;
    }

    gettimeofday(&tv_start, NULL);

    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Connection failed\n");
        return -1;
    }

    gettimeofday(&tv_end, NULL);

    close(sockfd);

    elapsed_time = (double)(tv_end.tv_sec - tv_start.tv_sec) 
                         + (double)(tv_end.tv_usec - tv_start.tv_usec) / 1000000;

    printf("Response time: %f seconds\n", elapsed_time);

    return 0;
}