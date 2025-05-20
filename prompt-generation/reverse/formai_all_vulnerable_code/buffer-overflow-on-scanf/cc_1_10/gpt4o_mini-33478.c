//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SCORE 100
#define NUMBER_OF_BUCKETS 10

// Function to perform Bucket Sort
void bucketSort(int scores[], int n) {
    // Create buckets
    int **buckets = (int **)malloc(NUMBER_OF_BUCKETS * sizeof(int *));
    int *bucketCounts = (int *)malloc(NUMBER_OF_BUCKETS * sizeof(int));
    
    for(int i = 0; i < NUMBER_OF_BUCKETS; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int)); // max n size for worst case
        bucketCounts[i] = 0; // initialize counters to 0
    }
    
    // Distribute scores into buckets
    for (int i = 0; i < n; i++) {
        int index = scores[i] / (MAX_SCORE / NUMBER_OF_BUCKETS);
        if (index >= NUMBER_OF_BUCKETS) {
            index = NUMBER_OF_BUCKETS - 1; // last bucket for max score
        }
        buckets[index][bucketCounts[index]++] = scores[i];
    }

    // Sort individual buckets and concatenate them
    int index = 0;
    for (int i = 0; i < NUMBER_OF_BUCKETS; i++) {
        // Simple Insertion Sort for individual buckets
        for (int j = 1; j < bucketCounts[i]; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            
            // Move elements of buckets[i], that are greater than key,
            // to one position ahead of their current position
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
        
        // Copy sorted bucket back to scores array
        for (int j = 0; j < bucketCounts[i]; j++) {
            scores[index++] = buckets[i][j];
        }
    }
    
    // Free allocated memory
    for (int i = 0; i < NUMBER_OF_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketCounts);
}

// Function to generate random scores for bakers
void generateRandomScores(int scores[], int n) {
    for (int i = 0; i < n; i++) {
        scores[i] = rand() % (MAX_SCORE + 1);
    }
}

// Function to print scores
void printScores(int scores[], int n) {
    printf("Scores:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    printf("Welcome to the Baking Competition Score Sorter!\n");
    printf("Please enter the number of bakers: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number of bakers. Exiting.\n");
        return 1;
    }
    
    int *scores = (int *)malloc(n * sizeof(int));
    
    // Generate random scores for the bakers
    generateRandomScores(scores, n);
    
    // Print unsorted scores
    printScores(scores, n);

    // Perform Bucket Sort
    bucketSort(scores, n);

    // Print sorted scores
    printf("Sorted Scores:\n");
    printScores(scores, n);

    // Free allocated memory
    free(scores);
    
    printf("Thank you for using the Baking Competition Score Sorter!\n");
    return 0;
}