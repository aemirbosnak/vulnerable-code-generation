//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_LEN 10
#define MAX_SUBNET_MASK 32
#define MAX_SUBNET_IP 16
#define MAX_SUBNET_NAME 32
#define MAX_SUBNET_COLOR 8

typedef struct {
    char name[MAX_SUBNET_NAME];
    char ip[MAX_SUBNET_IP];
    char mask[MAX_SUBNET_MASK];
    char color[MAX_SUBNET_COLOR];
} Subnet;

Subnet subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    printf("Enter subnet name (max %d characters): ", MAX_SUBNET_NAME);
    scanf("%s", subnets[num_subnets].name);

    printf("Enter subnet IP address (max %d characters): ", MAX_SUBNET_IP);
    scanf("%s", subnets[num_subnets].ip);

    printf("Enter subnet mask (max %d characters): ", MAX_SUBNET_MASK);
    scanf("%s", subnets[num_subnets].mask);

    printf("Enter subnet color (max %d characters): ", MAX_SUBNET_COLOR);
    scanf("%s", subnets[num_subnets].color);

    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("- %s (%s/%d) - %s\n", subnets[i].name, subnets[i].ip, atoi(subnets[i].mask), subnets[i].color);
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Surrealist Subnet Calculator!\n");
    printf("Please enter your desired number of subnets (1-%d): ", MAX_SUBNETS);
    int num_subnets_input;
    scanf("%d", &num_subnets_input);

    if (num_subnets_input < 1 || num_subnets_input > MAX_SUBNETS) {
        printf("Error: Invalid number of subnets.\n");
        return 1;
    }

    for (int i = 0; i < num_subnets_input; i++) {
        add_subnet();
    }

    print_subnets();

    return 0;
}