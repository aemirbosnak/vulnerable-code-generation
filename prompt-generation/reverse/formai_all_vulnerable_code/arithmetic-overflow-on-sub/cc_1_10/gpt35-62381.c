//FormAI DATASET v1.0 Category: Sorting ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to shuffle the array
void shuffle(int *array, int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function to implement Bubble sort
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to implement Merge Sort
void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Function to implement Selection Sort
void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
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
    int n, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocating memory using malloc
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Shuffling the array
    shuffle(arr, n);

    printf("\n1. Bubble Sort\n2. Merge Sort\n3. Selection Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        bubbleSort(arr, n);
        printf("\nArray after sorting:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        break;

    case 2:
        mergeSort(arr, 0, n - 1);
        printf("\nArray after sorting:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        break;

    case 3:
        selectionSort(arr, n);
        printf("\nArray after sorting:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        break;

    default:
        printf("Invalid choice!");
    }

    // Freeing the dynamically allocated memory
    free(arr);
    return 0;
}