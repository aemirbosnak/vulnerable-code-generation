//Falcon-180B DATASET v1.0 Category: Sorting ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, i, j, temp;
    char choice;
    srand(time(NULL)); // seed the random number generator

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100; // generate random numbers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    do {
        printf("Enter your choice of sorting algorithm:\n");
        printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                for (i = 0; i < n-1; i++) {
                    for (j = 0; j < n-i-1; j++) {
                        if (arr[j] > arr[j+1]) {
                            temp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = temp;
                        }
                    }
                }
                break;
            case '2':
                for (i = 0; i < n-1; i++) {
                    int min_idx = i;
                    for (j = i+1; j < n; j++) {
                        if (arr[j] < arr[min_idx]) {
                            min_idx = j;
                        }
                    }
                    temp = arr[i];
                    arr[i] = arr[min_idx];
                    arr[min_idx] = temp;
                }
                break;
            case '3':
                for (i = 1; i < n; i++) {
                    int key = arr[i];
                    int j = i-1;
                    while (j >= 0 && arr[j] > key) {
                        arr[j+1] = arr[j];
                        j--;
                    }
                    arr[j+1] = key;
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '2'); // keep prompting until user selects Selection Sort

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}