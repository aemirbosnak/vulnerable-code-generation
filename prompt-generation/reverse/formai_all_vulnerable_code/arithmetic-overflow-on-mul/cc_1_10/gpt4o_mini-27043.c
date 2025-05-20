//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <sys/time.h>

#define PACKET_SIZE     64
#define PING_COUNT      10
#define TIMEOUT         1

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

volatile sig_atomic_t stop;

void handle_alarm(int signum) {
    stop = 1; // Stop the program
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char*)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

long ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr;
    struct ping_packet packet;
    struct timeval start, end;
    int n_transmitted = 0, n_received = 0;
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    for (int i = 0; i < PING_COUNT; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.hdr.type = ICMP_ECHO;
        packet.hdr.un.echo.id = getpid();
        packet.hdr.un.echo.sequence = i + 1;
        packet.hdr.checksum = checksum(&packet, sizeof(packet));

        gettimeofday(&start, NULL);
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("sendto");
            continue;
        }
        n_transmitted++;

        // Set signal handler for timeout
        signal(SIGALRM, handle_alarm);
        alarm(TIMEOUT);
        
        struct sockaddr_in r_addr;
        socklen_t addr_len = sizeof(r_addr);
        if (recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&r_addr, &addr_len) > 0) {
            gettimeofday(&end, NULL);
            long rtt = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
            printf("Reply from %s: bytes=%d time=%ld ms\n", ip_addr, PACKET_SIZE, rtt);
            n_received++;
            stop = 0; // Reset stop condition
        } else if (stop != 1) {
            printf("Request timed out.\n");
        }
        alarm(0); // Cancel the alarm
        sleep(1);
    }

    close(sockfd);
    return ((n_transmitted - n_received) * 100.0 / n_transmitted);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_addr = argv[1];
    printf("Pinging %s with %d packets:\n", ip_addr, PING_COUNT);

    float packet_loss = ping(ip_addr);
    printf("\n--- %s ping statistics ---\n", ip_addr);
    printf("%d packets transmitted, %d received, %.2f%% packet loss\n",
           PING_COUNT, PING_COUNT - (int)packet_loss, packet_loss);
    
    return 0;
}