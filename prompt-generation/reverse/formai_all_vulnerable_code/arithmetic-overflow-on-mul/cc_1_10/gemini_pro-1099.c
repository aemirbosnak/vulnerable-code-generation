//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PING_SIZE 56
#define PING_TIMEOUT 1000  // ms

struct ping_pkt {
    struct timeval tv;
    unsigned char data[PING_SIZE - sizeof(struct timeval)];
};

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname or IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Resolve hostname to IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        herror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Create a raw socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set socket options
    int on = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Construct ping packet
    struct ping_pkt pkt;
    memset(&pkt, 0, sizeof(pkt));
    pkt.tv = (struct timeval) {0, 0};
    strcpy(pkt.data, "PING");

    // Send ping packet
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
    if (sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("sendto");
        return EXIT_FAILURE;
    }

    // Receive ping response
    struct sockaddr_in from;
    socklen_t fromlen = sizeof(from);
    if (recvfrom(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr *) &from, &fromlen) == -1) {
        perror("recvfrom");
        return EXIT_FAILURE;
    }

    // Validate ping response
    if (memcmp(pkt.data, "PING", 4) != 0) {
        fprintf(stderr, "Invalid ping response\n");
        return EXIT_FAILURE;
    }

    // Calculate round-trip time
    struct timeval now;
    gettimeofday(&now, NULL);
    long rtt = (now.tv_sec - pkt.tv.tv_sec) * 1000 + (now.tv_usec - pkt.tv.tv_usec) / 1000;

    // Print ping results
    printf("Ping: %s (%s)\n", argv[1], inet_ntoa(from.sin_addr));
    printf("Round-trip time: %ld ms\n", rtt);

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}