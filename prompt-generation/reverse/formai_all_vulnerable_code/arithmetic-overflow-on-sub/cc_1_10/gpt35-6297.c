//FormAI DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<netinet/ip_icmp.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<unistd.h>

#define PACKET_SIZE 64

unsigned short checksum(void *b, int len){
    unsigned short *buf = b;
    unsigned int sum=0;
    unsigned short result;

    for(sum=0; len>1; len-=2){
        sum += *buf++;
    }
    if(len==1){
        sum += *(unsigned char*)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >>16);
    result = ~sum;

    return result;
}

float timediff(struct timeval *begin, struct timeval *end){
    int n;
    n = (end->tv_sec - begin->tv_sec) * 1000000 + (end->tv_usec - begin->tv_usec);
    return (float) (n/1000)/1000;
}

void ping(char *ip){
    struct sockaddr_in addr_ping;
    int sockfd, flag = 1, ttl = 64, count = 0;
    char sendbuf[PACKET_SIZE], rcvbuf[PACKET_SIZE];
    double total_time = 0;
    struct timeval start, end;
    struct iphdr *iph;
    struct icmphdr *icmph;
    struct timeval *tvsend, *tvrcv;
    struct hostent *host;

    bzero(&addr_ping, sizeof(addr_ping));
    addr_ping.sin_addr.s_addr = inet_addr(ip);
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0){
        perror("socket");
        exit(1);
    }
    setuid(getuid());
    printf("PING %s (%s):\n", ip, inet_ntoa(addr_ping.sin_addr));

    while(flag){ 
        bzero(sendbuf, PACKET_SIZE); 
        memset(sendbuf, 'a', 56); 
        gettimeofday(&start, NULL); 
        tvsend = (struct timeval *)sendbuf; 
        tvsend -> tv_sec = start.tv_sec; 
        tvsend -> tv_usec = start.tv_usec; 
        icmph = (struct icmphdr *)(sendbuf + sizeof(struct timeval)); 
        icmph -> type = ICMP_ECHO; 
        icmph -> code = 0; 
        icmph -> checksum = 0; 
        icmph -> un.echo.id = getpid(); 
        icmph -> un.echo.sequence = count++; 
        icmph -> checksum = checksum(icmph, PACKET_SIZE - sizeof(struct timeval));
        sendto(sockfd, sendbuf, PACKET_SIZE, 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping));
        int len = sizeof(addr_ping);
        bzero(rcvbuf, PACKET_SIZE);
        if(recvfrom(sockfd, rcvbuf, PACKET_SIZE, 0, (struct sockaddr *)&addr_ping, &len) <= 0){
            perror("recvfrom()");
            continue;
        }
        gettimeofday(&end, NULL);
        total_time += timediff(&start, &end);
        tvrcv = (struct timeval *)rcvbuf; 
        iph = (struct iphdr *)rcvbuf; 
        icmph = (struct icmphdr *)(rcvbuf + iph -> ihl * 4); 
        if(icmph -> type == ICMP_ECHOREPLY){
            printf("%d byte from %s: icmp_seq=%u ttl=%d time=%.3f ms\n", PACKET_SIZE, inet_ntoa(addr_ping.sin_addr), icmph -> un.echo.sequence, ttl, timediff(tvsend, tvrcv));
        }
        else{
            printf("no response from %s\n", ip);
        }
        sleep(1);
    }
    printf("avg time=%.3f ms\n", total_time / count); 
    close(sockfd); 
}

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s <ip address>\n", argv[0]);
        exit(1);
    }
    ping(argv[1]);
    return 0;
}