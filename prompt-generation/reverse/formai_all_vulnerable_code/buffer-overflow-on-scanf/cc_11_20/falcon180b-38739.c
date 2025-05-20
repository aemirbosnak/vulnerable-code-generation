//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int n, i, j, k, count[MAX_SIZE];

    // Prompt user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Prompt user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize the count array to zero
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Count the frequency of each element in the array
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Create the buckets
    for (i = 0; i < n; i++) {
        if (count[i] > 0) {
            for (j = i; j < n; j++) {
                if (arr[j] == i) {
                    k = count[arr[j]] - 1;
                    count[arr[j]] = 0;
                    count[i]++;
                    arr[j] = i;
                    break;
                }
            }
        }
    }

    // Sort the array using bucket sort
    for (i = 0; i < n; i++) {
        if (count[i] > 0) {
            for (j = i; j < n; j++) {
                if (arr[j] == i) {
                    k = count[arr[j]] - 1;
                    count[arr[j]] = 0;
                    count[i]++;
                    arr[j] = i;
                    break;
                }
            }
        }
    }

    // Print the sorted array
    printf("Sorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}