//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 10
#define MAX_HOSTS_PER_NETWORK 10
#define MAX_OCTET_VALUE 255
#define MAX_IP_LENGTH 16
#define MAX_SUBNET_MASK_LENGTH 4

typedef struct {
    char ip[MAX_IP_LENGTH];
    int prefix_length;
} subnet;

subnet subnets[MAX_NETWORKS];

int num_subnets = 0;

void add_subnet(char* ip, int prefix_length) {
    if (num_subnets >= MAX_NETWORKS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strcpy(subnets[num_subnets].ip, ip);
    subnets[num_subnets].prefix_length = prefix_length;

    num_subnets++;
}

int main() {
    subnet* current_subnet = &subnets[0];

    while (1) {
        printf("Enter IP address and prefix length (e.g. 192.168.0.0/24) or type 'done' to finish:\n");
        scanf("%s", current_subnet->ip);

        if (strcmp(current_subnet->ip, "done") == 0) {
            break;
        }

        char* slash_pos = strchr(current_subnet->ip, '/');
        if (slash_pos == NULL) {
            printf("Error: Invalid subnet format.\n");
            return 1;
        }

        *slash_pos = '\0';
        current_subnet->prefix_length = atoi(slash_pos + 1);

        if (current_subnet->prefix_length > MAX_SUBNET_MASK_LENGTH) {
            printf("Error: Invalid subnet mask length.\n");
            return 1;
        }

        current_subnet++;
        num_subnets++;
    }

    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s/%d\n", subnets[i].ip, subnets[i].prefix_length);
    }

    return 0;
}