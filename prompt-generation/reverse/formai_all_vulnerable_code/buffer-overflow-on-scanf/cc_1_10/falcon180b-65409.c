//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_IP_LENGTH 15

struct subnet {
    char ip[MAX_IP_LENGTH];
    char mask[MAX_IP_LENGTH];
    int num_hosts;
};

int main() {
    int num_subnets, i;
    struct subnet subnets[MAX_SUBNETS];

    printf("Welcome to the Subnet Calculator!\n");
    printf("How many subnets do you want to calculate? ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the IP address for subnet %d: ", i+1);
        scanf("%s", subnets[i].ip);

        printf("Enter the subnet mask for subnet %d: ", i+1);
        scanf("%s", subnets[i].mask);

        subnets[i].num_hosts = calculate_num_hosts(subnets[i].ip, subnets[i].mask);
    }

    printf("\nSubnet calculations:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("IP address: %s\n", subnets[i].ip);
        printf("Subnet mask: %s\n", subnets[i].mask);
        printf("Number of hosts: %d\n\n", subnets[i].num_hosts);
    }

    return 0;
}

int calculate_num_hosts(char* ip, char* mask) {
    int num_hosts = 0;
    int i, j;

    for (i = 0, j = 0; i < strlen(ip) && j < strlen(mask); i++, j++) {
        if (ip[i] == '.' || mask[j] == '.') {
            continue;
        }

        if (isdigit(ip[i]) && isdigit(mask[j])) {
            num_hosts += (ip[i] - '0') * (mask[j] - '0');
        } else if (ip[i] == '*') {
            num_hosts += 8;
        } else if (mask[j] == '*') {
            num_hosts += 8;
        } else {
            return -1; // Invalid input
        }
    }

    return num_hosts;
}