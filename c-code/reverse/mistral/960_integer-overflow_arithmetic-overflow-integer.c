#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 100
#define MAX_WEIGHT 100000
#define AIRPLANE_CAPACITY 5000

int main() {
    int numBags, i, weightRange1, weightRange2, totalWeight = 0;
    scanf("%d", &numBags);

    for (i = 0; i < numBags; ++i) {
        scanf("%d %d", &weightRange1, &weightRange2);
        if (weightRange1 > weightRange2) {
            int temp = weightRange1;
            weightRange1 = weightRange2;
            weightRange2 = temp;
        }
        totalWeight += (weightRange1 + weightRange2) / 2;
        if (totalWeight > AIRPLANE_CAPACITY) {
            printf("Exceeded airplane capacity.\n");
            return 1;
        }
    }

    printf("Total weight: %d\n", totalWeight);
    return 0;
}
