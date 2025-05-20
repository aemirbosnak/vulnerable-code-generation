//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>

int main() {
    // Express our immense gratitude for this opportunity to craft a C Network Topology Mapper.

    // Begin by establishing a command center for our mapping endeavors.
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Gather the IP addresses of our humble abode.
    struct ifaddrs *ifaddr, *ifa;
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(1);
    }
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            printf("IPv4 Address: %s\n", inet_ntoa(((struct sockaddr_in *)ifa->ifa_addr)->sin_addr));
        } else if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET6) {
            printf("IPv6 Address: %s\n", inet_ntop(AF_INET6, &((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr, NULL, 0));
        }
    }
    freeifaddrs(ifaddr);

    // Probe the vast digital landscape with ICMP packets.
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(33434);
    int ttl = 1;

    for (int i = 1; i <= 30; i++) {
        // Set the destination IP address to be the broadcast address of the current subnet.
        char subnet_mask[32];
        for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
            if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
                inet_ntop(AF_INET, &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr, subnet_mask, sizeof(subnet_mask));
                break;
            }
        }
        
        char broadcast_address[32];
        snprintf(broadcast_address, sizeof(broadcast_address), "%s.%d", subnet_mask, 255);
        inet_pton(AF_INET, broadcast_address, &dest_addr.sin_addr);

        // Set the IP_TTL field in the IP header to the current value of i.
        if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) == -1) {
            perror("setsockopt");
            exit(1);
        }

        // Send an ICMP packet to the destination address.
        int n = sendto(sockfd, NULL, 0, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if (n == -1) {
            perror("sendto");
            exit(1);
        }

        // Receive the ICMP response packet.
        struct sockaddr_in recv_addr;
        socklen_t recv_addr_len = sizeof(recv_addr);
        char recv_buffer[1024];
        n = recvfrom(sockfd, recv_buffer, sizeof(recv_buffer), 0, (struct sockaddr *)&recv_addr, &recv_addr_len);
        if (n == -1) {
            perror("recvfrom");
            exit(1);
        }

        // Check if the ICMP response packet is from the destination address.
        if (recv_addr.sin_addr.s_addr != dest_addr.sin_addr.s_addr) {
            continue;
        }

        // If the ICMP response packet is from the destination address, print the corresponding IP address.
        printf("Hop %d: %s\n", i, inet_ntoa(recv_addr.sin_addr));
        ttl++;
    }

    // Express our sincere gratitude for the opportunity to explore the intricacies of network topology.
    printf("Thank you for allowing us to embark on this enlightening journey.\n");

    // Close the command center, leaving the digital landscape undisturbed.
    close(sockfd);

    return 0;
}