//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNETS 32
#define IP_LENGTH 15
#define MASK_LENGTH 4
#define MAX_MASK_VALUE 32

typedef struct {
    char ip[IP_LENGTH];
    int mask;
    int num_hosts;
    int broadcast_ip[IP_LENGTH];
} Subnet;

void calculate_subnet(Subnet *subnet) {
    int i, j, k, num_ones = 0;
    char *ip = subnet->ip;
    int mask = subnet->mask;

    for (i = 0; i < IP_LENGTH; i++) {
        if (ip[i] == '.') {
            for (j = 0; j < MASK_LENGTH; j++) {
                if (mask & (1 << j)) {
                    num_ones++;
                    break;
                }
            }
            if (num_ones == 0) {
                for (k = 0; k < MASK_LENGTH; k++) {
                    if (mask & (1 << k)) {
                        mask ^= (1 << k);
                        break;
                    }
                }
            }
        } else {
            if (ip[i] == '*') {
                mask = 0;
            } else {
                mask |= (ip[i] - '0') << (3 - i % 3);
            }
        }
    }

    subnet->num_hosts = pow(2, 8 - num_ones) - 2;
    subnet->broadcast_ip[0] = '\0';
    for (i = 0; i < IP_LENGTH; i++) {
        if (ip[i] == '.') {
            subnet->broadcast_ip[i] = '.';
        } else {
            if (ip[i] == '*') {
                for (j = 0; j < MASK_LENGTH; j++) {
                    if (mask & (1 << j)) {
                        subnet->broadcast_ip[i] = '*';
                        break;
                    }
                }
            } else {
                subnet->broadcast_ip[i] = ip[i];
            }
        }
    }
}

int main() {
    int num_subnets, i;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet #%d (ip/mask): ", i + 1);
        scanf("%s %s", subnets[i].ip, subnets[i].mask);
        calculate_subnet(&subnets[i]);
        printf("Subnet #%d: %s/%d (%d hosts, broadcast %s)\n", i + 1, subnets[i].ip, subnets[i].mask, subnets[i].num_hosts, subnets[i].broadcast_ip);
    }

    return 0;
}