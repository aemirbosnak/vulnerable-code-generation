//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

struct sockaddr_in target;
int sockfd;

int main(int argc, char *argv[])
{
    int opt = 1;
    int max_sockets = 1024;
    int *sockets = (int *)malloc(max_sockets * sizeof(int));
    int num_sockets = 0;
    int max_threads = 1024;
    pthread_t threads[max_threads];

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port;

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    while (num_sockets < max_sockets) {
        int port = start_port;
        while (port <= end_port) {
            target.sin_family = AF_INET;
            target.sin_addr.s_addr = inet_addr(ip_address);
            target.sin_port = htons(port);

            if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == 0) {
                close(sockfd);
                printf("Port %d is open\n", port);
            } else {
                printf("Port %d is closed\n", port);
            }

            port++;
        }
        start_port++;
    }

    return 0;
}