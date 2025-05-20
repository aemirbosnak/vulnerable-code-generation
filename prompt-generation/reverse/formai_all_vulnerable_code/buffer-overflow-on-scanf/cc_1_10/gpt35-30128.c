//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIES 1000

typedef struct Candy {
    int weight;
    int value;
} Candy;

int compare(const void *a, const void *b) {
    Candy *candyA = (Candy *) a;
    Candy *candyB = (Candy *) b;
    double ratioA = candyA->value / (double) candyA->weight;
    double ratioB = candyB->value / (double) candyB->weight;
    if (ratioA < ratioB) {
        return 1;
    } else if (ratioA > ratioB) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int numCandies;
    int maxWeight;
    Candy candies[MAX_CANDIES];
    printf("Enter the number of candies: ");
    scanf("%d", &numCandies);
    printf("Enter the maximum weight the bag can hold: ");
    scanf("%d", &maxWeight);
    for (int i = 0; i < numCandies; i++) {
        printf("Enter the weight and value of candy %d: ", i + 1);
        scanf("%d %d", &candies[i].weight, &candies[i].value);
    }
    qsort(candies, numCandies, sizeof(Candy), compare);
    int currentWeight = 0;
    double currentScore = 0.0;
    printf("Candies to take:\n");
    for (int i = 0; i < numCandies; i++) {
        if (currentWeight + candies[i].weight <= maxWeight) {
            currentWeight += candies[i].weight;
            currentScore += candies[i].value;
            printf("Candy %d (%d, %d)\n", i + 1, candies[i].weight, candies[i].value);
        } else {
            int remainingWeight = maxWeight - currentWeight;
            double remainingValue = candies[i].value * (remainingWeight / (double) candies[i].weight);
            currentWeight += remainingWeight;
            currentScore += remainingValue;
            printf("Partial candy %d (%d, %d)\n", i + 1, remainingWeight, (int) remainingValue);
            break;
        }
    }
    printf("Total weight: %d\nTotal value: %.2f\n", currentWeight, currentScore);
    return 0;
}