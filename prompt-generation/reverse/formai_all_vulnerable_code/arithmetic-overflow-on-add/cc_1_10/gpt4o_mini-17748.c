//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define MAX_NO_PACKET 5
#define TIMEOUT_INTERVAL 1

// Function to calculate checksum
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to send ICMP echo request
int ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct icmp *icmp_packet;
    char packet[PACKET_SIZE];
    struct timeval timeout;
    fd_set fdset;
    int addr_len, sent_packets = 0, received_packets = 0;
    clock_t start_time, end_time;
    
    // Create ICMP socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set timeout for socket
    timeout.tv_sec = TIMEOUT_INTERVAL;
    timeout.tv_usec = 0;

    strcpy(packet, "Ping Packet");
    icmp_packet = (struct icmp *) packet;
    icmp_packet->icmp_type = ICMP_ECHO;
    icmp_packet->icmp_code = 0;
    icmp_packet->icmp_id = getpid();
    icmp_packet->icmp_seq = 1;
    icmp_packet->icmp_cksum = checksum(icmp_packet, sizeof(packet));

    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);
    
    // Send packets to the target
    for (int i = 0; i < MAX_NO_PACKET; i++) {
        sent_packets++;
        start_time = clock();
        
        if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Send failed");
            continue;
        }

        // Wait for a reply
        FD_ZERO(&fdset);
        FD_SET(sockfd, &fdset);
        if (select(sockfd + 1, &fdset, NULL, NULL, &timeout) > 0) {
            unsigned char buffer[PACKET_SIZE];
            addr_len = sizeof(addr_ping);
            
            // Receive the reply
            if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr_ping, &addr_len) < 0) {
                perror("Receive failed");
            } else {
                end_time = clock();
                received_packets++;
                struct iphdr *ip_header = (struct iphdr *)buffer;
                struct icmp *icmp_response = (struct icmp *)(buffer + (ip_header->ihl * 4));
                
                if (icmp_response->icmp_type == ICMP_ECHOREPLY) {
                    printf("Received reply from %s: seq=%d time=%.2f ms\n", ip_address, icmp_response->icmp_seq, ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);
                }
            }
        } else {
            printf("Request timed out\n");
        }

        sleep(1); // Wait before sending the next ping
    }

    printf("--- %s ping statistics ---\n", ip_address);
    printf("%d packets transmitted, %d received, %.2f%% packet loss\n", sent_packets, received_packets, (sent_packets - received_packets) * 100.0 / sent_packets);

    close(sockfd);
    return (received_packets > 0) ? 0 : -1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *ip_address = argv[1];
    if (ping(ip_address) == -1) {
        fprintf(stderr, "Ping failed for %s\n", ip_address);
        exit(EXIT_FAILURE);
    }

    return 0;
}