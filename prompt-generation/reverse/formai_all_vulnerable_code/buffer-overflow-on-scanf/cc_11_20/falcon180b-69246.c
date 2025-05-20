//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SUBNET 100
#define MAX_SUBNET_SIZE 30

typedef struct {
    char name[MAX_SUBNET_SIZE];
    int size;
    int mask;
    int first_ip;
    int last_ip;
} Subnet;

int main() {
    int num_subnets;
    int i, j, k;
    Subnet subnets[MAX_SUBNET];
    char input[MAX_SUBNET_SIZE];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for(i=0; i<num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the size of subnet %d: ", i+1);
        scanf("%d", &subnets[i].size);

        for(j=0; j<4; j++) {
            printf("Enter the %dth octet of the first IP address: ", j+1);
            scanf("%d", &subnets[i].first_ip + (j*8));
        }

        for(j=0; j<4; j++) {
            printf("Enter the %dth octet of the last IP address: ", j+1);
            scanf("%d", &subnets[i].last_ip + (j*8));
        }

        subnets[i].mask = 0;
        for(j=0; j<4; j++) {
            if(subnets[i].first_ip >> (3-j) & 1) {
                subnets[i].mask |= (0x80 >> j);
            }
            if(subnets[i].last_ip >> (3-j) & 1) {
                subnets[i].mask |= (0x80 >> j);
            }
        }
    }

    printf("Subnet\tIP Range\tMask\n");
    for(i=0; i<num_subnets; i++) {
        printf("%s\t", subnets[i].name);
        for(j=0; j<4; j++) {
            printf("%d.", (subnets[i].first_ip >> (3-j) & 0xFF));
        }
        printf("-");
        for(j=0; j<4; j++) {
            printf("%d.", (subnets[i].last_ip >> (3-j) & 0xFF));
        }
        printf("\t");
        for(j=0; j<4; j++) {
            printf("%d.", (subnets[i].mask >> (3-j) & 0xFF));
        }
        printf("\n");
    }

    return 0;
}