//FormAI DATASET v1.0 Category: Network Ping Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define PACKET_SIZE 4096
#define MAX_WAIT_TIME 5
#define MAX_NO_PACKETS 3

int main(int argc, char *argv[]) {
    struct timeval tvstart, tvrecv;
    struct sockaddr_in addr;
    struct icmp *icmp;
    int sockfd, i, sendnum = 0, recvnum = 0;
    int packetsize = sizeof(struct icmp) + sizeof(struct timeval);
    char sendpacket[PACKET_SIZE], recvpacket[PACKET_SIZE];
    pid_t pid = getpid();

    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    printf("\nPING %s (%s) %d bytes of data.\n\n", argv[1], inet_ntoa(addr.sin_addr), sizeof(recvpacket));

    for (i = 0; i < MAX_NO_PACKETS; i++) {
        sendnum++;
        icmp = (struct icmp *) sendpacket;
        icmp->icmp_type = ICMP_ECHO;
        icmp->icmp_code = 0;
        icmp->icmp_id = pid;
        icmp->icmp_seq = i;
        gettimeofday((struct timeval *) icmp->icmp_data, NULL);
        if (sendto(sockfd, sendpacket, packetsize, 0, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
            perror("sendto()");
            continue;
        }
        printf("Sending packet %d to %s.\n", sendnum, argv[1]);
        if (recvfrom(sockfd, recvpacket, sizeof(recvpacket), 0, NULL, NULL) < 0) {
            perror("recvfrom()");
            continue;
        }
        recvnum++;
        gettimeofday(&tvrecv, NULL);

        icmp = (struct icmp *) recvpacket;
        if (icmp->icmp_type == ICMP_ECHOREPLY && icmp->icmp_id == pid && icmp->icmp_seq == i) {
            printf("Received packet %d from %s: time=%ldms.\n", recvnum, argv[1], (tvrecv.tv_sec - ((struct timeval *) icmp->icmp_data)->tv_sec) * 1000 + (tvrecv.tv_usec - ((struct timeval *) icmp->icmp_data)->tv_usec) / 1000);
        } else {
            printf("Error: packet %d wrong.\n", recvnum);
        }

        sleep(1);
    }

    printf("\n--- %s ping statistics ---\n", argv[1]);
    printf("%d packets transmitted, %d received, %.2f%% packet loss.\n", sendnum, recvnum, (float) (sendnum - recvnum) / sendnum * 100);

    return 0;
}