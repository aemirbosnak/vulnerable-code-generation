//FormAI DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define PORT 80
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    struct hostent *host;
    struct sockaddr_in addr;
    int sockfd, i, len, timeout = TIMEOUT;
    fd_set fds;
    char *hostname, *ptr, buffer[BUF_SIZE];

    if (argc < 2) {
        printf("Usage: %s hostname [timeout]\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];

    if (argc == 3) {
        if (isdigit(*argv[2])) {
            timeout = atoi(argv[2]);
        } else {
            printf("Timeout argument must be a number\n");
            exit(1);
        }
    }

    host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Could not resolve hostname %s\n", hostname);
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    memcpy(&addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sockfd < 0) {
        printf("Could not create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Could not connect to %s:%d\n", hostname, PORT);
        exit(1);
    }

    ptr = inet_ntoa(addr.sin_addr);
    printf("PING %s (%s): %d data bytes\n", hostname, ptr, BUF_SIZE);

    for (i = 1; i <= 10; i++) {
        memset(buffer, 'A', BUF_SIZE);
        len = send(sockfd, buffer, BUF_SIZE, 0);
        if (len <= 0) {
            printf("Error sending data to %s\n", hostname);
            close(sockfd);
            exit(1);
        }
        printf("%d bytes from %s: icmp_seq=%d ttl=64 time=%dms\n",
                BUF_SIZE, ptr, i, timeout);
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);
        struct timeval tv = {timeout, 0};
        int ret = select(sockfd+1, &fds, NULL, NULL, &tv);
        if (ret < 0) {
            printf("Select error on socket\n");
            close(sockfd);
            exit(1);
        } else if (ret == 0) {
            printf("No response from %s\n", hostname);
        } else {
            len = recv(sockfd, buffer, BUF_SIZE, 0);
            if (len <= 0) {
                printf("Error receiving data from %s\n", hostname);
                close(sockfd);
                exit(1);
            }
            printf("%d bytes from %s: icmp_seq=%d ttl=64 time=%dms\n",
                    len, ptr, i, timeout);
        }
        sleep(1);
    }

    close(sockfd);
    return 0;
}