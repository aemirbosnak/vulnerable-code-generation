//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char buffer[1024];
    struct hostent *he;
    struct sockaddr_in serv_addr;
    struct timeval timeout;
    int yes = 1;
    int flag = 0;
    int i;

    if (argc!= 3) {
        printf("Incorrect number of arguments\n");
        exit(1);
    }

    strcpy(serv_addr.sin_zero, "");
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes))) {
        perror("setsockopt");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect failed");
        exit(1);
    }

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        numbytes = recv(sockfd, buffer, sizeof(buffer), 0);
        if (numbytes <= 0) {
            flag = 1;
            break;
        }
        printf("%s", buffer);
    }

    if (flag == 0) {
        printf("\nConnection closed by server\n");
    }

    close(sockfd);
    return 0;
}