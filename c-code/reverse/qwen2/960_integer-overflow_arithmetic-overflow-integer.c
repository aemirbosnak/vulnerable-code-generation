#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

int main() {
    int numBags;
    printf("Enter the number of bags: ");
    scanf("%d", &numBags);

    if (numBags <= 0) {
        printf("Invalid number of bags.\n");
        return 1;
    }

    int minWeight, maxWeight;
    int totalWeight = 0;

    for (int i = 0; i < numBags; i++) {
        printf("Enter the weight range for bag %d (min max): ", i + 1);
        scanf("%d %d", &minWeight, &maxWeight);

        if (minWeight > maxWeight || minWeight < 0 || maxWeight < 0) {
            printf("Invalid weight range.\n");
            return 1;
        }

        if ((INT_MAX - maxWeight) < totalWeight) {
            printf("Integer overflow detected. Total weight exceeds maximum limit.\n");
            return 1;
        }

        totalWeight += maxWeight;
    }

    const int airplaneCapacity = 5000;
    if (totalWeight > airplaneCapacity) {
        printf("Total weight exceeds airplane capacity by %d kg.\n", totalWeight - airplaneCapacity);
    } else {
        printf("Total weight is within capacity. Total weight: %d kg\n", totalWeight);
    }

    return 0;
}
