//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE 64

typedef struct {
    pid_t pid; 
    int seq_no; 
    struct timeval timestamp; 
} ping_packet;

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

void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    ping_packet packet;
    struct timeval receive_time, send_time;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    packet.pid = getpid();
    packet.seq_no = 1;

    while (1) {
        packet.timestamp = (struct timeval){0};
        memset(&packet.timestamp, 0, sizeof(packet.timestamp));
        gettimeofday(&send_time, NULL);

        packet.timestamp = send_time;
        packet.seq_no = htons(packet.seq_no);
        packet.seq_no = ntohs(packet.seq_no); 

        packet.seq_no = htons(packet.seq_no);
        int packet_size = sizeof(ping_packet);
        packet.timestamp = send_time;

        packet.seq_no = checksum(&packet, packet_size);

        printf("Pinging %s with sequence number %d...\n", ip_address, ntohs(packet.seq_no));

        if (sendto(sockfd, &packet, packet_size, 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Error sending packet");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        
        // Wait for a response
        socklen_t addr_len = sizeof(addr);
        char buffer[PACKET_SIZE];

        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addr_len) < 0) {
            perror("Error receiving packet");
            continue;
        }

        gettimeofday(&receive_time, NULL);
        long rtt = (receive_time.tv_sec - send_time.tv_sec) * 1000 + (receive_time.tv_usec - send_time.tv_usec) / 1000;
        printf("Received response from %s in %ld ms\n", ip_address, rtt);

        // Simulate a delay for the next ping
        sleep(1);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_Address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ping(argv[1]);
    return EXIT_SUCCESS;
}