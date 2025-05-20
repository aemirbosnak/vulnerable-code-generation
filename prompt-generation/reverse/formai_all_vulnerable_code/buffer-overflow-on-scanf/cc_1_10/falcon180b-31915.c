//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_ADDR_LEN 15
#define SUBNET_MASK_LEN 3

typedef struct {
    char ip_addr[IP_ADDR_LEN];
    char subnet_mask[SUBNET_MASK_LEN];
    int num_subnets;
    int subnet_size;
} Subnet;

void print_subnets(Subnet *subnet) {
    int i;
    for (i = 0; i < subnet->num_subnets; i++) {
        printf("%s/%d\n", subnet->ip_addr, subnet->subnet_size);
    }
}

int main() {
    int num_subnets, i;
    Subnet subnet;

    printf("Enter the IP address: ");
    scanf("%s", subnet.ip_addr);

    printf("Enter the subnet mask: ");
    scanf("%s", subnet.subnet_mask);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d.\n", MAX_SUBNETS);
        return 1;
    }

    subnet.num_subnets = num_subnets;
    subnet.subnet_size = (int)pow(2, (int)strlen(subnet.subnet_mask) - 1);

    printf("Subnet IP addresses:\n");
    for (i = 0; i < num_subnets; i++) {
        char subnet_ip[IP_ADDR_LEN];
        sprintf(subnet_ip, "%s.%d", subnet.ip_addr, i);
        printf("%s/%d\n", subnet_ip, subnet.subnet_size);
    }

    return 0;
}