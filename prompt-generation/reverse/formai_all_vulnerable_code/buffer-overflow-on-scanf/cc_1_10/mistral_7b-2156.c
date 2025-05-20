//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int happiness;
} candy;

void selection(candy candies[], int n, int max_weight, int *index) {
    int i, j;
    candy selected_candy;

    *index = 0;

    for (i = 0; i < n && max_weight > 0; i++) {
        if (candies[i].weight <= max_weight) {
            selected_candy = candies[i];
            *index = i;

            max_weight -= selected_candy.weight;

            printf("Selected candy %d with happiness %d and weight %d\n", *index + 1, selected_candy.happiness, selected_candy.weight);
        }
    }

    if (max_weight > 0) {
        printf("Cannot select candies with total weight less than or equal to %d\n", max_weight);
    }
}

int main() {
    int n, max_weight;
    candy candies[100];
    int index;

    printf("Enter number of candies: ");
    scanf("%d", &n);

    printf("Enter candies information:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &candies[i].weight, &candies[i].happiness);
    }

    printf("Enter maximum weight limit: ");
    scanf("%d", &max_weight);

    selection(candies, n, max_weight, &index);

    return 0;
}