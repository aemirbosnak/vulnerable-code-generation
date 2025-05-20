//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <errno.h>
#include <signal.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

// Structure to store the ping results
struct ping_result {
    int seq_number;
    double rtt;
};

void signal_handler(int signo) {
    if (signo == SIGINT) {
        printf("\nPing test interrupted by user.\n");
        exit(0);
    }
}

// Computes checksum for the ICMP packet
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

// Function to execute the ping
void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp packet;
    struct ping_result results[PING_COUNT];
    struct timeval start_time, end_time;
    socklen_t addrlen = sizeof(addr);
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    for (int i = 0; i < PING_COUNT; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.icmp_type = ICMP_ECHO;
        packet.icmp_code = 0;
        packet.icmp_seq = htons(i + 1);
        packet.icmp_id = htons(getpid());
        packet.icmp_cksum = checksum(&packet, sizeof(packet));

        gettimeofday(&start_time, NULL);
        
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        char buffer[PACKET_SIZE];
        if (recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&addr, &addrlen) < 0) {
            perror("Receive failed");
            results[i].seq_number = i + 1;
            results[i].rtt = -1.0; // Indicate timeout
            continue;
        }

        gettimeofday(&end_time, NULL);
        double rtt = (double)(end_time.tv_sec - start_time.tv_sec) * 1000.0 + 
                     (double)(end_time.tv_usec - start_time.tv_usec) / 1000.0;

        results[i].seq_number = i + 1;
        results[i].rtt = rtt;
    }

    close(sockfd);

    // Output the ping results
    printf("\n--- PING Test Results for %s ---\n", ip_addr);
    for (int i = 0; i < PING_COUNT; i++) {
        if (results[i].rtt == -1.0)
            printf("Ping %d: Request timed out.\n", results[i].seq_number);
        else
            printf("Ping %d: RTT = %.2f ms\n", results[i].seq_number, results[i].rtt);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Set up signal handler for graceful exit
    signal(SIGINT, signal_handler);

    ping(argv[1]);
    
    return EXIT_SUCCESS;
}