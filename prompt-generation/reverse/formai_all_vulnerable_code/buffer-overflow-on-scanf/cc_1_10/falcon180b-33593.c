//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    int sockfd, portno, retval, i, maxfd;
    struct sockaddr_in target;
    fd_set masterfds, readfds;

    char buffer[BUF_SIZE];
    int maxi = 0;

    printf("Enter the IP address of the host: ");
    scanf("%s", argv[1]);

    printf("Enter the port range (e.g. 1-1024): ");
    scanf("%d-%d", &portno, &maxi);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket!");
        exit(1);
    }

    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);

    for (i = portno; i <= maxi; i++) {
        target.sin_port = htons(i);
        retval = connect(sockfd, (struct sockaddr *)&target, sizeof(target));

        if (retval == -1) {
            printf("Port %d is closed\n", i);
        } else {
            printf("Port %d is open\n", i);
            close(sockfd);
        }
    }

    return 0;
}