//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    int num_hosts;
} subnet_t;

int main() {
    int num_subnets;
    subnet_t subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter subnet name (up to %d characters): ", MAX_SUBNET_SIZE - 1);
        scanf("%s", subnets[i].name);

        printf("Enter subnet IP address: ");
        scanf("%s", subnets[i].ip);

        printf("Enter subnet mask: ");
        scanf("%s", subnets[i].mask);

        int num_octets = 0;
        for (int j = 0; subnets[i].mask[j]!= '\0'; j++) {
            if (subnets[i].mask[j] == '.') {
                num_octets++;
            }
        }

        if (num_octets!= 4) {
            printf("Error: Invalid subnet mask.\n");
            exit(1);
        }

        subnets[i].num_hosts = 0;
        for (int j = 0; subnets[i].mask[j]!= '\0'; j++) {
            if (subnets[i].mask[j] == '.') {
                continue;
            }

            switch (subnets[i].mask[j]) {
                case '0':
                    subnets[i].num_hosts += 1;
                    break;
                case '1':
                    subnets[i].num_hosts += 2;
                    break;
                case '2':
                    subnets[i].num_hosts += 4;
                    break;
                case '3':
                    subnets[i].num_hosts += 8;
                    break;
                case '4':
                    subnets[i].num_hosts += 16;
                    break;
                default:
                    printf("Error: Invalid subnet mask.\n");
                    exit(1);
            }
        }
    }

    printf("Subnet\tIP Address\tMask\t\tNumber of Hosts\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t%s\t%s\t\t%d\n", subnets[i].name, subnets[i].ip, subnets[i].mask, subnets[i].num_hosts);
    }

    return 0;
}