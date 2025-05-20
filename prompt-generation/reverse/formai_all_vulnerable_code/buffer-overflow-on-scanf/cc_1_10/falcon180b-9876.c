//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 30
#define MAX_IP_SIZE 16

typedef struct {
    char ip[MAX_IP_SIZE];
    char mask[MAX_IP_SIZE];
    int num_hosts;
    int num_subnets;
    int first_subnet;
    int last_subnet;
} Subnet;

void calculate_subnets(Subnet *subnet) {
    int num_bits = strlen(subnet->mask);
    int num_subnets = pow(2, num_bits) - 2;
    subnet->num_subnets = num_subnets;
    subnet->first_subnet = 1;
    subnet->last_subnet = num_subnets;
    subnet->num_hosts = pow(2, num_bits) - 1;
}

void print_subnet(Subnet *subnet) {
    printf("IP Address: %s\n", subnet->ip);
    printf("Subnet Mask: %s\n", subnet->mask);
    printf("Number of Subnets: %d\n", subnet->num_subnets);
    printf("First Subnet: %d\n", subnet->first_subnet);
    printf("Last Subnet: %d\n", subnet->last_subnet);
    printf("Number of Hosts per Subnet: %d\n", subnet->num_hosts);
}

int main() {
    int num_subnets;
    char ip[MAX_IP_SIZE];
    char mask[MAX_IP_SIZE];
    Subnet subnets[MAX_SUBNETS];

    printf("Enter IP Address: ");
    scanf("%s", ip);

    printf("Enter Subnet Mask: ");
    scanf("%s", mask);

    num_subnets = 0;

    while(num_subnets < MAX_SUBNETS) {
        Subnet *curr_subnet = &subnets[num_subnets];
        strcpy(curr_subnet->ip, ip);
        strcpy(curr_subnet->mask, mask);
        calculate_subnets(curr_subnet);
        num_subnets++;
    }

    printf("Number of Subnets: %d\n", num_subnets);

    for(int i=0; i<num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}