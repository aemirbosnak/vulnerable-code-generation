//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define PING_PKT_SIZE 64

struct ping_pkt {
    struct icmphdr icmp;
    char data[PING_PKT_SIZE - sizeof(struct icmphdr)];
};

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in addr;
    struct ping_pkt pkt;
    struct timeval start, end;
    socklen_t addrlen = sizeof(addr);
    int seq = 0;
    char *ip_addr = argv[1];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a raw socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the IP address and port of the destination
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    // Set the ICMP header
    memset(&pkt, 0, sizeof(pkt));
    pkt.icmp.type = ICMP_ECHO;
    pkt.icmp.code = 0;
    pkt.icmp.un.echo.id = getpid();
    pkt.icmp.un.echo.sequence = seq++;

    // Send the ICMP packet
    if (sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr *)&addr, addrlen) == -1) {
        perror("sendto");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Get the start time
    gettimeofday(&start, NULL);

    // Wait for the response
    while (1) {
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        if (select(sockfd + 1, &fds, NULL, NULL, &timeout) == -1) {
            perror("select");
            close(sockfd);
            return EXIT_FAILURE;
        }

        if (FD_ISSET(sockfd, &fds)) {
            // Receive the ICMP packet
            if (recvfrom(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr *)&addr, &addrlen) == -1) {
                perror("recvfrom");
                close(sockfd);
                return EXIT_FAILURE;
            }

            // Get the end time
            gettimeofday(&end, NULL);

            // Check if the packet is an ICMP echo reply
            if (pkt.icmp.type == ICMP_ECHOREPLY && pkt.icmp.un.echo.id == getpid() && pkt.icmp.un.echo.sequence == seq) {
                // Calculate the round trip time
                double rtt = (double)(end.tv_sec - start.tv_sec) * 1000.0 + (double)(end.tv_usec - start.tv_usec) / 1000.0;

                // Print the result
                printf("Reply from %s: bytes=%d time=%.3f ms\n", ip_addr, PING_PKT_SIZE, rtt);

                break;
            }
        }
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}