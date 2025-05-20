//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32

typedef struct {
    char ip[16];
    char subnet[16];
    char broadcast[16];
} subnet_t;

subnet_t subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet(char* ip, char* subnet) {
    strcpy(subnets[num_subnets].ip, ip);
    strcpy(subnets[num_subnets].subnet, subnet);
    sprintf(subnets[num_subnets].broadcast, "%s.255", subnet);
    num_subnets++;
}

int main() {
    char ip[16];
    char subnet[16];
    char* token;

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask: ");
    scanf("%s", subnet);

    token = strtok(subnet, ".");
    while (token!= NULL) {
        int val = atoi(token);
        if (val == 0 || val == 255) {
            printf("Invalid subnet mask.\n");
            exit(1);
        }
        token = strtok(NULL, ".");
    }

    add_subnet(ip, subnet);

    printf("Subnet IP: %s\n", subnets[0].ip);
    printf("Subnet Mask: %s\n", subnets[0].subnet);
    printf("Broadcast IP: %s\n", subnets[0].broadcast);

    return 0;
}