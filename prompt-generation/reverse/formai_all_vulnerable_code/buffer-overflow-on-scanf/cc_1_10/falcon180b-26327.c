//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_NUMBER 4
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    int num_hosts;
    int num_subnets;
} subnet;

void add_subnet(subnet *s, int num_hosts, int num_subnets, char *name, char *mask) {
    strcpy(s->name, name);
    strcpy(s->mask, mask);
    s->num_hosts = num_hosts;
    s->num_subnets = num_subnets;
}

int main() {
    char input[100];
    int ip[4], mask[4], i, j, k, num_subnets = 0;
    subnet subnets[MAX_SUBNETS];

    printf("Enter the IP address: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter the subnet mask: ");
    scanf("%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    for(i = 0; i < 4; i++) {
        if(mask[i] == 0) {
            for(j = i + 1; j < 4; j++) {
                if(mask[j] == 0) {
                    for(k = j + 1; k < 4; k++) {
                        if(mask[k] == 0) {
                            add_subnet(&subnets[num_subnets], 1, 1, "192.168.1.1", "255.255.255.192");
                            num_subnets++;
                            break;
                        }
                    }
                    if(num_subnets == MAX_SUBNETS) break;
                }
            }
            if(num_subnets == MAX_SUBNETS) break;
        }
    }

    printf("Subnets:\n");
    for(i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Name: %s\n", subnets[i].name);
        printf("Mask: %s\n", subnets[i].mask);
        printf("Number of hosts: %d\n", subnets[i].num_hosts);
        printf("Number of subnets: %d\n", subnets[i].num_subnets);
        printf("\n");
    }

    return 0;
}