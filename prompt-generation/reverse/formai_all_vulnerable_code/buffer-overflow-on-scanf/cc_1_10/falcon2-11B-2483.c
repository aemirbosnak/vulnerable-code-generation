//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k;
    int max_element, min_element;
    int *arr, *temp, *buckets[100];
    int *temp_arr;
    srand(time(NULL));

    // Take input for number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));

    // Take input for elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    max_element = arr[0];
    min_element = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        if (arr[i] < min_element) {
            min_element = arr[i];
        }
    }
    for (i = 0; i < n; i++) {
        if (arr[i] == max_element) {
            buckets[i] = arr[i];
        } else if (arr[i] == min_element) {
            buckets[i] = arr[i];
        } else {
            buckets[i] = arr[i];
        }
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", buckets[i]);
    }
    printf("\n");

    return 0;
}