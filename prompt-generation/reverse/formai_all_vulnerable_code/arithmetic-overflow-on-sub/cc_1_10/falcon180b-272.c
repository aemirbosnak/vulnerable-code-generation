//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 1000

struct subnet {
    char name[MAX_SUBNET_SIZE];
    int size;
    int mask;
};

void add_subnet(struct subnet* subnets, int num_subnets, char* name, int size) {
    int i;
    for (i = 0; i < num_subnets; i++) {
        if (strcmp(subnets[i].name, name) == 0) {
            printf("Error: subnet %s already exists.\n", name);
            return;
        }
    }
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: maximum number of subnets reached.\n");
        return;
    }
    strcpy(subnets[num_subnets].name, name);
    subnets[num_subnets].size = size;
    subnets[num_subnets].mask = ~(0xFFFFFFFF >> size) << 32 - size;
    num_subnets++;
}

void delete_subnet(struct subnet* subnets, int num_subnets, char* name) {
    int i;
    for (i = 0; i < num_subnets; i++) {
        if (strcmp(subnets[i].name, name) == 0) {
            memmove(&subnets[i], &subnets[i + 1], (num_subnets - i - 1) * sizeof(struct subnet));
            num_subnets--;
            return;
        }
    }
    printf("Error: subnet %s not found.\n", name);
}

void list_subnets(struct subnet* subnets, int num_subnets) {
    int i;
    for (i = 0; i < num_subnets; i++) {
        printf("%s (%d hosts)\n", subnets[i].name, (int)pow(2, 32 - subnets[i].size) - 1);
    }
}

int main() {
    struct subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;
    char command[MAX_SUBNET_SIZE];

    while (1) {
        printf("> ");
        fgets(command, MAX_SUBNET_SIZE, stdin);
        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            char name[MAX_SUBNET_SIZE];
            int size;
            sscanf(command, "add %s %d", name, &size);
            add_subnet(subnets, num_subnets, name, size);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_SUBNET_SIZE];
            sscanf(command, "delete %s", name);
            delete_subnet(subnets, num_subnets, name);
        } else if (strcmp(command, "list") == 0) {
            list_subnets(subnets, num_subnets);
        }
    }

    return 0;
}