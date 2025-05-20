//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_ADDR_LEN 16
#define SUBNET_LEN 8

struct subnet {
    char ip_addr[IP_ADDR_LEN];
    char subnet_mask[SUBNET_LEN];
    int num_hosts;
};

void generate_subnets(char *ip_addr, int num_subnets) {
    struct subnet subnets[MAX_SUBNETS];
    int i, j, k, num_hosts;

    strcpy(subnets[0].ip_addr, ip_addr);
    num_hosts = (int)pow(2, 8 - (int)log(atoi("255"))/log(2)); // calculate number of hosts in the subnet

    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < 4; j++) { // iterate through the octets of the IP address
            if (subnets[0].ip_addr[j] == '0' && subnets[0].ip_addr[j+1] == '0') { // if the octet is 00, it's a reserved address
                subnets[i].ip_addr[j] = '1';
                subnets[i].ip_addr[j+1] = '0';
                break;
            } else if (subnets[0].ip_addr[j] == '0' && subnets[0].ip_addr[j+1] == '1') { // if the octet is 01, it's a network address
                subnets[i].ip_addr[j] = '1';
                subnets[i].ip_addr[j+1] = '1';
                break;
            } else if (subnets[0].ip_addr[j] == '1' && subnets[0].ip_addr[j+1] == '0') { // if the octet is 10, it's a broadcast address
                subnets[i].ip_addr[j] = '1';
                subnets[i].ip_addr[j+1] = '1';
                break;
            }
        }
        subnets[i].num_hosts = num_hosts;
        printf("%s\n", subnets[i].ip_addr);
    }
}

int main() {
    char ip_addr[IP_ADDR_LEN];

    printf("Enter the IP address: ");
    scanf("%s", ip_addr);

    generate_subnets(ip_addr, 10);

    return 0;
}