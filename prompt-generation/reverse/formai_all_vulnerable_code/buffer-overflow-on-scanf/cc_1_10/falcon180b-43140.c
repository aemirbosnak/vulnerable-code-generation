//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 10000

int main() {
    int arr[MAX_SIZE];
    int n, i, j;
    int sum = 0;
    int count = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum of array elements: %d\n", sum);

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }

    printf("Number of even elements in the array: %d\n", count);

    return 0;
}