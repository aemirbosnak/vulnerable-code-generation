//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

// Function to calculate checksum for ICMP packets
unsigned short checksum(void* b, int len) {
    unsigned short* buf = b;
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

// Function to perform the ping operation
void ping(const char* ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp packet;
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    char buffer[PACKET_SIZE];
    time_t start_time, end_time;
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);
    
    for (int i = 0; i < PING_COUNT; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.icmp_type = ICMP_ECHO;
        packet.icmp_id = getpid();
        packet.icmp_seq = i + 1;
        packet.icmp_cksum = checksum(&packet, sizeof(packet));

        start_time = time(NULL);
        
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
            perror("Send failed");
            continue;
        }

        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&r_addr, &addr_len) <= 0) {
            perror("Receive failed");
            continue;
        }
        
        end_time = time(NULL);
        double time_taken = difftime(end_time, start_time) * 1000; // time in milliseconds
        
        struct iphdr* ip_header = (struct iphdr*)buffer;
        struct icmp* icmp_response = (struct icmp*)(buffer + (ip_header->ihl << 2));
        
        if (icmp_response->icmp_type == ICMP_ECHOREPLY && icmp_response->icmp_id == packet.icmp_id) {
            printf("Ping to %s: Reply from %s: time=%.2f ms\n", ip_address, ip_address, time_taken);
        } else {
            printf("Ping to %s: Packet lost\n", ip_address);
        }

        sleep(1); // Sleep for 1 second before sending the next ping
    }

    close(sockfd);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* ip_address = argv[1];
    printf("Pinging %s:\n", ip_address);
    ping(ip_address);
    
    return 0;
}