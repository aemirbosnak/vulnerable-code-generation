//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFSIZE 1024
#define MAXRECV 10
#define MAXTIMEOUT 100

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[BUFFSIZE], recvline[BUFFSIZE];
    struct timeval start, stop;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    while (1) {
        printf("> ");
        fgets(sendline, BUFFSIZE, stdin);
        if (sendto(sockfd, sendline, strlen(sendline), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
            perror("sendto");
            exit(1);
        }

        gettimeofday(&start, NULL);
        for (n = 0; n < MAXRECV; n++) {
            if ((n = recvfrom(sockfd, recvline, BUFFSIZE, 0, NULL, NULL)) < 0) {
                perror("recvfrom");
                exit(1);
            }
            gettimeofday(&stop, NULL);
            double elapsed = (stop.tv_sec - start.tv_sec) + (stop.tv_usec - start.tv_usec) / 1000000.0;
            printf("%s\n", recvline);
            printf("Elapsed time: %f ms\n", elapsed);
            if (n == BUFFSIZE) {
                break;
            }
        }
        if (n == 0) {
            printf("Timeout\n");
        }

        if (gettimeofday(&start, NULL) < 0) {
            perror("gettimeofday");
            exit(1);
        }
        if (stop.tv_sec - start.tv_sec > MAXTIMEOUT) {
            printf("Connection timed out\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}