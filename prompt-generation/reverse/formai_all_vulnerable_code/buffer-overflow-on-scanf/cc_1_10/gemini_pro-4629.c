//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Watson, gather the suspects and scrutinize their ages
int* suspectsAges(int suspectsCount, int* ages) {
    int minAge = ages[0];
    int maxAge = ages[0];
    for (int i = 1; i < suspectsCount; i++) {
        if (ages[i] < minAge) {
            minAge = ages[i];
        } else if (ages[i] > maxAge) {
            maxAge = ages[i];
        }
    }

    // Establish the age buckets
    int bucketCount = maxAge - minAge + 1;
    int* buckets = (int*) malloc(sizeof(int) * bucketCount);
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = 0;
    }

    // Fill the age buckets
    for (int i = 0; i < suspectsCount; i++) {
        int ageIndex = ages[i] - minAge;
        buckets[ageIndex]++;
    }

    // Reconstruct the ages list
    int* sortedAges = (int*) malloc(sizeof(int) * suspectsCount);
    int sortedIndex = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            sortedAges[sortedIndex++] = i + minAge;
        }
    }

    return sortedAges;
}

int main() {
    printf("Watson, the case of the mysterious ages has come to our attention.\n");
    printf("Gather the ages of the suspects and we shall scrutinize them.\n");

    // Gather the suspects' ages
    int suspectsCount;
    printf("How many suspects are there, Watson?\n");
    scanf("%d", &suspectsCount);

    int* ages = (int*) malloc(sizeof(int) * suspectsCount);
    for (int i = 0; i < suspectsCount; i++) {
        printf("Enter the age of suspect %d, Watson:\n", i + 1);
        scanf("%d", &ages[i]);
    }

    // Sort the ages using our ingenious bucket sort algorithm
    int* sortedAges = suspectsAges(suspectsCount, ages);

    // Present the sorted ages to Holmes
    printf("\nElementary, my dear Watson! The sorted ages of the suspects are:\n");
    for (int i = 0; i < suspectsCount; i++) {
        printf("%d ", sortedAges[i]);
    }
    printf("\n");

    // Release the suspects (and the memory)
    free(ages);
    free(sortedAges);

    return 0;
}