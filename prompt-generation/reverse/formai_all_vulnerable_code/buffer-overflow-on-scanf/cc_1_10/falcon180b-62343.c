//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_IP_LENGTH 15
#define MAX_SUBNET_LENGTH 15

typedef struct {
    char ip[MAX_IP_LENGTH];
    int subnet_length;
    char subnet[MAX_SUBNET_LENGTH];
} subnet_t;

int is_valid_ip(char *ip) {
    int i, j, num_dots = 0;
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            num_dots++;
        } else if (!isdigit(ip[i])) {
            return 0;
        }
    }
    return num_dots == 3;
}

int is_valid_subnet_length(int length) {
    return length >= 0 && length <= 32;
}

void print_subnet(subnet_t subnet) {
    printf("IP: %s\n", subnet.ip);
    printf("Subnet: %s\n", subnet.subnet);
    printf("Subnet Length: %d\n\n", subnet.subnet_length);
}

int main() {
    int num_subnets = 0;
    subnet_t subnets[MAX_SUBNETS];

    printf("Enter IP address: ");
    scanf("%s", subnets[num_subnets].ip);

    while (is_valid_ip(subnets[num_subnets].ip)) {
        printf("Enter subnet length (0-32): ");
        scanf("%d", &subnets[num_subnets].subnet_length);

        if (!is_valid_subnet_length(subnets[num_subnets].subnet_length)) {
            printf("Invalid subnet length.\n");
            continue;
        }

        strcpy(subnets[num_subnets].subnet, subnets[num_subnets].ip);
        int i, j;
        for (i = strlen(subnets[num_subnets].subnet) - 1, j = subnets[num_subnets].subnet_length - 1; i >= 0 && j >= 0; i--, j--) {
            subnets[num_subnets].subnet[i] = '.';
        }
        subnets[num_subnets].subnet[i + 1] = '\0';

        num_subnets++;

        printf("Enter IP address: ");
        scanf("%s", subnets[num_subnets].ip);
    }

    printf("Number of subnets: %d\n", num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }

    return 0;
}