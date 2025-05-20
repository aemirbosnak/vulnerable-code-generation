//FormAI DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE 64
#define RECEIVE_TIMEOUT 2
#define IP_HEADER_SIZE 20
#define ICMP_HEADER_SIZE 8

unsigned short checksum(unsigned short *ptr, int length) {
    unsigned int sum = 0;
    unsigned short odd_byte = 0;

    while (length > 1) {
        sum += *ptr++;
        length -= 2;
    }
    
    if (length == 1) {
        *(unsigned char *)(&odd_byte) = *(unsigned char *)ptr;
        sum += odd_byte;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >>16);
    return (unsigned short)(~sum);
}

int send_ping(int sockfd, struct sockaddr_in dest_addr, int sequence_number) {
    char packet[PACKET_SIZE];
    struct icmp *icmp_header = (struct icmp *)packet;
    
    icmp_header->icmp_type = ICMP_ECHO;
    icmp_header->icmp_code = 0;
    icmp_header->icmp_id = htons(getpid() & 0xFFFF);
    icmp_header->icmp_seq = htons(sequence_number);
    memset(packet + ICMP_HEADER_SIZE, 'x', PACKET_SIZE - ICMP_HEADER_SIZE);
    icmp_header->icmp_cksum = checksum((unsigned short *)packet, PACKET_SIZE);
    
    struct timeval start_time;
    gettimeofday(&start_time, NULL);
    int bytes_sent = sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
    
    if (bytes_sent == -1) {
        printf("Unable to send packet\n");
        return -1;
    }

    return start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
}

int receive_ping(int sockfd, struct sockaddr_in *sender_addr) {
    char buffer[PACKET_SIZE];
    struct iphdr *ip_header;
    struct icmp *icmp_header;
    struct timeval receive_time;
    socklen_t sender_addr_len = sizeof(struct sockaddr);
    
    fd_set descriptors;
    FD_ZERO(&descriptors);
    FD_SET(sockfd, &descriptors);
    
    struct timeval timeout;
    timeout.tv_sec = RECEIVE_TIMEOUT;
    timeout.tv_usec = 0;
    
    select(sockfd + 1, &descriptors, NULL, NULL, &timeout);
    if (FD_ISSET(sockfd, &descriptors)) {
        int bytes_received = recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)sender_addr, &sender_addr_len);
        gettimeofday(&receive_time, NULL);
        
        ip_header = (struct iphdr *)(buffer);
        unsigned int ip_header_len = ip_header->ihl * 4;
        
        icmp_header = (struct icmp *)(buffer + ip_header_len);
        
        if (icmp_header->icmp_type == ICMP_ECHOREPLY) {
            return receive_time.tv_sec * 1000 + receive_time.tv_usec / 1000;
        }
    }
    
    return -1;
}

void print_results(struct sockaddr_in dest_addr, long int start_time, long int end_time) {
    unsigned char *ip = (unsigned char *)&dest_addr.sin_addr.s_addr;
    printf("Ping result for %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    
    if (end_time == -1) {
        printf("Host is not responding\n");
        return;
    }
    
    printf("Received reply in %ld ms\n", end_time - start_time);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ./ping <host>\n");
        return -1;
    }
    
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    
    if (sockfd < 0) {
        printf("Unable to create socket\n");
        return -1;
    }
    
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    
    if (inet_pton(AF_INET, argv[1], &dest_addr.sin_addr) <= 0) {
        printf("Invalid address\n");
        return -1;
    }
    
    int sequence_number = 0;
    int failures = 0;
    
    while (sequence_number < 5) {
        long int start_time = send_ping(sockfd, dest_addr, sequence_number);
        
        if (start_time == -1) {
            failures++;
            sequence_number++;
            continue;
        }
        
        long int end_time = receive_ping(sockfd, &dest_addr);
        if (end_time == -1) {
            failures++;
        }
        
        print_results(dest_addr, start_time, end_time);
        sequence_number++;
        sleep(1);
    }
    
    printf("%d out of 5 packets failed to reach the destination\n", failures);
    
    close(sockfd);
    return 0;
}