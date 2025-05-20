//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100
#define BUCKET_SIZE 10

// Structure to represent a single bucket
typedef struct Bucket {
    float *array; // Pointer to the array that will hold bucket values
    int count;    // Number of elements in the bucket
} Bucket;

// Function to create and initialize a bucket
Bucket createBucket() {
    Bucket bucket;
    bucket.array = (float *)malloc(BUCKET_SIZE * sizeof(float)); // Allocate space
    bucket.count = 0; // Initialize count
    return bucket;
}

// Function to insert a number into a bucket
void insertIntoBucket(Bucket *bucket, float value) {
    if (bucket->count < BUCKET_SIZE) {
        bucket->array[bucket->count] = value;
        bucket->count++;
    }
}

// Function to sort a single bucket using insertion sort
void sortBucket(Bucket *bucket) {
    int i, j;
    for (i = 1; i < bucket->count; i++) {
        float temp = bucket->array[i];
        j = i - 1;
        while (j >= 0 && bucket->array[j] > temp) {
            bucket->array[j + 1] = bucket->array[j];
            j--;
        }
        bucket->array[j + 1] = temp;
    }
}

// Function to perform bucket sort
void bucketSort(float *array, int n) {
    // Create an array of buckets
    Bucket *buckets = (Bucket *)malloc(n * sizeof(Bucket));
    for (int i = 0; i < n; i++) {
        buckets[i] = createBucket();
    }

    // Distribute the input array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(array[i] * n); // Map number to bucket index
        insertIntoBucket(&buckets[bucketIndex], array[i]); // Insert into the bucket
    }

    // Sort each individual bucket
    for (int i = 0; i < n; i++) {
        sortBucket(&buckets[i]);
    }

    // Merge the sorted buckets back to the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            array[index++] = buckets[i].array[j];
        }
    }

    // Free allocated memory for each bucket
    for (int i = 0; i < n; i++) {
        free(buckets[i].array);
    }
    free(buckets);
}

// Main function to execute the program
int main() {
    float array[MAX_NUMBERS];
    int n;

    // Input: Read numbers from the user
    printf("Enter the number of elements to sort (max %d): ", MAX_NUMBERS);
    scanf("%d", &n);
    if (n > MAX_NUMBERS) {
        printf("Error: Maximum number of elements is %d.\n", MAX_NUMBERS);
        return 1;
    }
    printf("Enter %d floating point numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    // Perform Bucket Sort
    bucketSort(array, n);
    
    // Output: Print sorted numbers
    printf("Sorted numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");

    return 0;
}