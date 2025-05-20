//FormAI DATASET v1.0 Category: Network Ping Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define PING_PORT 80
#define PING_SIZE 64

struct ping_packet {
    struct timeval tv_send;
};

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Please enter the IP address or host name to ping as argument.\n");
        return -1;
    }

    char* target = argv[1];

    printf("Pinging %s...\n", target);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Failed to create socket.\n");
        return -1;
    }

    // Set socket options
    int ttl = 64;
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) == -1) {
        printf("Failed to set TTL option on socket.\n");
    }

    // Resolve target name to IP address
    struct hostent* host = gethostbyname(target);
    if (host == NULL) {
        printf("Failed to resolve target host.\n");
        return -1;
    }
    char* target_ip = inet_ntoa(*((struct in_addr*) host->h_addr));
    printf("Target IP: %s\n", target_ip);

    // Prepare ICMP packet
    struct ping_packet packet;
    packet.tv_send.tv_sec = 0;
    packet.tv_send.tv_usec = 0;

    // Send ping requests
    int sent = 0;
    int received = 0;
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(PING_PORT);
    target_addr.sin_addr.s_addr = inet_addr(target_ip);
    for (int i = 0; i < 4; i++) {
        // Set timestamp in packet
        gettimeofday(&packet.tv_send, NULL);
        // Send packet to target
        ssize_t sent_bytes = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&target_addr, sizeof(target_addr));
        if (sent_bytes == -1) {
            printf("Failed to send ping request.\n");
            continue;
        }
        sent++;
        // Wait for response
        struct sockaddr_in sender_addr;
        socklen_t sender_len = sizeof(sender_addr);
        char buffer[PING_SIZE];
        ssize_t recv_bytes = recvfrom(sockfd, buffer, PING_SIZE, 0, (struct sockaddr*)&sender_addr, &sender_len);
        if (recv_bytes == -1) {
            printf("No response from target.\n");
        }
        else {
            struct timeval tv_recv;
            gettimeofday(&tv_recv, NULL);
            long rtt_usec = (tv_recv.tv_sec - packet.tv_send.tv_sec) * 1000000 + (tv_recv.tv_usec - packet.tv_send.tv_usec);
            printf("Response from %s: bytes=%d time=%.3fms\n", target_ip, PING_SIZE, rtt_usec / 1000.0);
            received++;
        }
        sleep(1);
    }

    printf("Ping statistics for %s:\n", target_ip);
    printf("    Packets: Sent = %d, Received = %d, Lost = %d (%.1f%% loss),\n", sent, received, sent - received, (sent - received) * 100.0 / sent);

    close(sockfd);
    return 0;
}