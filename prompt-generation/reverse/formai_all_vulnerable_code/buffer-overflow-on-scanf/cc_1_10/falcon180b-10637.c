//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORK_SIZE 32
#define MAX_HOST_SIZE 32

void print_network(char* network, int prefix) {
    char buffer[MAX_NETWORK_SIZE];
    sprintf(buffer, "%s/%d", network, prefix);
    printf("%s\n", buffer);
}

void print_subnet(char* network, int prefix, int num_hosts) {
    char buffer[MAX_NETWORK_SIZE];
    sprintf(buffer, "%s/%d (%d hosts)", network, prefix, num_hosts);
    printf("%s\n", buffer);
}

int main() {
    char network[MAX_NETWORK_SIZE];
    int prefix;
    int num_hosts;

    printf("Enter network address: ");
    scanf("%s", network);

    printf("Enter prefix size: ");
    scanf("%d", &prefix);

    if (prefix > 32 || prefix < 1) {
        printf("Invalid prefix size\n");
        exit(1);
    }

    printf("Enter number of hosts: ");
    scanf("%d", &num_hosts);

    if (num_hosts > (32 - prefix) || num_hosts < 1) {
        printf("Invalid number of hosts\n");
        exit(1);
    }

    char* subnet = malloc((MAX_NETWORK_SIZE * 2) + 1);
    sprintf(subnet, "%s/%d", network, prefix);

    char* ip = malloc(MAX_NETWORK_SIZE + 1);
    strcpy(ip, network);

    for (int i = 0; i < num_hosts; i++) {
        char* host = malloc(MAX_HOST_SIZE + 1);
        sprintf(host, "%s.%d", ip, i+1);
        printf("%s\n", host);
    }

    return 0;
}