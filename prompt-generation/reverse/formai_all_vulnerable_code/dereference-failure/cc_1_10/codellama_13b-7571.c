//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define PING_DEST "www.google.com"
#define PING_SIZE 32
#define PING_TIMEOUT 2

int main(int argc, char *argv[]) {
    int sockfd, n;
    char sendbuf[PING_SIZE], recvbuf[PING_SIZE];
    struct sockaddr_in dest_addr;
    struct hostent *host;
    struct sockaddr_in sin;

    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    if ((host = gethostbyname(argv[1])) == NULL) {
        herror("gethostbyname");
        return 2;
    }

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket");
        return 3;
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = 0;
    dest_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        perror("connect");
        return 4;
    }

    memset(sendbuf, 0, PING_SIZE);
    memset(recvbuf, 0, PING_SIZE);

    for (int i = 0; i < 4; i++) {
        sendbuf[i] = i;
    }

    if ((n = send(sockfd, sendbuf, PING_SIZE, 0)) < 0) {
        perror("send");
        return 5;
    }

    if ((n = recv(sockfd, recvbuf, PING_SIZE, 0)) < 0) {
        perror("recv");
        return 6;
    }

    close(sockfd);

    if (memcmp(sendbuf, recvbuf, PING_SIZE) != 0) {
        printf("Ping failed.\n");
        return 7;
    }

    printf("Ping successful.\n");
    return 0;
}