//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 50
#define MAX_IP_LENGTH 16
#define MAX_SUBNET_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    char mask[MAX_IP_LENGTH];
    char subnet[MAX_SUBNET_LENGTH];
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

void add_subnet(char *ip, char *mask) {
    strcpy(subnets[num_subnets].ip, ip);
    strcpy(subnets[num_subnets].mask, mask);
    char *dot_ip = strtok(ip, ".");
    char *dot_mask = strtok(mask, ".");
    char subnet_ip[MAX_IP_LENGTH];
    char subnet_mask[MAX_IP_LENGTH];
    strcpy(subnet_ip, dot_ip);
    strcpy(subnet_mask, dot_mask);
    int i = 0;
    while (i < strlen(subnet_mask)) {
        if (subnet_mask[i] == '0') {
            if (subnet_ip[i] == '0' || subnet_ip[i] == '1') {
                subnets[num_subnets].subnet[i] = '0';
            } else {
                subnets[num_subnets].subnet[i] = '1';
            }
        } else if (subnet_mask[i] == '1') {
            if (subnet_ip[i] == '0' || subnet_ip[i] == '1') {
                subnets[num_subnets].subnet[i] = '1';
            } else {
                subnets[num_subnets].subnet[i] = '0';
            }
        }
        i++;
    }
    num_subnets++;
}

void print_subnets() {
    printf("IP Address\tSubnet Mask\tSubnet\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t%s\t%s\n", subnets[i].ip, subnets[i].mask, subnets[i].subnet);
    }
}

int main() {
    char ip[MAX_IP_LENGTH];
    char mask[MAX_IP_LENGTH];
    char subnet[MAX_SUBNET_LENGTH];
    printf("Enter the IP address: ");
    scanf("%s", ip);
    printf("Enter the subnet mask: ");
    scanf("%s", mask);
    strcpy(subnet, mask);
    add_subnet(ip, mask);
    print_subnets();
    return 0;
}