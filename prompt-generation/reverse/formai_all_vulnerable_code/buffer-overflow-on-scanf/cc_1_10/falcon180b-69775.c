//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 100

struct subnet {
    char name[10];
    int size;
    int start_ip[4];
    int end_ip[4];
};

int main() {
    int num_subnets, i, j, k;
    struct subnet subnets[MAX_SUBNETS];
    char input[100];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the size of subnet %s: ", subnets[i].name);
        scanf("%d", &subnets[i].size);

        printf("Enter the start IP address of subnet %s: ", subnets[i].name);
        for (j = 0; j < 4; j++) {
            scanf("%d", &subnets[i].start_ip[j]);
            if (j < 3) {
                printf(".");
            }
        }

        printf("Enter the end IP address of subnet %s: ", subnets[i].name);
        for (j = 0; j < 4; j++) {
            scanf("%d", &subnets[i].end_ip[j]);
            if (j < 3) {
                printf(". ");
            }
        }

        printf("\n");
    }

    printf("Subnet Name\tSubnet Size\tStart IP\tEnd IP\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\t\t%d\t\t", subnets[i].name, subnets[i].size);
        for (j = 0; j < 4; j++) {
            printf("%d. ", subnets[i].start_ip[j]);
        }
        printf("\t\t");
        for (j = 0; j < 4; j++) {
            printf("%d. ", subnets[i].end_ip[j]);
        }
        printf("\n");
    }

    return 0;
}