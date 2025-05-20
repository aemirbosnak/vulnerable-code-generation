//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_IP_LENGTH 15

struct subnet {
    char ip[MAX_IP_LENGTH];
    char mask[MAX_IP_LENGTH];
    char broadcast[MAX_IP_LENGTH];
};

void generate_subnet_mask(char *ip, char *mask) {
    int i, j;
    for (i = 0, j = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            mask[j++] = '.';
        } else {
            mask[j++] = ip[i];
        }
    }
    mask[j] = '\0';
}

void generate_broadcast_ip(char *ip, char *mask) {
    int i, j;
    for (i = 0, j = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            if (j == strlen(mask) - 1) {
                mask[j++] = '.';
            }
        } else {
            if (mask[j] == '.' || mask[j] == '0') {
                mask[j++] = '1';
            } else if (mask[j] == '1') {
                mask[j++] = '0';
            }
        }
    }
    mask[j] = '\0';
}

int main() {
    int num_subnets, i;
    char ip[MAX_IP_LENGTH], mask[MAX_IP_LENGTH], broadcast[MAX_IP_LENGTH];
    struct subnet subnets[MAX_SUBNETS];

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Subnet IP\tSubnet Mask\tBroadcast IP\n");

    for (i = 0; i < num_subnets; i++) {
        generate_subnet_mask(ip, mask);
        strcpy(subnets[i].ip, ip);
        strcpy(subnets[i].mask, mask);
        generate_broadcast_ip(subnets[i].ip, subnets[i].mask);
        strcpy(subnets[i].broadcast, broadcast);

        printf("%s\t%s\t%s\n", subnets[i].ip, subnets[i].mask, subnets[i].broadcast);
    }

    return 0;
}