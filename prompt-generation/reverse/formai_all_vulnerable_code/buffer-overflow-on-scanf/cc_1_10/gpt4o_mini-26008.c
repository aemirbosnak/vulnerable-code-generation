//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// A noble heart does crave for order,
// Thus, we embark upon the bucket's journey.

void bucketSort(float arr[], int n);
void sortBucket(float bucket[], int bucketSize);
void printArray(float arr[], int size);

// O, each noble bucket, do rise to the occasion,
// Sorting and arranging in proper formation.
// A function swift and true like love's sweet embrace.

int main() {
    int n;
    printf("Oh, gentle friend, how many numbers dost thou wish to sort? ");
    scanf("%d", &n);

    float *arr = (float *)malloc(n * sizeof(float));
    
    printf("Enter the numbers of thy fair desire:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Before sorting, thy array doth appear as:\n");
    printArray(arr, n);

    bucketSort(arr, n);
    
    printf("After the tempestuous sorting, behold!\n");
    printArray(arr, n);

    free(arr);
    return 0;
}

// O, the buckets so divine!
// Memory for each they shall aspire.

void bucketSort(float arr[], int n) {
    if (n <= 0) return;

    // Create `n` buckets for storage,
    // To catch the gentle numbers in their mirage.
    float *buckets[n];
    int bucketSizes[n];

    for (int i = 0; i < n; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // We assign each number to a bucket based on its grace,
    // A delicate sorting of their rightful place.
    for (int i = 0; i < n; i++) {
        int index = n * arr[i]; // the index of thy bucket dost lie.
        if (index >= n) index = n - 1;
        buckets[index][bucketSizes[index]++] = arr[i];
    }

    // Now, gentle buckets, sort each in thy aid,
    // For in love as in life, order must be laid.
    for (int i = 0; i < n; i++) {
        sortBucket(buckets[i], bucketSizes[i]);
    }

    // Now we shall gather the fruits of our labor,
    // And place them all back with nought but a favor.
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]); // We must free that which we no longer need,
    }
}

// An intimate embrace of two, this function dost reveal,
// For each bucket to be sorted with great zeal.
void sortBucket(float bucket[], int bucketSize) {
    for (int i = 0; i < bucketSize - 1; i++) {
        for (int j = 0; j < bucketSize - i - 1; j++) {
            if (bucket[j] > bucket[j + 1]) {
                float temp = bucket[j];
                bucket[j] = bucket[j + 1];
                bucket[j + 1] = temp;
            }
        }
    }
}

// Hark! The array dost wish to be printed,
// Forth it emerges, as love hath hinted.
void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            printf("%.2f\n", arr[i]);
        } else {
            printf("%.2f, ", arr[i]);
        }
    }
}