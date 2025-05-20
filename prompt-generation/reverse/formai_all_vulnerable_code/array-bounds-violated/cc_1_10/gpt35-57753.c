//FormAI DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>

#define TIMEOUT 2
#define PACKET_SIZE 64
#define MAX_HOPS 30

typedef struct {
    float rtt;
    char ip[16];
} PingResult;

void sigint_handler(int sig) {
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }
    signal(SIGINT, sigint_handler);

    struct addrinfo hints, *res;
    int sockfd, ret;
    struct timeval tv;
    char ip[16];
    int ttl = 1;
    struct sockaddr_in addr;
    socklen_t len;
    char send_packet[PACKET_SIZE] = {0};
    char recv_packet[PACKET_SIZE] = {0};
    PingResult results[MAX_HOPS];
    int i = 0;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;

    if ((ret = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
        printf("Error: %s\n", gai_strerror(ret));
        exit(1);
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    inet_ntop(AF_INET, &((struct sockaddr_in *)res->ai_addr)->sin_addr, ip, sizeof(ip));
    printf("Pinging %s [%s] with %d bytes of data:\n", argv[1], ip, PACKET_SIZE);

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &addr.sin_addr);

    while (ttl <= MAX_HOPS) {
        setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));

        int seq = 0;
        while (seq < 3) {
            gettimeofday(&tv, NULL);
            long start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
            snprintf(send_packet, PACKET_SIZE, "ping %d %d", ttl, seq);
            sendto(sockfd, send_packet, strlen(send_packet), 0, (struct sockaddr *)&addr, sizeof(addr));
            len = sizeof(addr);
            ret = recvfrom(sockfd, recv_packet, PACKET_SIZE, 0, (struct sockaddr *)&addr, &len);
            if (ret > 0) {
                gettimeofday(&tv, NULL);
                long end = tv.tv_sec * 1000 + tv.tv_usec / 1000;
                float rtt = end - start;
                recv_packet[ret] = '\0';
                char *reply_ttl = strtok(recv_packet, " ");
                char *reply_seq = strtok(NULL, " ");
                if (reply_ttl && reply_seq && atoi(reply_seq) == seq) {
                    printf("%d\t%0.3f ms\t%s\n", ttl, rtt, inet_ntoa(addr.sin_addr));
                    results[i].rtt = rtt;
                    results[i].ip[0] = '\0';
                    if (strcmp(inet_ntoa(addr.sin_addr), ip) != 0) {
                        strcpy(results[i].ip, inet_ntoa(addr.sin_addr));
                    }
                    i++;
                }
                else {
                    printf("Error: Invalid reply format: %s\n", recv_packet);
                }
            }
            else if (ret == 0) {
                continue;
            }
            else {
                printf("%d\t*\n", ttl);
            }
            seq++;
            usleep(100000);
        }
        ttl++;
        if (results[i-1].rtt < TIMEOUT) {
            break;
        }
    }

    printf("\nPing statistics:\n");
    printf("\tPackets: Sent = %d, Received = %d, Lost = %d (%d%% loss)\n", i*3, i*3, i*3, 0);
    if (i > 0) {
        printf("Approximate round trip times (in milli-seconds):\n");
        printf("\tMinimum = %0.3fms, Maximum = %0.3fms, Average = %0.3fms\n", results[0].rtt, results[i-1].rtt, 0.0);
    }
    else {
        printf("No packets received.\n");
    }

    close(sockfd);

    return 0;
}