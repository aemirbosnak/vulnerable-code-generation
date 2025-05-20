//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>

#define MAX_HOPS 30
#define TIMEOUT 5
#define BUFSIZE 1024

int main(int argc, char **argv)
{
    int sockfd, n, i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z;
    struct sockaddr_in servaddr;
    struct timeval start, end;
    char buf[BUFSIZE];
    char hostname[BUFSIZE];
    char ip[BUFSIZE];
    char hops[MAX_HOPS][BUFSIZE];
    int ttls[MAX_HOPS];
    int times[MAX_HOPS];
    int losses[MAX_HOPS];
    int jitter[MAX_HOPS];
    int rtos[MAX_HOPS];
    int cwnds[MAX_HOPS];
    int mss[MAX_HOPS];
    int bw[MAX_HOPS];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    gethostname(hostname, BUFSIZE);
    if (hostname == NULL) {
        perror("gethostname");
        exit(1);
    }

    getsockopt(sockfd, IPPROTO_IP, IP_TTL, &i, &j);
    if (i == -1) {
        perror("getsockopt");
        exit(1);
    }

    for (i = 1; i <= MAX_HOPS; i++) {
        ttls[i] = i;
        losses[i] = 0;
        jitter[i] = 0;
        rtos[i] = 0;
        cwnds[i] = 0;
        mss[i] = 0;
        bw[i] = 0;
    }

    for (i = 1; i <= MAX_HOPS; i++) {
        if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttls[i], sizeof(ttls[i])) == -1) {
            perror("setsockopt");
            exit(1);
        }

        gettimeofday(&start, NULL);
        n = send(sockfd, buf, BUFSIZE, 0);
        if (n == -1) {
            perror("send");
            exit(1);
        }

        gettimeofday(&end, NULL);
        times[i] = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;

        n = recv(sockfd, buf, BUFSIZE, 0);
        if (n == -1) {
            perror("recv");
            exit(1);
        }

        if (i > 1) {
            jitter[i] = times[i] - times[i - 1];
        }

        if (i == 1) {
            rtos[i] = times[i];
        } else {
            rtos[i] = rtos[i - 1] + jitter[i];
        }

        cwnds[i] = rtos[i] * bw[i] / 1000;

        mss[i] = n;

        bw[i] = n * 8000 / times[i];
    }

    printf("Hostname: %s\n", hostname);
    printf("IP: %s\n", ip);
    printf("Hops: %d\n", i - 1);
    for (i = 1; i <= MAX_HOPS; i++) {
        if (losses[i] == 0) {
            printf("Hop %d: %s\n", i, hops[i]);
            printf("TTL: %d\n", ttls[i]);
            printf("Time: %d ms\n", times[i]);
            printf("Jitter: %d ms\n", jitter[i]);
            printf("RTO: %d ms\n", rtos[i]);
            printf("CWND: %d\n", cwnds[i]);
            printf("MSS: %d bytes\n", mss[i]);
            printf("Bandwidth: %d Kbps\n", bw[i]);
            printf("\n");
        }
    }

    close(sockfd);

    return 0;
}