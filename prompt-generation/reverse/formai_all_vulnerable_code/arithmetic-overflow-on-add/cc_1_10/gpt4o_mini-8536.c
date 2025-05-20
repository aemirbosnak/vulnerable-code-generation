//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <errno.h>

#define PACKET_SIZE 64

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

// Function to perform ping
void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmphdr icmp_hdr;
    struct timeval timeout;
    char packet[PACKET_SIZE];
    int send_count = 0;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    memset(packet, 0, sizeof(packet));
    memset(&icmp_hdr, 0, sizeof(icmp_hdr));

    icmp_hdr.type = ICMP_ECHO;
    icmp_hdr.un.echo.sequence = send_count++;
    icmp_hdr.un.echo.id = getpid();
    icmp_hdr.checksum = checksum(&icmp_hdr, sizeof(icmp_hdr));

    printf("Pinging %s:\n", ip_addr);

    // Sending ICMP packets
    for (int i = 0; i < 4; i++) {  // Send 4 pings
        icmp_hdr.un.echo.sequence = send_count++;
        icmp_hdr.checksum = checksum(&icmp_hdr, sizeof(icmp_hdr));
        
        if (sendto(sockfd, &icmp_hdr, sizeof(icmp_hdr), 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
            perror("Ping send failed");
            break;
        }

        // Wait for response
        fd_set readfds;
        struct timeval tv;
        tv.tv_sec = 1;  // 1 second timeout
        tv.tv_usec = 0;

        FD_SET(sockfd, &readfds);
        int activity = select(sockfd + 1, &readfds, NULL, NULL, &tv);

        if (activity < 0) {
            perror("Select error");
            break;
        }
        
        if (activity == 0) {
            printf("Request timed out.\n");
        } else {
            char buffer[PACKET_SIZE];
            socklen_t addr_len = sizeof(addr);
            recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addr_len);
            printf("Reply from %s: bytes=%d seq=%d\n", ip_addr, sizeof(buffer), icmp_hdr.un.echo.sequence);
        }

        sleep(1);
    }

    close(sockfd);
    printf("Finished pinging %s.\n", ip_addr);
}

// Main function to drive the program
int main() {
    char ip_addr[16];

    printf("Welcome to the Network Ping Test Program!\n");
    printf("Please enter the IP address or hostname to ping (e.g., 8.8.8.8 or google.com): ");
    
    // Getting user input for IP address or hostname
    scanf("%15s", ip_addr);
    
    // Verifying input
    if (strlen(ip_addr) == 0) {
        printf("You entered an empty value. Please try again.\n");
        return 1;
    }

    // Conducting the ping test
    ping(ip_addr);

    printf("Would you like to ping another address? (yes/no): ");
    char response[4];
    scanf("%3s", response);
    
    if (strcmp(response, "yes") == 0) {
        main(); // Call main again for a new ping test
    } else {
        printf("Thank you for using the Network Ping Test Program. Goodbye!\n");
    }

    return 0;
}