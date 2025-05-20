#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000

int main() {
    int num_bags, min_weight, max_weight;
    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);
    printf("Enter the minimum weight: ");
    scanf("%d", &min_weight);
    printf("Enter the maximum weight: ");
    scanf("%d", &max_weight);

    srand(time(NULL));

    int bags[num_bags];

    for (int i = 0; i < num_bags; ++i) {
        bags[i] = rand() % (max_weight - min_weight + 1) + min_weight;
    }

    int total_weight = 0;
    for (int i = 0; i < num_bags; ++i) {
        total_weight += bags[i];
    }

    printf("Total weight: %d\n", total_weight);

    return 0;
}
