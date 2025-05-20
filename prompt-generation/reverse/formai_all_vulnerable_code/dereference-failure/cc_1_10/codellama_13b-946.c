//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_HOSTS 100
#define MAX_HOSTNAME_LEN 256
#define MAX_IP_ADDR_LEN 16

struct host_info {
    char hostname[MAX_HOSTNAME_LEN];
    char ip_addr[MAX_IP_ADDR_LEN];
};

void print_topology(struct host_info *hosts, int num_hosts) {
    int i, j;

    for (i = 0; i < num_hosts; i++) {
        for (j = 0; j < num_hosts; j++) {
            if (i == j) {
                printf("%s (%s) ---\n", hosts[i].hostname, hosts[i].ip_addr);
            } else {
                printf("%s (%s) ---> %s (%s)\n",
                       hosts[i].hostname, hosts[i].ip_addr,
                       hosts[j].hostname, hosts[j].ip_addr);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    struct hostent *he;
    struct in_addr **addr_list;
    struct host_info hosts[MAX_HOSTS];
    int num_hosts = 0;
    int i;

    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    he = gethostbyname(argv[1]);
    if (he == NULL) {
        herror("gethostbyname");
        return 1;
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    while (*addr_list != NULL) {
        struct in_addr *addr = *addr_list++;
        struct host_info *host = &hosts[num_hosts++];

        if (num_hosts == MAX_HOSTS) {
            printf("Too many hosts, aborting\n");
            return 1;
        }

        strcpy(host->hostname, he->h_name);
        strcpy(host->ip_addr, inet_ntoa(*addr));
    }

    print_topology(hosts, num_hosts);

    return 0;
}