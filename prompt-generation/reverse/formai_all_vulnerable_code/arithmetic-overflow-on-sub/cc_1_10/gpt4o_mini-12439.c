//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void visualize(int arr[], int size) {
    printf("Current state of the array: ");
    printArray(arr, size);
    printf("----------------------------\n");
}

int main() {
    int choice;
    int size;

    printf("Welcome to the Merge Sort Visualizer!\n");
    printf("1. Enter your own array\n");
    printf("2. Use a predefined array\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the size of the array: ");
        scanf("%d", &size);
        int *arr = (int *)malloc(size * sizeof(int));

        printf("Enter the elements of the array:\n");
        for (int i = 0; i < size; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr[i]);
        }

        printf("You entered:\n");
        visualize(arr, size);
        mergeSort(arr, 0, size - 1);
        printf("Sorted array:\n");
        printArray(arr, size);
        
        free(arr);
    } else if (choice == 2) {
        int arr[] = {38, 27, 43, 3, 9, 82, 10};
        size = sizeof(arr) / sizeof(arr[0]);
        
        printf("Predefined array:\n");
        visualize(arr, size);
        mergeSort(arr, 0, size - 1);
        printf("Sorted array:\n");
        printArray(arr, size);
    } else {
        printf("Invalid choice! Please restart the program and choose 1 or 2.\n");
    }

    return 0;
}