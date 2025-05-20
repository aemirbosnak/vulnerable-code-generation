//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    int ip[4], mask[4], subnet[4], wildcard[4];
    char choice;

    printf("Welcome to the C Subnet Calculator!\n\n");
    printf("Please enter your IPv4 address in the following format: x.x.x.x\n");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("\nGreat, now let's enter your subnet mask in the following format: x.x.x.x\n");
    scanf("%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    printf("\nCalculating your subnet...\n");

    for (int i=0; i<4; i++) {
        subnet[i] = ip[i] & mask[i];
        wildcard[i] = 255 - mask[i];
    }

    printf("\nYour subnet is: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("The wildcard mask is: %d.%d.%d.%d\n", wildcard[0], wildcard[1], wildcard[2], wildcard[3]);

    printf("\nWould you like to calculate another subnet? (y/n)\n");
    scanf(" %c", &choice);

    while (choice == 'y') {
        printf("\nPlease enter your IPv4 address in the following format: x.x.x.x\n");
        scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

        printf("\nGreat, now let's enter your subnet mask in the following format: x.x.x.x\n");
        scanf("%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

        printf("\nCalculating your subnet...\n");

        for (int i=0; i<4; i++) {
            subnet[i] = ip[i] & mask[i];
            wildcard[i] = 255 - mask[i];
        }

        printf("\nYour subnet is: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
        printf("The wildcard mask is: %d.%d.%d.%d\n", wildcard[0], wildcard[1], wildcard[2], wildcard[3]);

        printf("\nWould you like to calculate another subnet? (y/n)\n");
        scanf(" %c", &choice);
    }

    printf("\nThank you for using the C Subnet Calculator!\n");

    return 0;
}