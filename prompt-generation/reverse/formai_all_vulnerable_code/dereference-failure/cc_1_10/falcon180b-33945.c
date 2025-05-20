//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOST_LEN 1025
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    int opt = 1;
    struct sockaddr_in servaddr;
    char buffer[BUF_SIZE];
    char hostname[MAX_HOST_LEN];

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket failed\n");
        return 1;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(7);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error: connect failed\n");
        close(sockfd);
        return 1;
    }

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Host is down\n");
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}