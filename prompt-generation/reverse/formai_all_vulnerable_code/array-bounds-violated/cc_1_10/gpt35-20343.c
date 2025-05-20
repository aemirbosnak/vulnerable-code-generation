//FormAI DATASET v1.0 Category: Network Ping Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <time.h>

#define PACKET_SIZE 64
#define PORT_NO 0
#define PING_TIMEOUT 1
#define MAX_PING_RESPONSE_TIME 1000 

unsigned short calculate_checksum(unsigned short *data, int length);

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct timeval timeout = {PING_TIMEOUT, 0};
    int sequence_no = 0;
    fd_set readfds;
    int i;
    char packet[PACKET_SIZE];
    struct icmphdr *icmp_header = (struct icmphdr*)packet;

    if(argc != 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 0;
    }

    // Open a socket and set it in raw mode
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0) {
        perror("socket");
        return 0;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT_NO);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Set the timeout for the socket
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    // Start sending ping requests
    while(1) {
        // Prepare the ICMP packet
        memset(packet, 0, PACKET_SIZE);
        icmp_header->type = ICMP_ECHO;
        icmp_header->code = 0;
        icmp_header->checksum = 0;
        icmp_header->un.echo.id = getpid();
        icmp_header->un.echo.sequence = sequence_no++;
        for(i = 0; i < sizeof(packet); i++)
            packet[sizeof(struct icmphdr) + i] = i % 10 + '0';
        icmp_header->checksum = calculate_checksum((unsigned short*)packet, sizeof(packet));

        if(sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr*)&server_addr, sizeof(server_addr)) <= 0) {
            perror("sendto");
            break;
        }

        // Wait for a ping response
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        if(select(sockfd+1, &readfds, NULL, NULL, &timeout) <= 0) {
            printf("Request timed out for sequence %d\n", sequence_no-1);
        }
        else {
            // Receive the response and calculate response time
            struct timeval t1, t2;
            gettimeofday(&t1, NULL);
            char recv_packet[PACKET_SIZE];
            struct sockaddr_in rcv_addr;
            int rcv_addr_len = sizeof(rcv_addr);
            if(recvfrom(sockfd, recv_packet, sizeof(recv_packet), 0, (struct sockaddr*)&rcv_addr, &rcv_addr_len) > 0) {
                gettimeofday(&t2, NULL);
                if((t2.tv_sec - t1.tv_sec) * 1000 + (t2.tv_usec - t1.tv_usec) / 1000 < MAX_PING_RESPONSE_TIME) {
                    printf("Response received from %s for sequence %d\n", inet_ntoa(rcv_addr.sin_addr), sequence_no-1);
                }
            }
        }

        sleep(1);
    }

    close(sockfd);

    return 0;
}

// Checksum calculation function
unsigned short calculate_checksum(unsigned short *data, int length) {
    unsigned int sum = 0;
    unsigned short *ptr = data;

    while(length > 1) {
        sum += *ptr++;
        length -= 2;
    }

    if(length == 1)
        sum += *((unsigned char*)ptr);

    while(sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);

    return ~sum;
}