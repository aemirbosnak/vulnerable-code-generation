//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This function allocates memory dynamically for the buckets */
int** allocate_buckets(int num_buckets, int bucket_capacity) {
    int **buckets = malloc(num_buckets * sizeof(int*));
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = malloc(bucket_capacity * sizeof(int));
    }
    return buckets;
}

/* This function initializes all the elements of the buckets to -1 */
void initialize_buckets(int **buckets, int num_buckets, int bucket_capacity) {
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_capacity; j++) {
            buckets[i][j] = -1;
        }
    }
}

/* This function prints the elements in each of the buckets */
void print_buckets(int **buckets, int num_buckets, int bucket_capacity) {
    for (int i = 0; i < num_buckets; i++) {
        printf("Bucket %d: ", i);
        for (int j = 0; j < bucket_capacity; j++) {
            if (buckets[i][j] != -1) {
                printf("%d ", buckets[i][j]);
            }
        }
        printf("\n");
    }
}

/* This function generates a random array of integers of given size */
int* generate_array(int size) {
    int *arr = malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

/* This function prints the given array */
void print_array(int *arr, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* This function finds the maximum element in the array */
int find_max(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/* This function performs the bucket sort */
void bucket_sort(int *arr, int size, int num_buckets) {
    int max = find_max(arr, size);
    int bucket_capacity = (max / num_buckets) + 1;
    int **buckets = allocate_buckets(num_buckets, bucket_capacity);
    initialize_buckets(buckets, num_buckets, bucket_capacity);
    /* Distribute the elements of the array into the buckets */
    for (int i = 0; i < size; i++) {
        int j = arr[i] / bucket_capacity;
        int k = 0;
        while (buckets[j][k] != -1) {
            k++;
        }
        buckets[j][k] = arr[i];
    }
    /* Sort each bucket individually */
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_capacity - 1; j++) {
            for (int k = 0; k < bucket_capacity - j - 1; k++) {
                if (buckets[i][k] > buckets[i][k+1]) {
                    int temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k+1];
                    buckets[i][k+1] = temp;
                }
            }
        }
    }
    /* Concatenate the sorted buckets to obtain the final sorted array */
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_capacity; j++) {
            if (buckets[i][j] != -1) {
                arr[index] = buckets[i][j];
                index++;
            }
        }
    }
}

int main() {
    int size, num_buckets;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the number of buckets: ");
    scanf("%d", &num_buckets);
    int *arr = generate_array(size);
    print_array(arr, size);
    bucket_sort(arr, size, num_buckets);
    print_array(arr, size);
    return 0;
}