//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define MAX_PINGS 10
#define PING_SLEEP_INTERVAL 1 // seconds

void print_summary(int total_pings, int success_pings, double total_time) {
    printf("\n=== Network Quality of Service Summary ===\n");
    printf("Total pings sent: %d\n", total_pings);
    printf("Successful pings: %d\n", success_pings);
    printf("Total round-trip time: %.2f seconds\n", total_time);
    printf("Ping success rate: %.2f%%\n",
           (double)success_pings / total_pings * 100);
    printf("Thank you for using the QoS Monitor! Have a happy networking day!\n");
}

double calculate_latency(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int ping(const char *ip_address) {
    int sockfd;
    struct icmphdr icmp_hdr;
    struct sockaddr_in addr;
    char packet[64];
    memset(packet, 0, sizeof(packet));
    
    // Creating a raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket Creation Failed");
        return -1;
    }
    
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);
    
    // Prepare ICMP header
    memset(&icmp_hdr, 0, sizeof(icmp_hdr));
    icmp_hdr.type = ICMP_ECHO;
    icmp_hdr.un.echo.id = getpid();
    
    // Fill the packet with the ICMP header
    memcpy(packet, &icmp_hdr, sizeof(icmp_hdr));
    
    struct timespec start_time, end_time;
    
    // Send the packet
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&addr,
               sizeof(addr)) <= 0) {
        perror("Ping Send Failed");
        close(sockfd);
        return 0;
    }
    
    // Wait for a reply
    char buffer[1024];
    socklen_t addr_len = sizeof(addr);
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr,
                 &addr_len) < 0) {
        perror("Ping Response Failed");
        close(sockfd);
        return 0;
    }
    
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double latency = calculate_latency(start_time, end_time);
    
    printf("Ping to %s successful! Latency: %.2f ms\n",
           ip_address, latency * 1000);
    
    close(sockfd);
    return 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }
    
    const char *ip_address = argv[1];
    printf("Starting QoS Monitor for %s...\n", ip_address);
    
    int total_pings = 0;
    int success_pings = 0;
    double total_time = 0.0;

    for (int i = 0; i < MAX_PINGS; i++) {
        total_pings++;
        int result = ping(ip_address);
        
        if (result > 0) {
            success_pings++;
            total_time += 1.0; // Assuming a successful ping takes 1 second
        }
        
        sleep(PING_SLEEP_INTERVAL);
    }
    
    print_summary(total_pings, success_pings, total_time);
    
    return 0;
}