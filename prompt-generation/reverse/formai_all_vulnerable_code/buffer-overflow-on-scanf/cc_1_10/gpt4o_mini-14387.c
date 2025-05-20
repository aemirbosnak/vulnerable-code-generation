//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define BUCKET_COUNT 10

// Structure for the noble knight items
typedef struct NobleKnight {
    int value;
    struct NobleKnight* next;
} NobleKnight;

// Function to create a new NobleKnight item
NobleKnight* createNobleKnight(int value) {
    NobleKnight* newKnight = (NobleKnight*)malloc(sizeof(NobleKnight));
    newKnight->value = value;
    newKnight->next = NULL;
    return newKnight;
}

// Function to insert a Knight in the bucket
void insertIntoBucket(NobleKnight** bucket, int value) {
    NobleKnight* newKnight = createNobleKnight(value);
    newKnight->next = bucket[value];
    bucket[value] = newKnight;
}

// Function to collect all Noble Knights from the buckets
void collectBuckets(NobleKnight** bucket, int* array, int* size) {
    *size = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        NobleKnight* current = bucket[i];
        while (current != NULL) {
            array[(*size)++] = current->value;
            NobleKnight* temp = current;
            current = current->next;
            free(temp); // Free memory of the collected Knight
        }
    }
}

// The charming Bucket Sort function
void bucketSort(int* array, int size) {
    NobleKnight* buckets[BUCKET_COUNT] = { NULL };

    // Place each noble item into corresponding bucket
    for (int i = 0; i < size; i++) {
        int bucketIndex = array[i] / (MAX_ITEMS / BUCKET_COUNT);
        if (bucketIndex >= BUCKET_COUNT) {
            bucketIndex = BUCKET_COUNT - 1; // stays within bounds
        }
        insertIntoBucket(&buckets[bucketIndex], array[i]);
    }

    // Collecting all the noble items back into an array
    int index = 0;
    collectBuckets(buckets, array, &index);

    // Nominate the noble knights again for sorting them
    printf("Noble Knights have sorted themselves in the array: \n");
    for (int i = 0; i < index; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// A medieval binding to the main kingdom
int main() {
    int nobilityArray[MAX_ITEMS];
    int numberOfNobles;

    // Summon the knights and their strengths
    printf("Enter the number of noble knights (max %d): ", MAX_ITEMS);
    scanf("%d", &numberOfNobles);

    if (numberOfNobles > MAX_ITEMS || numberOfNobles < 1) {
        printf("Alas! The number of noble knights must be between 1 and %d.\n", MAX_ITEMS);
        return -1;
    }

    printf("Enter the strength of each noble knight:\n");
    for (int i = 0; i < numberOfNobles; i++) {
        scanf("%d", &nobilityArray[i]);
    }

    // Activate the sorting spell of Bucket Sort
    bucketSort(nobilityArray, numberOfNobles);

    // Farewell to the knights
    return 0;
}