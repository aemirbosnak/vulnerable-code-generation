//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOSTS 100
#define MAX_LINKS 100
#define MAX_LINKS_PER_HOST 10

typedef struct {
    char name[20];
    int num_links;
    int links[MAX_LINKS];
} Host;

void add_link(Host *hosts, int num_hosts, int host1, int host2) {
    hosts[host1].num_links++;
    hosts[host1].links[hosts[host1].num_links - 1] = host2;
    hosts[host2].num_links++;
    hosts[host2].links[hosts[host2].num_links - 1] = host1;
}

void print_hosts(Host *hosts, int num_hosts) {
    for (int i = 0; i < num_hosts; i++) {
        printf("%s\n", hosts[i].name);
        for (int j = 0; j < hosts[i].num_links; j++) {
            printf("%d ", hosts[i].links[j]);
        }
        printf("\n");
    }
}

int main() {
    Host hosts[MAX_HOSTS];
    int num_hosts = 0;

    char host_name[20];
    while (num_hosts < MAX_HOSTS) {
        printf("Enter host name (or 'done'): ");
        scanf("%s", host_name);
        if (strcmp(host_name, "done")!= 0) {
            strcpy(hosts[num_hosts].name, host_name);
            num_hosts++;
        }
    }

    int host1, host2;
    while (1) {
        printf("Enter two host numbers to connect (or 'done'): ");
        scanf("%d %d", &host1, &host2);
        if (strcmp(hosts[host1].name, hosts[host2].name)!= 0) {
            add_link(hosts, num_hosts, host1, host2);
        } else {
            printf("Cannot connect a host to itself.\n");
        }
        if (strcmp(hosts[host1].name, "done") == 0 || strcmp(hosts[host2].name, "done") == 0) {
            break;
        }
    }

    print_hosts(hosts, num_hosts);

    return 0;
}