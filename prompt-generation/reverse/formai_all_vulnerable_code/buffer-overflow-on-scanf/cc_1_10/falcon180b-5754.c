//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTS 100
#define MAX_PORTS 100
#define MAX_LINKS 100

typedef struct {
    char name[64];
    int port;
    int links[MAX_LINKS];
    int num_links;
} host_t;

host_t hosts[MAX_HOSTS];
int num_hosts;

void add_host(char* name, int port) {
    int i;
    for(i=0; i<num_hosts; i++) {
        if(strcmp(hosts[i].name, name)==0) {
            hosts[i].port = port;
            return;
        }
    }
    if(num_hosts>=MAX_HOSTS) {
        printf("Error: too many hosts\n");
        exit(1);
    }
    strcpy(hosts[num_hosts].name, name);
    hosts[num_hosts].port = port;
    num_hosts++;
}

void add_link(int host1, int host2) {
    int i;
    for(i=0; i<num_hosts; i++) {
        if(hosts[i].port==host1) {
            hosts[i].links[hosts[i].num_links++] = host2;
            return;
        }
    }
    printf("Error: host not found\n");
    exit(1);
}

void print_hosts() {
    int i, j;
    for(i=0; i<num_hosts; i++) {
        printf("%s:%d ", hosts[i].name, hosts[i].port);
        for(j=0; j<hosts[i].num_links; j++) {
            printf("->%s:%d ", hosts[hosts[i].links[j]].name, hosts[hosts[i].links[j]].port);
        }
        printf("\n");
    }
}

int main() {
    int i, j, n;
    char name[64];
    int port;
    scanf("%d", &n);
    num_hosts = 0;
    while(n--) {
        scanf("%s %d", name, &port);
        add_host(name, port);
    }
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &i, &j);
        add_link(i, j);
    }
    print_hosts();
    return 0;
}