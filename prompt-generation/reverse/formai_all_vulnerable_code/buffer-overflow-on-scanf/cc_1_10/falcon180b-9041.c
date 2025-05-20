//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 16
#define MAX_SUBNET_SIZE 16
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNETS];
    int size;
    char mask[MAX_SUBNET_MASK];
} subnet;

int main() {
    int n, i, j, k;
    char ip[MAX_SUBNETS][MAX_SUBNET_MASK];
    subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the IP address of subnet %d: ", i+1);
        scanf("%s", ip[i]);
        subnets[i].size = strlen(ip[i]);
        strcpy(subnets[i].name, ip[i]);

        for (j = 0; j < subnets[i].size; j++) {
            if (ip[i][j] == '.') {
                subnets[i].mask[j] = '0';
            } else {
                subnets[i].mask[j] = '1';
            }
        }
        subnets[i].mask[subnets[i].size] = '\0';
    }

    printf("Subnet\tIP Address\tMask\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%s\t", subnets[i].name, subnets[i].name);
        for (j = 0; j < subnets[i].size; j++) {
            if (subnets[i].mask[j] == '0') {
                printf("%.2X", (int)ip[i][j] & 0xFF);
            } else {
                printf("%.2X", (int)ip[i][j] & 0xFF);
            }
        }
        printf("\n");
    }

    return 0;
}