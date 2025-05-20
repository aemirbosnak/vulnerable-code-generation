//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Artistic reminder of Mother Nature's beauty
#define MAX 100    // The sky's the limit, but let's contain ourselves
#define BUCKET_COUNT 10   // A group of friends goes to the park

// Create a structure for our lovely buckets
typedef struct Bucket {
    float* items;          // Each bucket holds its own collection
    int itemCount;        // Count the joyful sounds (items) within
} Bucket;

// Function prototypes
void bucketSort(float arr[], int size);
void initializeBuckets(Bucket buckets[], int bucketCount);
void insertIntoBucket(Bucket* bucket, float value);
void sortBucket(Bucket* bucket);
void freeBuckets(Bucket buckets[], int bucketCount);
int compare(const void* a, const void* b);

// The main garden where all the actions take place
int main() {
    float itemsToSort[MAX]; // Array for elements to be sorted
    int n, i;

    // A cocoon of input
    printf("Enter the number of elements (max %d): ", MAX);
    scanf("%d", &n);
    printf("Write %d floating-point numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &itemsToSort[i]);
    }

    printf("The unsorted elements are: \n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", itemsToSort[i]);
    }
    printf("\n");

    // Let the magic happen
    bucketSort(itemsToSort, n);

    // The final sorted parade
    printf("The sorted elements are: \n");
    for (i = 0; i < n; i++) {
        printf("%.2f ", itemsToSort[i]);
    }
    printf("\n");

    return 0;
}

// The dance of the Bucket Sort mechanism
void bucketSort(float arr[], int size) {
    if (size <= 0) return; // Fall quietly into the abyss

    Bucket buckets[BUCKET_COUNT];
    initializeBuckets(buckets, BUCKET_COUNT);

    // Placing each element into its respective bucket
    for (int i = 0; i < size; i++) {
        int bucketIndex = (int)(arr[i] * BUCKET_COUNT); // Our bucket's index magic
        if (bucketIndex >= BUCKET_COUNT) {
            bucketIndex = BUCKET_COUNT - 1; // Do not overflow; our buckets need their peace!
        }
        insertIntoBucket(&buckets[bucketIndex], arr[i]);
    }

    // Sorting each bucket
    for (int i = 0; i < BUCKET_COUNT; i++) {
        sortBucket(&buckets[i]);
    }

    // Merging the sorted buckets back into the original array, like a beautiful river flowing
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < buckets[i].itemCount; j++) {
            arr[index++] = buckets[i].items[j];
        }
        free(buckets[i].items); // Letting the memory fly away
    }
}

// Initialize the buckets with care and gentle love
void initializeBuckets(Bucket buckets[], int bucketCount) {
    for (int i = 0; i < bucketCount; i++) {
        buckets[i].items = (float*)malloc(MAX * sizeof(float)); // Each bucket's crafted vessel
        buckets[i].itemCount = 0; // Empty baskets waiting for treasures
    }
}

// Insert into a given bucket with kindness
void insertIntoBucket(Bucket* bucket, float value) {
    bucket->items[bucket->itemCount++] = value; // Add joy
}

// Sort each bucket using a simple qsort (quick and beautiful!)
void sortBucket(Bucket* bucket) {
    if (bucket->itemCount > 0) {
        qsort(bucket->items, bucket->itemCount, sizeof(float), compare); // Sort the merry travelers
    }
}

// Free the memory of the buckets with a wish for good travels
void freeBuckets(Bucket buckets[], int bucketCount) {
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i].items);
    }
}

// Comparison function needed for qsort
int compare(const void* a, const void* b) {
    return (*(float*)a > *(float*)b) ? 1 : -1; // Simple comparison of the beautiful numbers
}