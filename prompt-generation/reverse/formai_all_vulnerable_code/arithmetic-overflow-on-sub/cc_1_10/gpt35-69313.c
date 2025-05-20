//FormAI DATASET v1.0 Category: Network Ping Test ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

// ICMP packet structure for pinging
struct ping_packet
{
    struct icmphdr hdr;
    char msg[64 - sizeof(struct icmphdr)];
};

bool ping(const char *ip_address)
{
    // Create socket descriptor
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    char buffer[1024];
    struct sockaddr_in recipient_addr;
    bzero(&recipient_addr, sizeof(recipient_addr));
    recipient_addr.sin_family = AF_INET;
    recipient_addr.sin_addr.s_addr = inet_addr(ip_address);

    // Create ping packet
    struct ping_packet packet;
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();

    // Start timer
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    // Send ping packet to recipient
    sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&recipient_addr, sizeof(recipient_addr));

    // Receive response from recipient
    socklen_t len = sizeof(struct sockaddr_in);
    if (recvfrom(sockfd, &buffer, sizeof(buffer), 0, (struct sockaddr*)&recipient_addr, &len) > 0)
    {
        // Stop timer and calculate RTT
        gettimeofday(&end_time, NULL);
        double rtt = ((end_time.tv_sec - start_time.tv_sec) * 1000.0) + ((end_time.tv_usec - start_time.tv_usec) / 1000.0);

        // Print successful ping result
        printf("SUCCESS: Ping to %s took %0.2fms\n", ip_address, rtt);
        close(sockfd);
        return true;
    }
    else
    {
        // Print unsuccessful ping result
        printf("FAILURE: Ping to %s failed\n", ip_address);
        close(sockfd);
        return false;
    }
}

int main()
{
    // Ping Google DNS
    ping("8.8.8.8");

    // Ping local host
    ping("127.0.0.1");

    return 0;
}