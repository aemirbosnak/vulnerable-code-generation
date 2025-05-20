//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 7654
#define BUFSIZE 1024

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;
    char sendline[BUFSIZE], recvline[BUFSIZE];
    int n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <command>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    snprintf(sendline, sizeof(sendline), "%s", argv[2]);
    if (sendto(sockfd, sendline, strlen(sendline), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("sendto");
        exit(1);
    }

    if ((n = recvfrom(sockfd, recvline, sizeof(recvline), 0, NULL, NULL)) < 0) {
        perror("recvfrom");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s\n", recvline);

    close(sockfd);
    return 0;
}