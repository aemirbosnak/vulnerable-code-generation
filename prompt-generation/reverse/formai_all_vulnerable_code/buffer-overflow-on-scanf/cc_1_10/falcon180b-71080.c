//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_SUBNETS 10

typedef struct {
    char ip[16];
    int prefix;
} Subnet;

void calculate_subnets(char* ip, int prefix, Subnet* subnets) {
    int i, j, k;
    char* octet;
    for (i = 0; i < 4; i++) {
        octet = strtok(ip, ".");
        for (j = 0; j < 256; j++) {
            if (j == 0 || j == 127)
                continue; // Reserved IP addresses
            for (k = 0; k < MAX_SUBNETS; k++) {
                if (subnets[k].ip[i] == 0) {
                    subnets[k].ip[i] = j;
                    subnets[k].prefix = prefix;
                    break;
                }
            }
            if (k == MAX_SUBNETS)
                break;
        }
    }
}

int main() {
    char ip[16];
    int prefix;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter an IP address: ");
    scanf("%s", ip);

    printf("Enter a prefix length: ");
    scanf("%d", &prefix);

    calculate_subnets(ip, prefix, subnets);

    printf("Subnets:\n");
    for (int i = 0; i < MAX_SUBNETS; i++) {
        if (subnets[i].ip[0] == 0)
            break;
        printf("%s/%d\n", subnets[i].ip, subnets[i].prefix);
    }

    return 0;
}