//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

// Function to generate random numbers between 0 and max_value
int generate_random_number(int max_value) {
    return rand() % max_value;
}

// Function to print the elements of an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucket_sort(int arr[], int size) {
    int max_value = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    int bucket_size = max_value / size;
    int *buckets[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = (int *) malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / bucket_size;
        int j = 0;
        while (j < size && buckets[bucket_index][j]!= 0) {
            j++;
        }
        buckets[bucket_index][j] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < size; j++) {
            if (buckets[i][j]!= 0) {
                arr[index] = buckets[i][j];
                index++;
            }
        }
    }
}

// Function to generate an array of random numbers
void generate_array(int arr[], int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = generate_random_number(MAX_VALUE);
    }
}

// Main function
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generate_array(arr, size);

    printf("Original array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}