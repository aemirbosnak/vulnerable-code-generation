//FormAI DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0
#define MAX_TRIES 4

// Calculates the checksum
unsigned short checksum(void *msg, int msg_size){
    unsigned short *buf = (unsigned short *)msg;
    unsigned int sum = 0, i;
    for(i = 0; i < msg_size/2; i++) 
        sum += buf[i];
    if(msg_size%2 != 0) 
        sum+= ((unsigned short) ((unsigned char *)msg)[msg_size-1]) << 8;
    while (sum >> 16)
        sum = (sum & 0xFFFF)+(sum >> 16);
    return ~sum;
}

void ping(char* ip_addr){
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    inet_aton(ip_addr, &addr.sin_addr);
    int sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sock_fd < 0){
        printf("Unable to open socket or create socket failed!\n");
        exit(1);
    }
    int ttl = 64;
    if (setsockopt(sock_fd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0){
        printf("Setting socket options failed\n");
        exit(1);
    }
    char buffer[PACKET_SIZE];
    memset(buffer, 0, PACKET_SIZE);
    struct icmphdr *icmp;
    icmp = (struct icmphdr *)(buffer);
    icmp->type = ICMP_ECHO_REQUEST;
    icmp->code = 0;
    icmp->un.echo.id = getpid();
    icmp->un.echo.sequence = 0;
    icmp->checksum = 0;
    icmp->checksum = checksum(buffer, PACKET_SIZE);
    struct timeval send_time, recv_time;
    gettimeofday(&send_time, NULL);
    if (sendto(sock_fd, buffer, PACKET_SIZE, 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0){
        printf("Failed to send the packet\n");
    }
    char recv_buff[PACKET_SIZE];
    int addr_length = sizeof(addr);
    int tries = 0;
    while(tries < MAX_TRIES) {
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sock_fd, &fds);
        struct timeval tv = {0, 500000};
        int rc = select(sock_fd+1, &fds, NULL, NULL, &tv);
        switch (rc) {
            case -1:
                printf("Select error occurred!\n");
                return;
            case 0:
                printf("Timeout waiting for ICMP packets!\n");
                tries++;
                continue;
        }
        if(recvfrom(sock_fd, recv_buff, PACKET_SIZE, 0, (struct sockaddr*)&addr, &addr_length) < 0){
            printf("Failed to receive any data!\n");
            return;
        }
        gettimeofday(&recv_time, NULL);
        struct icmphdr *recv_icmp;
        recv_icmp = (struct icmphdr *)(recv_buff);
        if(recv_icmp->type == ICMP_ECHO_REPLY){
            printf("Received ping response with %d bytes from %s: icmp_seq=%d ttl=%d time=%ld ms\n", PACKET_SIZE, ip_addr, recv_icmp->un.echo.sequence, ttl, (recv_time.tv_sec - send_time.tv_sec) * 1000 + (recv_time.tv_usec - send_time.tv_usec) / 1000);
            return;
        }
    }
    printf("Ping to IP address %s failed: No response received after %d tries.\n", ip_addr, tries);
}


int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }
    printf("Starting Ping Test:\n");
    ping(argv[1]);
    printf("\nPing Test Completed.\n");
    return 0;
}