//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define IP_SIZE 16
#define SUBNET_MASK_SIZE 16

typedef struct {
    char ip[IP_SIZE];
    char subnet_mask[SUBNET_MASK_SIZE];
    int num_hosts;
} Subnet;

void generate_subnets(char *ip, int num_subnets) {
    Subnet subnets[MAX_SUBNETS];
    int num_subnets_generated = 0;
    int i, j;

    strcpy(subnets[0].ip, ip);
    strcpy(subnets[0].subnet_mask, "255.255.255.0");
    subnets[0].num_hosts = 254;

    for (i = 1; i < MAX_SUBNETS && num_subnets_generated < num_subnets; i++) {
        for (j = 0; j < IP_SIZE; j++) {
            if (subnets[i - 1].ip[j] == '.' || subnets[i - 1].ip[j] == '\0')
                continue;
            subnets[i].ip[j] = subnets[i - 1].ip[j] + 1;
            if (subnets[i].ip[j] > '9') {
                subnets[i].ip[j] = '0';
                if (j == 2 && subnets[i].ip[1] == '0') {
                    subnets[i].ip[0]++;
                    subnets[i].ip[1] = '0';
                } else if (j == 3 && subnets[i].ip[2] == '0') {
                    subnets[i].ip[1]++;
                    subnets[i].ip[2] = '0';
                }
            }
        }
        strcpy(subnets[i].subnet_mask, "255.255.255.0");
        subnets[i].num_hosts = 254;
        num_subnets_generated++;
    }

    for (i = 0; i < num_subnets_generated; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("IP address: %s\n", subnets[i].ip);
        printf("Subnet mask: %s\n", subnets[i].subnet_mask);
        printf("Number of hosts: %d\n\n", subnets[i].num_hosts);
    }
}

int main() {
    char ip[IP_SIZE];

    printf("Enter the IP address: ");
    scanf("%s", ip);

    generate_subnets(ip, 10);

    return 0;
}