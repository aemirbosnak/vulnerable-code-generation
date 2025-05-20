#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_BAGS 100

int main() {
    int numBags;
    float weightLimit = 50.0;
    float weights[MAX_BAGS];
    int i;

    printf("Enter the number of bags: ");
    scanf("%d", &numBags);

    if (numBags > MAX_BAGS) {
        printf("Too many bags!\n");
        return 1;
    }

    printf("Enter the weight of each bag:\n");
    for (i = 0; i < numBags; i++) {
        scanf("%f", &weights[i]);
    }

    printf("Loading bags...\n");
    for (i = 0; i < numBags; i++) {
        if (weights[i] <= weightLimit) {
            printf("Bag %d loaded.\n", i + 1);
        } else {
            printf("Bag %d exceeds weight limit and is removed.\n", i + 1);
        }
    }

    return 0;
}
