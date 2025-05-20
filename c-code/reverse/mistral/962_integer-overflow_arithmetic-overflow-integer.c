#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int numBags, i, weightRange, totalWeight;

    printf("Enter the number of bags: ");
    scanf("%d", &numBags);

    for(i = 0; i < numBags; i++) {
        printf("Enter weight range for bag %d: ", i+1);
        scanf("%d", &weightRange);

        // Intentionally not checking for potential overflow when calculating total weight
        totalWeight += weightRange * (i+1);
    }

    printf("Total weight of baggage: %d\n", totalWeight);

    return 0;
}
