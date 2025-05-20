//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOSTS 100
#define MAX_PORT 65535
#define MAX_LINE 1000

typedef struct {
    char hostname[MAX_LINE];
    int port;
    struct sockaddr_in addr;
} host_t;

void add_host(host_t *hosts, int count, char *hostname, int port) {
    if (count >= MAX_HOSTS) {
        printf("Error: Too many hosts!\n");
        exit(1);
    }
    strncpy(hosts[count].hostname, hostname, MAX_LINE);
    hosts[count].port = port;
    hosts[count].addr.sin_family = AF_INET;
    hosts[count].addr.sin_addr.s_addr = inet_addr(hostname);
    hosts[count].addr.sin_port = htons(port);
    count++;
}

void print_hosts(host_t *hosts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s:%d\n", inet_ntoa(hosts[i].addr.sin_addr), ntohs(hosts[i].addr.sin_port));
    }
}

int main() {
    char input[MAX_LINE];
    char *filename = NULL;
    FILE *fp = NULL;
    host_t hosts[MAX_HOSTS];
    int count = 0;

    // Get filename from user
    printf("Enter the filename containing hostnames and ports: ");
    scanf("%s", input);
    filename = strdup(input);

    // Open file and read hosts
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }
    while (fgets(input, MAX_LINE, fp)!= NULL) {
        char *host = strtok(input, ":");
        int port = atoi(strtok(NULL, ":"));
        add_host(hosts, count, host, port);
    }
    fclose(fp);

    // Print hosts and map topology
    printf("Hosts:\n");
    print_hosts(hosts, count);

    return 0;
}