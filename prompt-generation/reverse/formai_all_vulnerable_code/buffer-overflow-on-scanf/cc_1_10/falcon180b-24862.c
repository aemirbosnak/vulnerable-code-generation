//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_LENGTH 20
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    char mask[MAX_IP_LENGTH];
    char gateway[MAX_IP_LENGTH];
    char dns1[MAX_IP_LENGTH];
    char dns2[MAX_IP_LENGTH];
} subnet_t;

int main() {
    int num_subnets;
    subnet_t subnets[MAX_SUBNETS];
    char input[MAX_IP_LENGTH];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter the IP address for subnet %d: ", i+1);
        scanf("%s", input);
        strcpy(subnets[i].ip, input);

        printf("Enter the mask for subnet %d: ", i+1);
        scanf("%s", input);
        strcpy(subnets[i].mask, input);

        printf("Enter the gateway for subnet %d: ", i+1);
        scanf("%s", input);
        strcpy(subnets[i].gateway, input);

        printf("Enter the DNS server 1 for subnet %d: ", i+1);
        scanf("%s", input);
        strcpy(subnets[i].dns1, input);

        printf("Enter the DNS server 2 for subnet %d: ", i+1);
        scanf("%s", input);
        strcpy(subnets[i].dns2, input);
    }

    printf("Subnet 1: \n");
    printf("IP address: %s\n", subnets[0].ip);
    printf("Mask: %s\n", subnets[0].mask);
    printf("Gateway: %s\n", subnets[0].gateway);
    printf("DNS server 1: %s\n", subnets[0].dns1);
    printf("DNS server 2: %s\n", subnets[0].dns2);

    return 0;
}