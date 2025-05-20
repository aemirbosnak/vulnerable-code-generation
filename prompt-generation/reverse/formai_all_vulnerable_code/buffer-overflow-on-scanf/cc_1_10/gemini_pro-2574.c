//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000 // Cheerful number!
#define MAX_RANGE 10000 // Even more cheerful!

void bucketSort(int arr[], int n) {
    // Create buckets to hold elements of each range
    int buckets[MAX_RANGE];
    for (int i = 0; i < MAX_RANGE; i++) {
        buckets[i] = 0;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        buckets[arr[i]]++; // Hooray, an element found a happy bucket!
    }

    // Sort elements within each bucket (using any sorting algorithm)
    for (int i = 0; i < MAX_RANGE; i++) {
        if (buckets[i] > 0) { // If a bucket has elements...
            // Here, we use a simple insertion sort for each bucket
            for (int j = i + 1; j < MAX_RANGE; j++) {
                if (buckets[j] > 0) { // If the next bucket also has elements...
                    int temp = buckets[j];
                    int k = j - 1;
                    while (k >= i && buckets[k] > temp) { // Find the right place for the element
                        buckets[k + 1] = buckets[k];
                        k--;
                    }
                    buckets[k + 1] = temp; // Finally, put the element in its rightful place
                }
            }
        }
    }

    // Concatenate buckets to get the sorted array
    int index = 0;
    for (int i = 0; i < MAX_RANGE; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i; // Yay! Elements are being sorted!
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];
    srand(time(NULL)); // Let's make the array cheerful with random numbers!

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_RANGE;
    }

    printf("Unsorted array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}