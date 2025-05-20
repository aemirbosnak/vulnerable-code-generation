//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_COUNT 1000

typedef struct {
    char ip[MAX_SUBNET_SIZE];
    int count;
} Subnet;

void add_subnet(Subnet *subnets, int count, char *ip) {
    if (count >= MAX_SUBNET_COUNT) {
        printf("Error: Too many subnets.\n");
        exit(1);
    }

    strncpy(subnets[count].ip, ip, MAX_SUBNET_SIZE);
    subnets[count].count = 1;
    count++;
}

int main() {
    char ip[MAX_SUBNET_SIZE];
    Subnet subnets[MAX_SUBNET_COUNT];
    int count = 0;

    printf("Enter the IP address: ");
    scanf("%s", ip);

    int i = 0;
    while (i < strlen(ip)) {
        if (ip[i] == '.') {
            add_subnet(subnets, count, ip);
            count++;
            i++;
        } else {
            i++;
        }
    }

    printf("Subnets:\n");
    for (int j = 0; j < count; j++) {
        printf("%s (%d)\n", subnets[j].ip, subnets[j].count);
    }

    return 0;
}