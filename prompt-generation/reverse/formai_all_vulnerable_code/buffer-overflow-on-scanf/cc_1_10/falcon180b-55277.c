//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32

typedef struct {
    char ip[16];
    int size;
} Subnet;

void calc_subnets(Subnet *subnets, int num_subnets, int size, int start_index, int *current_index) {
    if (*current_index >= num_subnets) {
        return;
    }

    subnets[*current_index].size = size;
    strcpy(subnets[*current_index].ip, "192.168.0.");
    sprintf(&subnets[*current_index].ip[15], "%d", start_index + 1);

    (*current_index)++;

    if (size > 1) {
        calc_subnets(subnets, num_subnets, size - 1, start_index, current_index);
    }
}

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    Subnet subnets[MAX_SUBNETS];
    int current_index = 0;

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d\n", MAX_SUBNETS);
        return 1;
    }

    for (int i = 0; i < num_subnets; i++) {
        int size;
        printf("Enter the size of subnet %d: ", i + 1);
        scanf("%d", &size);

        if (size < 2 || size > MAX_SUBNET_SIZE) {
            printf("Error: Subnet size must be between 2 and %d\n", MAX_SUBNET_SIZE);
            return 1;
        }

        calc_subnets(subnets, num_subnets, size, i * (MAX_SUBNET_SIZE / num_subnets), &current_index);
    }

    printf("Subnets:\n");
    for (int i = 0; i < current_index; i++) {
        printf("%s\n", subnets[i].ip);
    }

    return 0;
}