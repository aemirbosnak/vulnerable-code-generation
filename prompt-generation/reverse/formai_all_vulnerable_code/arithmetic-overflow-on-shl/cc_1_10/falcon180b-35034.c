//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_IP_LEN 16

typedef struct {
    char ip[MAX_IP_LEN];
    int mask;
    int num_subnets;
    int subnet_size;
    char *subnet_ips[MAX_SUBNETS];
} Subnet;

void generate_subnets(Subnet *subnet) {
    int i, j, k, num_subnets = 0;
    char ip[MAX_IP_LEN];
    strcpy(ip, subnet->ip);
    int mask = subnet->mask;
    int subnet_size = 0;

    for (i = 0; i < 4; i++) {
        if (mask & 0x80) {
            subnet_size = 1 << ((mask & 0x7F) - 1);
            break;
        }
        mask <<= 1;
    }

    for (i = 0; i < 4; i++) {
        if (mask & 0x80) {
            for (j = 0; j < 256; j++) {
                if ((j & 0xFF) == (mask & 0xFF)) {
                    for (k = 0; k < subnet_size; k++) {
                        sprintf(subnet->subnet_ips[num_subnets], "%s.%d", ip, j + k);
                        num_subnets++;
                    }
                }
            }
        }
        mask <<= 1;
    }
}

int main() {
    Subnet subnet;
    printf("Enter the IP address: ");
    scanf("%s", subnet.ip);
    printf("Enter the subnet mask: ");
    scanf("%d", &subnet.mask);
    generate_subnets(&subnet);
    printf("Subnet IPs:\n");
    for (int i = 0; i < subnet.num_subnets; i++) {
        printf("%s\n", subnet.subnet_ips[i]);
    }
    return 0;
}