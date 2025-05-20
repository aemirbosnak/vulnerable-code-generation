//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTICIPANTS 100
#define BUCKET_COUNT 10

// A structure for bucket
struct Bucket {
    int *scores;
    int count;
};

// Function to create all buckets
struct Bucket* createBuckets(int count) {
    struct Bucket *buckets = malloc(count * sizeof(struct Bucket));
    for (int i = 0; i < count; i++) {
        buckets[i].scores = malloc(MAX_PARTICIPANTS * sizeof(int));
        buckets[i].count = 0;
    }
    return buckets;
}

// Function to free the allocated buckets
void freeBuckets(struct Bucket *buckets, int count) {
    for (int i = 0; i < count; i++) {
        free(buckets[i].scores);
    }
    free(buckets);
}

// Insertion sort for individual bucket
void insertionSort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function implementing Bucket Sort
void bucketSort(int *scores, int n) {
    // Create buckets
    struct Bucket *buckets = createBuckets(BUCKET_COUNT);

    // Populate buckets
    for (int i = 0; i < n; i++) {
        int index = scores[i] / (101 / BUCKET_COUNT);
        buckets[index].scores[buckets[index].count++] = scores[i];
    }

    // Sort each bucket and collect sorted scores
    int idx = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (buckets[i].count > 0) {
            insertionSort(buckets[i].scores, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                scores[idx++] = buckets[i].scores[j];
            }
        }
    }

    // Free allocated memory for buckets
    freeBuckets(buckets, BUCKET_COUNT);
}

// Function to generate random scores
void generateScores(int *scores, int n) {
    for (int i = 0; i < n; i++) {
        scores[i] = rand() % 101; // Scores from 0 to 100
    }
}

// Function to print scores
void printScores(int *scores, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int scores[MAX_PARTICIPANTS];

    printf("Welcome to The Bucket Challenge!\n");
    printf("Enter the number of participants (up to %d): ", MAX_PARTICIPANTS);
    scanf("%d", &n);

    if (n > MAX_PARTICIPANTS || n <= 0) {
        printf("Invalid number of participants. Please try again.\n");
        return 1;
    }

    // Generate random scores for participants
    generateScores(scores, n);
    
    printf("Scores before sorting:\n");
    printScores(scores, n);

    // Sort scores using Bucket Sort
    bucketSort(scores, n);

    printf("Scores after sorting:\n");
    printScores(scores, n);

    printf("Thank you for participating in The Bucket Challenge!\n");

    return 0;
}