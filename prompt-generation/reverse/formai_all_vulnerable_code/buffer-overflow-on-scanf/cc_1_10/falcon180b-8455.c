//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

/* Function to generate a random number between 0 and MAX-1 */
int rand_num(void)
{
    return rand() % MAX;
}

/* Function to print an array */
void print_array(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

/* Function to merge two sorted arrays */
void merge(int arr[], int left[], int left_size, int right[], int right_size)
{
    int i, j, k;

    i = j = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left_size) {
        arr[k++] = left[i++];
    }

    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

/* Function to perform merge sort recursively */
void merge_sort(int arr[], int n)
{
    int mid;

    if (n <= 1) {
        return;
    }

    mid = n / 2;

    merge_sort(arr, mid);
    merge_sort(arr + mid, n - mid);

    merge(arr, arr, mid, arr + mid, n - mid);
}

/* Function to generate a random array of size n */
void generate_array(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
        arr[i] = rand_num();
    }
}

int main()
{
    int n, arr[MAX], i;

    srand(time(NULL));

    /* Get the size of the array */
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    /* Generate the array */
    generate_array(arr, n);

    /* Print the original array */
    printf("Original array:\n");
    print_array(arr, n);

    /* Sort the array */
    merge_sort(arr, n);

    /* Print the sorted array */
    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}