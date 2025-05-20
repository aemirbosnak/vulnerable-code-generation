//FormAI DATASET v1.0 Category: Sorting ; Style: sophisticated
/* This program sorts a given array of integers in ascending order using the bubble sort algorithm */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to display the array */
void display(int arr[], int n) {
    printf("The array after sorting is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to perform bubble sort */
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/* Main function */
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    /* Generating random integers and storing them in an array */
    int arr[n];
    srand(time(0));
    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }

    /* Displaying the unsorted array */
    printf("The array before sorting is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* Sorting the array using bubble sort */
    bubbleSort(arr, n);

    /* Displaying the sorted array */
    display(arr, n);
    
    return 0;
}