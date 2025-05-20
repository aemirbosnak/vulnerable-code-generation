//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 50
#define ERROR_MESSAGE "Invalid Input"

int main() {
    char ip[MAX_INPUT_SIZE];
    char subnet[MAX_INPUT_SIZE];
    char *token;

    printf("Enter IP address:\n");
    scanf("%s", ip);

    printf("Enter subnet mask:\n");
    scanf("%s", subnet);

    // parsing the IP address
    token = strtok(ip, ".");
    int ip_bytes[4];
    int i = 0;

    while(token != NULL) {
        ip_bytes[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    // parsing the subnet mask
    token = strtok(subnet, "/");
    int subnet_mask_bit_count;

    if(token != NULL) {
        subnet_mask_bit_count = atoi(token);
    } else {
        printf(ERROR_MESSAGE);
        return 1;
    }

    // calculate the subnet mask
    int subnet_mask_bytes[4] = { 0 };
    int j, k, mask;

    for(j = 0; j < 4; j++) {
        for(k = 7, mask = 1; k >= 0; k--) {
            if(mask <= subnet_mask_bit_count) {
                subnet_mask_bytes[j] += mask;
            }

            mask *= 2;
        }

        subnet_mask_bit_count -= 8;
    }

    // calculate the network address
    int network_address_bytes[4];

    for(i = 0; i < 4; i++) {
        network_address_bytes[i] = ip_bytes[i] & subnet_mask_bytes[i];
    }

    // print the results
    printf("\nIP Address: \n");

    for(i = 0; i < 4; i++) {
        printf("%d", ip_bytes[i]);

        if(i < 3) {
            printf(".");
        }
    }

    printf("\nSubnet Mask: \n");

    for(i = 0; i < 4; i++) {
        printf("%d", subnet_mask_bytes[i]);

        if(i < 3) {
            printf(".");
        }
    }

    printf("\nNetwork Address: \n");

    for(i = 0; i < 4; i++) {
        printf("%d", network_address_bytes[i]);

        if(i < 3) {
            printf(".");
        }
    }

    return 0;
}