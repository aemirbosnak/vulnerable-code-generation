//FormAI DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 4096 // Max packet size

// Function to calculate checksum
int checksum(unsigned short *ptr, int nbytes)
{
    register long sum;
    unsigned short oddbyte;
    register short answer;

    sum = 0;
    while (nbytes > 1) {
        sum += *ptr++;
        nbytes -= 2;
    }

    if (nbytes == 1) {
        oddbyte = 0;
        *((unsigned char *)&oddbyte) = *(unsigned char *)ptr;
        sum += oddbyte;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = (short)~sum;

    return answer;
}

// Structure of an ICMP header
struct icmpheader {
    unsigned char type;
    unsigned char code;
    unsigned short checksum;
    unsigned short id;
    unsigned short sequence;
    struct timeval timestamp;
};

// Send icmp packet to destination
void send_packet(int sockfd, struct sockaddr_in *dest_addr, int sequence)
{
    char packet[MAX_PACKET_SIZE];

    // Fill icmp header
    struct icmpheader *icmp_hdr = (struct icmpheader *)packet;
    icmp_hdr->type = 8; // ICMP Request (ping)
    icmp_hdr->code = 0; // Code 0
    icmp_hdr->checksum = 0;
    icmp_hdr->id = getpid() & 0xFFFF;
    icmp_hdr->sequence = sequence;
    gettimeofday(&(icmp_hdr->timestamp), NULL);

    // Calculate ICMP checksum
    int packet_size = sizeof(struct icmpheader);
    icmp_hdr->checksum = checksum((unsigned short *)icmp_hdr, packet_size);

    // Send packet
    int bytes_sent = sendto(sockfd, packet, packet_size, 0, (struct sockaddr *)dest_addr, sizeof(struct sockaddr_in));
}

// Receive icmp packet
int receive_packet(int sockfd, struct sockaddr_in *dest_addr, int sequence)
{
    char packet[MAX_PACKET_SIZE];

    // Wait for packet
    fd_set read_set;
    FD_ZERO(&read_set);
    FD_SET(sockfd, &read_set);
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    select(sockfd + 1, &read_set, NULL, NULL, &timeout);

    // Receive packet
    struct sockaddr_in from_addr;
    socklen_t from_size = sizeof(struct sockaddr_in);
    int bytes_recv = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, (struct sockaddr *)&from_addr, &from_size);
    if(bytes_recv == -1)
        return -1;

    // Parse ICMP header
    struct icmpheader *icmp_hdr = (struct icmpheader *)packet;
    if(icmp_hdr->type == 0 && icmp_hdr->id == (getpid() & 0xFFFF) && icmp_hdr->sequence == sequence)
    {
        return 1;
    }

    return 0;
}

int main(int argc, char **argv)
{
    // Get destination IP address
    if(argc < 2)
    {
        printf("Usage: %s <destination>\n", argv[0]);
        return 1;
    }
    char *destination_str = argv[1];

    // Create socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd == -1)
    {
        perror("socket");
        return 1;
    }

    // Set socket options
    int ttl = 64;
    if(setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) == -1)
    {
        perror("setsockopt");
        return 1;
    }
    int timeout = 3000;
    if(setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const void *)&timeout, sizeof(timeout)) == -1)
    {
        perror("setsockopt");
        return 1;
    }

    // Set destination
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(struct sockaddr_in));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(0);
    dest_addr.sin_addr.s_addr = inet_addr(destination_str);

    // Ping loop
    int sequence = 0;
    while(1)
    {
        sequence++;

        // Send packet
        send_packet(sockfd, &dest_addr, sequence);

        // Receive packet
        int result = receive_packet(sockfd, &dest_addr, sequence);
        if(result == -1)
        {
            printf("Timeout\n");
        }
        else if(result == 1)
        {
            printf("Received packet from %s - OK\n", destination_str);
        }
        else
        {
            printf("Received packet from %s - ERROR\n", destination_str);
        }

        // Sleep for 1 second
        sleep(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}