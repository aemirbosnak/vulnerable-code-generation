//FormAI DATASET v1.0 Category: Network Ping Test ; Style: post-apocalyptic
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/time.h> 
#include <unistd.h> 
#include <netinet/in.h> 
#include <netinet/ip_icmp.h> 

#define PACKET_SIZE     56 
#define MAX_WAIT_TIME   5 
#define MAX_NO_PACKETS  3 

struct Packet 
{ 
    struct icmphdr hdr; 
    char msg[PACKET_SIZE - sizeof(struct icmphdr)]; 
}; 

int main(int argc, char *argv[]) 
{ 
    int sockfd, sent, rcvd, i, sockopt; 
    socklen_t addrlen; 
    struct timeval tv_begin, tv_end, tv_interval; 
    struct sockaddr_in sendaddr, recvaddr; 
    struct Packet packet; 
    struct timezone tz; 
    fd_set readfds; 

    if (argc != 2) 
    { 
        printf("Usage: %s IP address\n", argv[0]); 
        exit(1); 
    } 

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); 
    if (sockfd < 0) 
    { 
        printf("socket() error\n"); 
        exit(1); 
    } 

    memset(&sendaddr, 0, sizeof(struct sockaddr_in)); 
    sendaddr.sin_family = AF_INET; 
    sendaddr.sin_addr.s_addr = inet_addr(argv[1]); 

    sockopt = 64; 
    setsockopt(sockfd, SOL_IP, IP_TTL, &sockopt, sizeof(sockopt)); 
    printf("PING %s (%s) %d bytes of data.\n", argv[1], 
        inet_ntoa(sendaddr.sin_addr), PACKET_SIZE); 

    for (i = 0; i < MAX_NO_PACKETS; i++) 
    { 
        memset(&packet, 0, sizeof(packet)); 
        gettimeofday(&tv_begin, &tz); 
        packet.hdr.type = ICMP_ECHO; 
        packet.hdr.code = 0; 
        packet.hdr.checksum = htons(~(ICMP_ECHO << 8)); 
        packet.hdr.un.echo.id = getpid(); 
        packet.hdr.un.echo.sequence = i; 
        memset(packet.msg, 'A', sizeof(packet.msg)); 
        if (sendto(sockfd, &packet, PACKET_SIZE, 0, 
            (struct sockaddr*)&sendaddr, sizeof(sendaddr)) < 0) 
        { 
            printf("sendto() error\n"); 
            continue; 
        } 

        addrlen = sizeof(recvaddr); 
        FD_ZERO(&readfds); 
        FD_SET(sockfd, &readfds); 

        if (select(sockfd + 1, &readfds, NULL, NULL, 
            &tv_interval) == 0) 
        { 
            printf("Request timed out.\n"); 
            continue; 
        } 

        rcvd = recvfrom(sockfd, &packet, 
            PACKET_SIZE, 0, (struct sockaddr*)&recvaddr, &addrlen); 

        if (rcvd < 0) 
        { 
            printf("recvfrom() error\n"); 
            continue; 
        } 

        gettimeofday(&tv_end, &tz); 
        tv_interval.tv_sec = tv_end.tv_sec - tv_begin.tv_sec; 
        tv_interval.tv_usec = tv_end.tv_usec - tv_begin.tv_usec; 
        if (tv_interval.tv_usec < 0) 
        { 
            tv_interval.tv_sec--; 
            tv_interval.tv_usec += 1000000; 
        } 

        printf("%d bytes from %s: icmp_seq=%u ttl=%d time=%.1f ms\n", rcvd, 
            inet_ntoa(recvaddr.sin_addr), packet.hdr.un.echo.sequence, 
            sockopt, tv_interval.tv_sec*1000.0+tv_interval.tv_usec/1000.0); 

        sleep(1); 
    } 

    close(sockfd); 

    return 0; 
}