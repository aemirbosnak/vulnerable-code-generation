//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: mathematical
#include <stdio.h>        // Including standard input and output library
#include <stdlib.h>       // Including standard library for memory allocation
#include <unistd.h>       // Including standard symbolic constants and types
#include <string.h>       // Including string manipulation functions
#include <arpa/inet.h>    // Including definitions for internet operations
#include <sys/types.h>    // Including definitions for data types
#include <sys/socket.h>   // Including socket operations

#define BUFFER_SIZE 64    // Defining buffer size for ping requests
#define PING_COUNT 4      // Number of pings to send

// Function to create a raw socket for ICMP protocol
int create_socket() {
    int sockfd;
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to calculate the checksum of the ICMP packet
unsigned short calculate_checksum(void *b, int len) {
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

// Function to create an ICMP Echo Request packet
struct icmp {
    unsigned char icmp_type;      // ICMP type
    unsigned char icmp_code;      // ICMP code
    unsigned short icmp_checksum;  // ICMP checksum
    unsigned short icmp_id;        // Identifier
    unsigned short icmp_seq;       // Sequence number
    unsigned char icmp_data[BUFFER_SIZE]; // Data portion
};

// Function to perform ping operation
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp packet;
    struct timeval start, end;
    socklen_t addrlen = sizeof(addr);
    char buffer[BUFFER_SIZE];
    
    sockfd = create_socket();
    memset(&packet, 0, sizeof(packet));
    
    packet.icmp_type = 8; // Echo Request
    packet.icmp_code = 0; // Code 0
    packet.icmp_id = getpid(); // ID set to the PID
    packet.icmp_seq = 1; // Sequence number
    strcpy((char *)packet.icmp_data, "Ping Test!"); // Data to send
	// Calculating the checksum
    packet.icmp_checksum = calculate_checksum(&packet, sizeof(packet));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(0); // Port zero for ICMP
    addr.sin_addr.s_addr = inet_addr(ip_address); // Setting target IP

    // Sending the packet
    for (int i = 0; i < PING_COUNT; i++) {
        gettimeofday(&start, NULL); // Starting time measurement
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Failed to send ICMP packet");
            continue;
        }

        // Waiting for a response
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addrlen) <= 0) {
            perror("Timeout or error receiving ICMP packet");
            continue;
        }

        gettimeofday(&end, NULL); // Ending time measurement
        long duration = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000; // Duration in milliseconds

        printf("Response from %s: bytes=%ld time=%ldms\n", ip_address, sizeof(buffer), duration);
        packet.icmp_seq++; // Incrementing the sequence number
        sleep(1); // Waiting a second before the next ping
    }
    
    close(sockfd); // Closing the socket
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    ping(argv[1]); // Calling ping function with the given IP address

    return 0; // Successful execution
}