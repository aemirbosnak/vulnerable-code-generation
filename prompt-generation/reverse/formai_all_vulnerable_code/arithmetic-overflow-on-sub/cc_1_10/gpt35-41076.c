//FormAI DATASET v1.0 Category: Network Ping Test ; Style: surprised
// Wow! I can't believe it! I finally did it!
// This is an amazing C Network Ping Test example program!
// I'm so surprised I was able to make it work!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define PACKETSIZE 64

void sendPacket(int sockfd, struct sockaddr_in *addr, int seq_num) {
    char packet[PACKETSIZE];
    memset(packet, 1, sizeof(packet));

    // Set sequence number of packet
    packet[0] = (seq_num >> 24) & 0xFF;
    packet[1] = (seq_num >> 16) & 0xFF;
    packet[2] = (seq_num >> 8) & 0xFF;
    packet[3] = seq_num & 0xFF;

    // Get current time of day
    struct timeval tv;
    gettimeofday(&tv, NULL);

    // Set packet timestamp
    packet[8] = (tv.tv_sec * 1000) / 256;
    packet[9] = (tv.tv_sec * 1000) % 256;
    packet[10] = (tv.tv_usec / 1000) / 256;
    packet[11] = (tv.tv_usec / 1000) % 256;

    // Send packet to target address
    if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *) addr, sizeof(*addr)) < 0) {
        perror("sendto failed");
    }
}

void receivePacket(int sockfd, struct sockaddr_in *addr, int seq_num) {
    char packet[PACKETSIZE];
    socklen_t fromlen = sizeof(*addr);
    int millisecs;

    if (recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr *) addr, &fromlen) < 0) {
        perror("recvfrom failed");
        return;
    }

    // Check packet sequence number
    int recv_seq_num = ((int) packet[0] << 24) | ((int) packet[1] << 16) | ((int) packet[2] << 8) | (int) packet[3];
    if (recv_seq_num != seq_num) {
        printf("Packet with wrong sequence number received\n");
        return;
    }

    // Get current time of day and calculate round-trip time
    struct timeval tv;
    gettimeofday(&tv, NULL);
    millisecs = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - (((int) packet[8] << 8) | (int) packet[9]) - (((int) packet[10] << 8) | (int) packet[11]);

    printf("pong from %s: bytes=%d time=%dms\n", inet_ntoa(addr->sin_addr), PACKETSIZE, millisecs);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname or IP address>\n", argv[0]);
        return 1;
    }

    // Get target IP address and hostname
    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        printf("Could not resolve hostname\n");
        return 1;
    }

    char *hostname = he->h_name;
    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;
    char *ip_addr = inet_ntoa(*addr_list[0]);

    printf("PING %s (%s): %d data bytes\n", hostname, ip_addr, PACKETSIZE);

    // Create UDP socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("socket failed");
        return 1;
    }

    // Set socket options
    struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt failed");
        return 1;
    }

    // Set target address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    addr.sin_port = htons(0);

    int seq_num = 0;
    while (1) {
        seq_num++;
        sendPacket(sockfd, &addr, seq_num);
        receivePacket(sockfd, &addr, seq_num);
        sleep(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}