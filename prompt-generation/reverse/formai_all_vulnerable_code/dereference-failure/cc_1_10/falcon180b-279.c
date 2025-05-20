//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT 80
#define MAX 100

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    struct hostent *he;
    struct sockaddr_in serv_addr;
    char buffer[MAX];
    int i, j;
    char *ip;

    if (argc!= 2) {
        printf("Usage:./ping <IP Address>\n");
        exit(0);
    }

    ip = argv[1];

    if ((he = gethostbyname(ip)) == NULL) {
        printf("No such host\n");
        exit(0);
    }

    if (he->h_addrtype == AF_INET) {
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("socket failed");
            exit(0);
        }

        bzero(&serv_addr, sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        bcopy(he->h_addr, &serv_addr.sin_addr, he->h_length);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("connect failed");
            exit(0);
        }

        printf("Connected to %s\n", ip);

        while (TRUE) {
            memset(buffer, 0, MAX);

            if ((numbytes = read(sockfd, buffer, MAX)) < 0) {
                perror("read failed");
                exit(0);
            }

            printf("%s", buffer);

            if (strstr(buffer, "</html>")) {
                printf("\nPing Successful\n");
                break;
            }
        }

        close(sockfd);
    } else {
        printf("Unknown host address type\n");
        exit(0);
    }

    return 0;
}