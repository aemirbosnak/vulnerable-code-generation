//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
    char ip1[16];
    char ip2[16];
    char mask[16];
    char network[4];
    char broadcast[4];

    printf("Enter two IP addresses and a subnet mask: ");
    gets(ip1);
    gets(ip2);
    gets(mask);

    if (strlen(ip1)!= 15 || strlen(ip2)!= 15 || strlen(mask)!= 16) {
        printf("Invalid input. Please enter valid IP addresses and subnet mask.\n");
        return 1;
    }

    strcpy(network, &ip1[strlen(ip1) - 12]);
    strcpy(broadcast, &ip1[strlen(ip1) - 8]);

    int mask_len = strlen(mask);
    int mask_bits = 32 - mask_len;
    int ip_len = strlen(ip1);
    int ip_bits = 32 - ip_len;
    int subnet_bits = ip_bits - mask_bits;
    int subnet_mask_len = (mask_len - subnet_bits) / 8;

    printf("Subnet mask: ");
    for (int i = 0; i < subnet_mask_len; i++) {
        printf("%d.%d.%d.%d", 255 << (i * 8), 255 << (i * 8 + 1), 255 << (i * 8 + 2), 255 << (i * 8 + 3));
    }
    printf("\n");

    printf("Network address: ");
    for (int i = 0; i < subnet_mask_len; i++) {
        printf("%d.%d.%d.%d", 0, 0, 0, 0);
    }
    printf("\n");

    printf("Broadcast address: ");
    for (int i = 0; i < subnet_mask_len; i++) {
        printf("%d.%d.%d.%d", 0, 0, 0, 255);
    }
    printf("\n");

    if (strcmp(network, broadcast) == 0) {
        printf("The two IP addresses are in the same subnet.\n");
    } else {
        printf("The two IP addresses are not in the same subnet.\n");
    }

    return 0;
}