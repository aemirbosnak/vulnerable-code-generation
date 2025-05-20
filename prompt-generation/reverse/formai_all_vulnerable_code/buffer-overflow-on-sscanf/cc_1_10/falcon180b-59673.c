//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100

struct subnet {
    char name[20];
    int num_hosts;
};

void add_subnet(struct subnet *subnets, int num_subnets, char *name, int num_hosts) {
    int i;
    for (i = 0; i < num_subnets; i++) {
        if (strcmp(subnets[i].name, name) == 0) {
            subnets[i].num_hosts += num_hosts;
            return;
        }
    }
    strcpy(subnets[num_subnets].name, name);
    subnets[num_subnets].num_hosts = num_hosts;
    num_subnets++;
}

void print_subnets(struct subnet *subnets, int num_subnets) {
    int i;
    for (i = 0; i < num_subnets; i++) {
        printf("%s: %d hosts\n", subnets[i].name, subnets[i].num_hosts);
    }
}

int main() {
    char input[100];
    struct subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    printf("Enter subnet information in the following format: subnet_name num_hosts\n");

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *token = strtok(input, " ");
        if (token == NULL) {
            continue;
        }
        char *subnet_name = token;
        int num_hosts;
        sscanf(input, "%s %d", subnet_name, &num_hosts);
        add_subnet(subnets, num_subnets, subnet_name, num_hosts);
        num_subnets++;
    }

    print_subnets(subnets, num_subnets);

    return 0;
}