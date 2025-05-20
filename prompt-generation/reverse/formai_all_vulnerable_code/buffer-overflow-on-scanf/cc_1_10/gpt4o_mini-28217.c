//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000
#define NUM_BUCKETS 10
#define RANGE 100.0 // range of numbers to be sorted

typedef struct Bucket {
    float *items;
    int count;
} Bucket;

void initializeBuckets(Bucket buckets[], int num_buckets) {
    for (int i = 0; i < num_buckets; i++) {
        buckets[i].items = (float *)malloc(MAX * sizeof(float));
        buckets[i].count = 0;
    }
}

void freeBuckets(Bucket buckets[], int num_buckets) {
    for (int i = 0; i < num_buckets; i++) {
        free(buckets[i].items);
    }
}

void bucketSort(float arr[], int n) {
    Bucket buckets[NUM_BUCKETS];
    initializeBuckets(buckets, NUM_BUCKETS);

    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * NUM_BUCKETS / RANGE);
        if (index >= NUM_BUCKETS) {
            index = NUM_BUCKETS - 1; // push to last bucket
        }
        buckets[index].items[buckets[index].count++] = arr[i];
    }

    for (int i = 0; i < NUM_BUCKETS; i++) {
        // Sort individual buckets using insertion sort
        for (int j = 1; j < buckets[i].count; j++) {
            float key = buckets[i].items[j];
            int k = j - 1;
            while (k >= 0 && buckets[i].items[k] > key) {
                buckets[i].items[k + 1] = buckets[i].items[k];
                k--;
            }
            buckets[i].items[k + 1] = key;
        }
    }

    // Recollect sorted elements
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[index++] = buckets[i].items[j];
        }
    }

    freeBuckets(buckets, NUM_BUCKETS);
}

void displayArray(float arr[], int n) {
    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

float getRandomFloat() {
    return ((float)rand() / (float)(RAND_MAX)) * RANGE;
}

void populateArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = getRandomFloat();
    }
}

int main() {
    srand((unsigned int)time(NULL));

    printf("Welcome to the Magical Bucket Sort!\n");
    
    int n;
    printf("Enter the number of elements (max 1000): ");
    scanf("%d", &n);
    if (n > MAX) n = MAX;

    float arr[MAX];
    populateArray(arr, n);

    printf("Generated Array:\n");
    displayArray(arr, n);

    bucketSort(arr, n);
    displayArray(arr, n);

    return 0;
}