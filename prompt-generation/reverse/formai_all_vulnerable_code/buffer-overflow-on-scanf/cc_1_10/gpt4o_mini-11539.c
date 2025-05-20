//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

// Function to create a bucket
typedef struct Bucket {
    int *arr;
    int count;
} Bucket;

// Function to initialize a bucket
Bucket create_bucket() {
    Bucket b;
    b.arr = (int*)malloc(100 * sizeof(int));
    b.count = 0;
    return b;
}

// Function to free the bucket memory
void free_bucket(Bucket *b) {
    free(b->arr);
    b->arr = NULL;
}

// Function to sort individual buckets using Insertion Sort
void insertion_sort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Bucket Sort
void bucket_sort(float arr[], int n) {
    // Create buckets
    Bucket buckets[BUCKET_COUNT];
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = create_bucket();
    }

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (int)(BUCKET_COUNT * arr[i]);
        if (bucket_index >= BUCKET_COUNT) bucket_index = BUCKET_COUNT - 1;
        buckets[bucket_index].arr[buckets[bucket_index].count++] = arr[i];
    }

    // Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (buckets[i].count > 0) {
            insertion_sort(buckets[i].arr, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                arr[index++] = buckets[i].arr[j];
            }
        }
        free_bucket(&buckets[i]);
    }
}

// Function to print the sorted array
void print_array(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

// Main program start
int main() {
    int n;
    printf("Welcome to the Curiously Clever Bucket Sort Program!\n");
    printf("How many floating-point numbers do you want to sort? ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    float *arr = (float*)malloc(n * sizeof(float));
    printf("Enter %d floating-point numbers:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Your original array is:\n");
    print_array(arr, n);

    // Perform Bucket Sort
    bucket_sort(arr, n);

    // Display the sorted array
    printf("Sorted array using Bucket Sort:\n");
    print_array(arr, n);

    // Free the allocated memory for the array
    free(arr);
    printf("Thank you for sorting with us! Happy coding!\n");

    return 0;
}