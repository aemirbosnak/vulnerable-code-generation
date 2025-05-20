//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HOSTS 100
#define MAX_LINKS 100

typedef struct {
    char name[20];
    int id;
} Host;

typedef struct {
    int from;
    int to;
    int cost;
} Link;

Host* hosts = NULL;
int num_hosts = 0;
Link* links = NULL;
int num_links = 0;

void add_host(char* name) {
    Host* new_host = malloc(sizeof(Host));
    strcpy(new_host->name, name);
    new_host->id = num_hosts;
    hosts = realloc(hosts, sizeof(Host) * ++num_hosts);
    hosts[num_hosts - 1] = *new_host;
}

int find_host_id(char* name) {
    for (int i = 0; i < num_hosts; i++) {
        if (strcmp(hosts[i].name, name) == 0) {
            return hosts[i].id;
        }
    }
    return -1;
}

void add_link(int from_id, int to_id, int cost) {
    Link* new_link = malloc(sizeof(Link));
    new_link->from = from_id;
    new_link->to = to_id;
    new_link->cost = cost;
    links = realloc(links, sizeof(Link) * ++num_links);
    links[num_links - 1] = *new_link;
}

void print_hosts() {
    for (int i = 0; i < num_hosts; i++) {
        printf("%d: %s\n", hosts[i].id, hosts[i].name);
    }
}

void print_links() {
    for (int i = 0; i < num_links; i++) {
        printf("(%d,%d,%d)\n", links[i].from, links[i].to, links[i].cost);
    }
}

int main() {
    add_host("Host1");
    add_host("Host2");
    add_host("Host3");
    add_host("Host4");

    add_link(0, 1, 10);
    add_link(1, 2, 20);
    add_link(2, 3, 30);

    print_hosts();
    print_links();

    return 0;
}