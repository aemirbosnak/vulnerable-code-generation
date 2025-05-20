//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_HOSTS 10

struct host_info {
    char *hostname;
    struct in_addr addr;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <network-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the network address
    char *network_addr = argv[1];

    // Create an array of host_info structs
    struct host_info hosts[MAX_HOSTS];

    // Initialize the host_info structs
    for (int i = 0; i < MAX_HOSTS; i++) {
        hosts[i].hostname = NULL;
        hosts[i].addr.s_addr = 0;
    }

    // Get the network mask
    struct in_addr network_mask;
    if (inet_pton(AF_INET, network_addr, &network_mask) != 1) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Get the first host address
    struct in_addr first_host_addr;
    first_host_addr.s_addr = network_mask.s_addr | htonl(1);

    // Get the last host address
    struct in_addr last_host_addr;
    last_host_addr.s_addr = network_mask.s_addr | htonl(254);

    // Iterate over the hosts and get their information
    int num_hosts = 0;
    for (struct in_addr addr = first_host_addr; addr.s_addr <= last_host_addr.s_addr; addr.s_addr++) {
        // Get the hostname
        char hostname[NI_MAXHOST];
        int ret = getnameinfo((struct sockaddr *)&addr, sizeof(addr), hostname, NI_MAXHOST, NULL, 0, 0);
        if (ret != 0) {
            perror("getnameinfo");
            continue;
        }

        // Store the hostname and address
        hosts[num_hosts].hostname = strdup(hostname);
        hosts[num_hosts].addr = addr;

        // Increment the number of hosts
        num_hosts++;
    }

    // Print the host information
    for (int i = 0; i < num_hosts; i++) {
        printf("%s: %s\n", hosts[i].hostname, inet_ntoa(hosts[i].addr));
        free(hosts[i].hostname);
    }

    return EXIT_SUCCESS;
}