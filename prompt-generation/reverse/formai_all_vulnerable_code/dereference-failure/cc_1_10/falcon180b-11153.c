//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 8
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    int size;
} Subnet;

int main(int argc, char *argv[]) {
    int num_subnets, i, j;
    char input_string[MAX_SUBNET_SIZE];
    char delimiter;

    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    strcpy(input_string, argv[1]);
    delimiter = '.';

    num_subnets = 0;

    for (i = 1; i <= 8; i++) {
        if (num_subnets == MAX_SUBNETS) {
            printf("Maximum number of subnets reached.\n");
            break;
        }

        if (i == 1) {
            strcat(input_string, "0");
        } else {
            strcat(input_string, "1");
        }

        strcat(input_string, ".");

        for (j = 0; j < i - 1; j++) {
            strcat(input_string, "0");
        }

        strcat(input_string, &delimiter);

        printf("Subnet %d: %s\n", num_subnets + 1, input_string);
        num_subnets++;
    }

    return 0;
}