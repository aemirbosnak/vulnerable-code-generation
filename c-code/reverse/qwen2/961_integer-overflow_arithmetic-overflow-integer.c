#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_WEIGHT 50
#define MIN_WEIGHT 1

int main() {
    int num_bags, max_weight, min_weight;
    srand(time(0));

    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);

    if (num_bags > MAX_BAGS) {
        printf("Number of bags exceeds maximum limit.\n");
        return 1;
    }

    printf("Enter the maximum weight per bag: ");
    scanf("%d", &max_weight);
    if (max_weight > MAX_WEIGHT || max_weight < MIN_WEIGHT) {
        printf("Invalid maximum weight.\n");
        return 1;
    }

    printf("Enter the minimum weight per bag: ");
    scanf("%d", &min_weight);
    if (min_weight > max_weight || min_weight < MIN_WEIGHT) {
        printf("Invalid minimum weight.\n");
        return 1;
    }

    int bags[MAX_BAGS];
    for (int i = 0; i < num_bags; i++) {
        bags[i] = rand() % (max_weight - min_weight + 1) + min_weight;
    }

    printf("\nLoading bags...\n");
    for (int i = 0; i < num_bags; i++) {
        if (bags[i] <= 30) {
            printf("Bag %d loaded with weight %d\n", i + 1, bags[i]);
        } else {
            printf("Bag %d removed due to excess weight\n", i + 1);
        }
    }

    return 0;
}
