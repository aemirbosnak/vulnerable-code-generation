//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <errno.h>
#include <unistd.h>

#define MAX_HOSTNAME_LENGTH 256
#define MAX_IFNAME_LENGTH 16

void usage() {
    fprintf(stderr, "Usage: netmapper <ip-range>\n");
}

int check_ip(const char *ip) {
    struct sockaddr_in sa;

    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));

    return result != 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage();
        exit(1);
    }

    char *ip_range = argv[1];
    char ip_range_copy[strlen(ip_range) + 1];
    strcpy(ip_range_copy, ip_range);

    char *start_ip_str = strtok(ip_range, "-");
    char *end_ip_str = strtok(NULL, "-");

    char *current_ip_str = start_ip_str;

    int start_ip[4];
    int end_ip[4];

    int i = 0;

    char *token;

    token = strtok(start_ip_str, ".");

    while (token != NULL) {
        start_ip[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    i = 0;

    token = strtok(end_ip_str, ".");

    while (token != NULL) {
        end_ip[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct ifaddrs *ifaddr, *ifa;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(1);
    }

    int num_ifaces = 0;

    for (ifa = ifaddr; ifaddr != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        if (ifa->ifa_addr->sa_family != AF_INET) {
            continue;
        }

        num_ifaces++;
    }

    char ifaces[num_ifaces][MAX_IFNAME_LENGTH];
    char ip_addresses[num_ifaces][INET_ADDRSTRLEN];

    int j = 0;

    for (ifa = ifaddr; ifaddr != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        if (ifa->ifa_addr->sa_family != AF_INET) {
            continue;
        }

        struct sockaddr_in *ia = (struct sockaddr_in *) ifa->ifa_addr;

        inet_ntop(AF_INET, &(ia->sin_addr), ip_addresses[j], INET_ADDRSTRLEN);

        strcpy(ifaces[j], ifa->ifa_name);

        j++;
    }

    freeifaddrs(ifaddr);

    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);

    char hostname[MAX_HOSTNAME_LENGTH];

    while (strcmp(current_ip_str, end_ip_str) != 0) {
        if (check_ip(current_ip_str)) {
            addr.sin_family = AF_INET;
            addr.sin_port = htons(22);
            inet_pton(AF_INET, current_ip_str, &(addr.sin_addr));

            int result = getnameinfo((struct sockaddr *) &addr, len, hostname, MAX_HOSTNAME_LENGTH, NULL, 0, 0);

            if (result == 0) {
                printf("%s\t%s\n", current_ip_str, hostname);
            } else {
                printf("%s\t%s\n", current_ip_str, "");
            }
        }

        int index = start_ip[3]++;

        if (start_ip[3] > 255) {
            start_ip[3] = 0;
            start_ip[2]++;
        }

        if (start_ip[2] > 255) {
            start_ip[2] = 0;
            start_ip[1]++;
        }

        if (start_ip[1] > 255) {
            start_ip[1] = 0;
            start_ip[0]++;
        }

        if (start_ip[0] > 255) {
            fprintf(stderr, "Error: IP range too large\n");
            exit(1);
        }

        i = 0;
        int carry = 0;

        while (index > 0) {
            start_ip[i] += carry + (index % 256);
            carry = (start_ip[i] > 255);
            start_ip[i] %= 256;
            index /= 256;
            i++;
        }

        char new_ip_str[INET_ADDRSTRLEN];
        sprintf(new_ip_str, "%d.%d.%d.%d", start_ip[0], start_ip[1], start_ip[2], start_ip[3]);

        if (strcmp(new_ip_str, current_ip_str) == 0) {
            fprintf(stderr, "Error: infinite loop detected\n");
            exit(1);
        }

        int found_iface = 0;

        for (i = 0; i < num_ifaces; i++) {
            if (strncmp(ip_addresses[i], new_ip_str, strlen(ip_addresses[i])) == 0) {
                found_iface = 1;
                break;
            }
        }

        if (!found_iface) {
            fprintf(stderr, "Error: network interface not found\n");
            exit(1);
        }

        current_ip_str = new_ip_str;
    }

    close(sockfd);

    return 0;
}