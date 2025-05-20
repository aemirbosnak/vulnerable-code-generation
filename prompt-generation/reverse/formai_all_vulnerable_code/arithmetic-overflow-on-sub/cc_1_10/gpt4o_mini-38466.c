//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>
#include <signal.h>

#define MAX_PINGS 10
#define ICMP_ECHO 8
#define TIMEOUT 1

volatile sig_atomic_t keep_running = 1;

void handle_signal(int sig) {
    keep_running = 0;
}

unsigned short checksum(void *b, int len) {    
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF); 
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void *ping(void *ip_address) {
    struct sockaddr_in addr;
    struct icmp icmp_hdr;
    struct timeval start, end;
    int sockfd;
    int sent = 0, received = 0;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket error");
        return NULL;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr((char *)ip_address);
    
    while (keep_running && sent < MAX_PINGS) {
        memset(&icmp_hdr, 0, sizeof(icmp_hdr));
        icmp_hdr.icmp_type = ICMP_ECHO;
        icmp_hdr.icmp_id = getpid();
        icmp_hdr.icmp_seq = sent++;
        icmp_hdr.icmp_cksum = checksum(&icmp_hdr, sizeof(icmp_hdr));

        gettimeofday(&start, NULL);

        if (sendto(sockfd, &icmp_hdr, sizeof(icmp_hdr), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Send error");
            continue;
        }

        char buffer[1024];
        socklen_t addr_len = sizeof(addr);
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addr_len) > 0) {
            gettimeofday(&end, NULL);
            received++;
            long latency = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000; // latency in ms
            
            printf("Received reply from %s: time=%ld ms\n", inet_ntoa(addr.sin_addr), latency);
        } else {
            printf("Request timed out\n");
        }

        sleep(1);
    }

    close(sockfd);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, handle_signal);

    pthread_t thread;
    if (pthread_create(&thread, NULL, ping, argv[1]) != 0) {
        perror("Error creating thread");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread, NULL);
    printf("Ping operation completed.\n");

    return 0;
}