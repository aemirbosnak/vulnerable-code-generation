//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>

#define MAX_IP_LEN 1024

void usage(char *name);
int check_args(char *arg1, char *arg2);

int main(int argc, char *argv[]) {
    int s, ii;
    struct ifreq ifr;
    u_char hw_address[6];
    char *ip = "192.168.0.1";
    char ip_range[MAX_IP_LEN];
    char *start_ip, *end_ip;
    int start1, start2, start3, start4;
    int end1, end2, end3, end4;
    char *endptr;

    // Parse command line arguments
    if (argc != 3) {
        usage(argv[0]);
        exit(1);
    }

    if (check_args(argv[1], argv[2]) != 0) {
        usage(argv[0]);
        exit(1);
    }

    start_ip = argv[1];
    end_ip = argv[2];

    // Convert start and end IP ranges to array indices
    start1 = strtol(strtok(start_ip, "."), &endptr, 10);
    start2 = strtol(strtok(NULL, "."), &endptr, 10);
    start3 = strtol(strtok(NULL, "."), &endptr, 10);
    start4 = strtol(strtok(NULL, "."), &endptr, 10);

    end1 = strtol(strtok(end_ip, "."), &endptr, 10);
    end2 = strtol(strtok(NULL, "."), &endptr, 10);
    end3 = strtol(strtok(NULL, "."), &endptr, 10);
    end4 = strtol(strtok(NULL, "."), &endptr, 10);

    // Determine length of IP range
    int range_len = ((end1 - start1) * 16777216) + ((end2 - start2) * 65536) + ((end3 - start3) * 256) + (end4 - start4) + 1;

    // Initialize socket for sending packets
    if ((s = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) == -1) {
        perror("socket() failed");
        exit(1);
    }

    // Get MAC address of the interface
    memset(&ifr, 0, sizeof(struct ifreq));

    strncpy(ifr.ifr_name, "wlan0", IFNAMSIZ - 1);
    ifr.ifr_name[IFNAMSIZ - 1] = '\0';

    if (ioctl(s, SIOCGIFHWADDR, &ifr) != 0) {
        perror("ioctl() failed");
        exit(1);
    }

    memcpy(hw_address, ifr.ifr_hwaddr.sa_data, 6);

    // Scan the IP range
    struct sockaddr_in addr;
    int addr_len = sizeof(struct sockaddr_in);
    struct iphdr *ip_header;
    struct udphdr *udp_header;
    char recvbuf[1500];
    int bytes, ttl, flags, is_complete = 0;

    for (ii = 0; ii < range_len && !is_complete; ii++) {
        // Build the IP address as a string
        snprintf(ip_range, MAX_IP_LEN, "%d.%d.%d.%d", start1, start2, start3, start4);

        // Build the IP and UDP headers
        ip_header = (struct iphdr*) recvbuf;
        udp_header = (struct udphdr*) (recvbuf + sizeof(struct iphdr));
        memset(ip_header, 0, sizeof(struct iphdr));
        memset(udp_header, 0, sizeof(struct udphdr));

        // Populating IP header
        ip_header->version = 4;
        ip_header->ihl = 5;
        ip_header->tos = IPTOS_LOWDELAY;
        ip_header->tot_len = htons(sizeof(struct iphdr) + sizeof(struct udphdr));
        ip_header->id = htons(12345);
        ip_header->frag_off = htons(0);
        ip_header->ttl = 64;
        ip_header->protocol = IPPROTO_UDP;
        ip_header->saddr = inet_addr(ip);
        ip_header->daddr = inet_addr(ip_range);
        ip_header->check = 0;

        // Populating UDP header
        udp_header->source = htons(1024);
        udp_header->dest = htons(1025);
        udp_header->len = htons(sizeof(struct udphdr));

        // Send the packet
        if (sendto(s, recvbuf, sizeof(struct iphdr) + sizeof(struct udphdr), 0, (struct sockaddr*) &addr, sizeof(struct sockaddr_in)) == -1) {
            perror("sendto() failed");
            exit(1);
        }

        // Receive a packet
        while ((bytes = recv(s, recvbuf, sizeof(recvbuf), 0)) > 0) {
            ttl = recvbuf[8];
            flags = recvbuf[20] & 0x07;

            // Check the TTL and Flags values to determine if port is open or closed
            if (ttl <= 64 && flags == 0) {
                printf("%s is up\n", ip_range);
            } else {
                printf("%s is down\n", ip_range);
            }

            // If the end IP address has been reached, exit the loop
            if (strncmp(ip_range, end_ip, MAX_IP_LEN) == 0) {
                is_complete = 1;
                break;
            }
        }

        // Update the start IP address
        start4++;

        if (start4 > 255) {
            start4 = 0;
            start3++;
        }

        if (start3 > 255) {
            start3 = 0;
            start2++;
        }

        if (start2 > 255) {
            start2 = 0;
            start1++;
        }

        if (start1 > end1) {
            is_complete = 1;
        }
    }

    close(s);
    return 0;
}

void usage(char *name) {
    printf("Usage: %s <start IP address> <end IP address>\n", name);
}

int check_args(char *arg1, char *arg2) {
    // Check if IP addresses are valid
    int success = 0;
    int i1, i2, i3, i4;
    char *endptr;

    i1 = strtol(strtok(arg1, "."), &endptr, 10);
    i2 = strtol(strtok(NULL, "."), &endptr, 10);
    i3 = strtol(strtok(NULL, "."), &endptr, 10);
    i4 = strtol(strtok(NULL, "."), &endptr, 10);

    if (i1 >= 0 && i1 <= 255 && i2 >= 0 && i2 <= 255 && i3 >= 0 && i3 <= 255 && i4 >= 0 && i4 <= 255) {
        success++;
    }

    i1 = strtol(strtok(arg2, "."), &endptr, 10);
    i2 = strtol(strtok(NULL, "."), &endptr, 10);
    i3 = strtol(strtok(NULL, "."), &endptr, 10);
    i4 = strtol(strtok(NULL, "."), &endptr, 10);

    if (i1 >= 0 && i1 <= 255 && i2 >= 0 && i2 <= 255 && i3 >= 0 && i3 <= 255 && i4 >= 0 && i4 <= 255) {
        success++;
    }

    return success == 2 ? 0 : 1;
}