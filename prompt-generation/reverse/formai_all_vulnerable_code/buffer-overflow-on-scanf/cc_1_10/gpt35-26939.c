//FormAI DATASET v1.0 Category: Sorting ; Style: sophisticated
#include <stdio.h>

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

void insertionSort(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = temp;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Choose Sorting Algorithm:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Insertion Sort\n");
    printf("3 - Selection Sort\n");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            bubbleSort(arr, n);
            printf("Sorted array in ascending order using Bubble Sort:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            break;
        case 2:
            insertionSort(arr, n);
            printf("Sorted array in ascending order using Insertion Sort:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            break;
        case 3:
            selectionSort(arr, n);
            printf("Sorted array in ascending order using Selection Sort:\n");
            for (int i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            break;
        default:
            printf("Invalid Choice!\n");
            break;
    }
    return 0;
}