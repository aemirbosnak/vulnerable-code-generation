//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>
#include <errno.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define MAX_IP_RANGE 255

// Function to calculate the checksum
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

// Function to send an ICMP echo request
int send_ping(const char *ip_address) {
    int sockfd;
    struct icmp packet;
    struct sockaddr_in addr;
    struct timeval start, end;
    double time_taken;
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&packet, 0, sizeof(packet));
    packet.icmp_type = ICMP_ECHO;
    packet.icmp_code = 0;
    packet.icmp_seq = htons(1);
    packet.icmp_id = htons(getpid());
    packet.icmp_cksum = checksum(&packet, sizeof(packet));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    gettimeofday(&start, NULL);
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
        perror("Send failed");
        close(sockfd);
        return -1;
    }

    fd_set readfds;
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    if (select(sockfd + 1, &readfds, NULL, NULL, &tv) > 0) {
        char buf[PACKET_SIZE];
        socklen_t len = sizeof(addr);
        if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, &len) < 0) {
            perror("Receive failed");
        } else {
            gettimeofday(&end, NULL);
            time_taken = (end.tv_sec - start.tv_sec) * 1.0 + (end.tv_usec - start.tv_usec) / 1000000.0;
            printf("Ping to %s: time=%.2f ms\n", ip_address, time_taken * 1000);
        }
    } else {
        printf("Request timed out for %s\n", ip_address);
    }

    close(sockfd);
    return 0;
}

// Main function to iterate through the network range
int main() {
    char ip_prefix[16];
    printf("Enter the IP prefix (e.g., 192.168.1.): ");
    fgets(ip_prefix, sizeof(ip_prefix), stdin);
    ip_prefix[strcspn(ip_prefix, "\n")] = 0;  // Remove newline character

    for (int i = 1; i <= MAX_IP_RANGE; i++) {
        char ip_address[16];
        snprintf(ip_address, sizeof(ip_address), "%s%d", ip_prefix, i);
        send_ping(ip_address);
    }

    return 0;
}