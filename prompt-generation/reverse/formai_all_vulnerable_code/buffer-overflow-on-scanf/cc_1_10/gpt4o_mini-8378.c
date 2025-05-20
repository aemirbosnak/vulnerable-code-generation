//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define BUCKET_SIZE 10

// Structure to represent a bucket
typedef struct Bucket {
    int* arr;               // Array of elements in the bucket
    int count;             // Number of elements in the bucket
} Bucket;

// Function to create a bucket
Bucket* createBucket() {
    Bucket* bucket = (Bucket*)malloc(sizeof(Bucket));
    bucket->arr = (int*)malloc(BUCKET_SIZE * sizeof(int));
    bucket->count = 0;
    return bucket;
}

// Function to free a bucket
void freeBucket(Bucket* bucket) {
    free(bucket->arr);
    free(bucket);
}

// The mind-bending sort function that takes a delightful journey through the array
void bucketSort(int* nums, int n) {
    // Enchanting maximum value discovery
    int maxValue = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > maxValue) {
            maxValue = nums[i];
        }
    }

    // Mesmerizing bucket array creation
    int bucketCount = (maxValue / BUCKET_SIZE) + 1;
    Bucket** buckets = (Bucket**)malloc(bucketCount * sizeof(Bucket*));
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = createBucket();
    }

    // Glorious distribution of elements into buckets
    for (int i = 0; i < n; i++) {
        int index = nums[i] / BUCKET_SIZE;
        if (buckets[index]->count < BUCKET_SIZE) {
            buckets[index]->arr[buckets[index]->count++] = nums[i];
        } else {
            // Handle if a bucket overflows using reallocation (it will double the array size)
            buckets[index]->arr = (int*)realloc(buckets[index]->arr, (buckets[index]->count + 1) * sizeof(int));
            buckets[index]->arr[buckets[index]->count++] = nums[i];
        }
    }

    // The grand sorting extravaganza for each bucket
    for (int i = 0; i < bucketCount; i++) {
        if (buckets[i]->count > 0) {
            // Sorting each bucket using insertion sort
            for (int j = 1; j < buckets[i]->count; j++) {
                int key = buckets[i]->arr[j];
                int k = j - 1;
                while (k >= 0 && buckets[i]->arr[k] > key) {
                    buckets[i]->arr[k + 1] = buckets[i]->arr[k];
                    k--;
                }
                buckets[i]->arr[k + 1] = key;
            }
        }
    }

    // Exquisite gathering of all the sorted elements
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < buckets[i]->count; j++) {
            nums[index++] = buckets[i]->arr[j];
        }
        freeBucket(buckets[i]);
    }

    free(buckets);
}

// The magical realm of our main function
int main() {
    // An enchanting list of chaotic numbers
    int nums[MAX];
    int n = 0;
    
    printf("Welcome to the Bucket Sort Adventure!\n");
    printf("Enter numbers (type 'end' to finish): \n");

    // The gathering of numbers
    char input[10];
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "end") == 0) {
            break;
        }
        nums[n++] = atoi(input);
    }

    // If we have gathered at least one number
    if (n > 0) {
        printf("You entered these numbers:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", nums[i]);
        }
        printf("\nNow let us sort them...\n");

        // The transformation: Bucket Sort
        bucketSort(nums, n);

        // The grand reveal of sorted numbers
        printf("Sorted numbers:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", nums[i]);
        }
        printf("\nHow magnificent!\n");
    } else {
        printf("No numbers entered, what a mystery!\n");
    }

    return 0;
}