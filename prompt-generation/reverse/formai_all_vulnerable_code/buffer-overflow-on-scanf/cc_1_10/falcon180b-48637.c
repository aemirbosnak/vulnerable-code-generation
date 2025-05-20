//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    int mask;
    int bits;
} Subnet;

void parse_subnet(const char *subnet_str, Subnet *subnet) {
    char subnet_buf[MAX_SUBNET_SIZE];
    strcpy(subnet_buf, subnet_str);

    char *dot = strchr(subnet_buf, '.');
    if (dot == NULL) {
        subnet->mask = 32;
        subnet->bits = 0;
        strcpy(subnet->subnet, subnet_buf);
        return;
    }

    *dot = '\0';
    int mask = atoi(dot + 1);
    if (mask == 0 || mask > 32) {
        printf("Invalid subnet mask: %s\n", subnet_str);
        exit(1);
    }

    subnet->mask = mask;
    subnet->bits = 32 - mask;
    strcpy(subnet->subnet, subnet_buf);
}

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    Subnet subnets[MAX_SUBNETS];
    for (int i = 0; i < num_subnets; i++) {
        char subnet_buf[MAX_SUBNET_SIZE];
        printf("Enter subnet %d: ", i + 1);
        scanf("%s", subnet_buf);

        Subnet subnet;
        parse_subnet(subnet_buf, &subnet);
        strcpy(subnets[i].subnet, subnet.subnet);
        subnets[i].mask = subnet.mask;
        subnets[i].bits = subnet.bits;
    }

    printf("\nSubnet\tIP Range\tHosts\n");
    for (int i = 0; i < num_subnets; i++) {
        char subnet_str[MAX_SUBNET_SIZE];
        snprintf(subnet_str, MAX_SUBNET_SIZE, "%s/%d", subnets[i].subnet, subnets[i].mask);
        printf("%s\t", subnet_str);

        int hosts = pow(2, subnets[i].bits) - 2;
        printf("%d hosts\n", hosts);
    }

    return 0;
}