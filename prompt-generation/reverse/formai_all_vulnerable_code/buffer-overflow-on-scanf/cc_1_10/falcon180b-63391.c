//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNET_SIZE 32
#define MAX_SUBNETS 256
#define MAX_SUBNET_NAME_LENGTH 64

typedef struct {
    char name[MAX_SUBNET_NAME_LENGTH];
    char subnet[MAX_SUBNET_SIZE];
    int num_hosts;
    int num_subnets;
} Subnet;

void parse_subnet(char *subnet_str, Subnet *subnet) {
    char *ptr;
    int num_bits = 0;
    int i = 0;

    ptr = strchr(subnet_str, '. ');
    if (ptr == NULL) {
        subnet->num_hosts = 1;
        subnet->num_subnets = 1;
    } else {
        subnet->num_hosts = 0;
        subnet->num_subnets = 0;
        while (ptr!= NULL) {
            subnet->subnet[i] = ptr[1];
            i++;
            num_bits++;
            ptr = strchr(ptr + 1, '. ');
        }
        subnet->subnet[i] = '\0';
        subnet->num_hosts = (int)pow(2, MAX_SUBNET_SIZE - num_bits);
        subnet->num_subnets = subnet->num_hosts / 2;
    }
}

void print_subnet(Subnet *subnet) {
    printf("Subnet: %s\n", subnet->subnet);
    printf("Number of hosts: %d\n", subnet->num_hosts);
    printf("Number of subnets: %d\n", subnet->num_subnets);
}

int main() {
    int num_subnets = 0;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter subnet #%d name: ", i + 1);
        scanf("%s", subnets[i].name);

        printf("Enter subnet IP address: ");
        scanf("%s", subnets[i].subnet);

        parse_subnet(subnets[i].subnet, &subnets[i]);

        printf("\n");
    }

    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}