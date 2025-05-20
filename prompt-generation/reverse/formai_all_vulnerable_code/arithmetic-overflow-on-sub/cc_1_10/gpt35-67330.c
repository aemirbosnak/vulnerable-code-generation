//FormAI DATASET v1.0 Category: Sorting ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    printf("Welcome to the bubble sort example program!\n");
    printf("This program will generate a random array of integers and sort them using the bubble sort algorithm.\n");
    printf("How many integers would you like the array to contain?\n");

    int n;
    scanf("%d", &n);
    int arr[n];

    srand(time(NULL)); // seed the random number generator

    printf("The random array of integers generated is: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; // generate random integer between 1 and 100
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Thank you for using our bubble sort example program!\n");

    return 0;
}