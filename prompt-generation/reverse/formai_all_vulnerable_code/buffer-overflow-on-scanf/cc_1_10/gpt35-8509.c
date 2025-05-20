//FormAI DATASET v1.0 Category: Sorting ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int* arr, int n) {
    int i, j, temp;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int* arr, int n) {
    int i, j, min_idx, temp;

    for(i = 0; i < n-1; i++) {
        min_idx = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }

        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int* arr, int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void quickSort(int* arr, int low, int high) {
    if(low < high) {
        int pivot = arr[low], i = low, j = high;
        while(i < j) {
            while(arr[i] <= pivot && i <= high)
                i++;
            while(arr[j] > pivot && j >= low)
                j--;
            if(i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[j];
        arr[j] = arr[low];
        arr[low] = temp;

        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }
}

void merge(int* arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[l+i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m+1+j];

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr, int l, int r) {
    if(l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n, i, option;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));
    printf("Generating random array...\n");
    for(i = 0; i < n; i++)
        arr[i] = rand();

    printf("\nWhat sorting algorithm would you like to use?\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");
    printf("Enter option number: ");
    scanf("%d", &option);

    printf("\nBefore sorting:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    switch(option) {
        case(1): {
            printf("\nUsing Bubble Sort...\n");
            bubbleSort(arr, n);
            break;
        }
        case(2): {
            printf("\nUsing Selection Sort...\n");
            selectionSort(arr, n);
            break;
        }
        case(3): {
            printf("\nUsing Insertion Sort...\n");
            insertionSort(arr, n);
            break;
        }
        case(4): {
            printf("\nUsing Quick Sort...\n");
            quickSort(arr, 0, n-1);
            break;
        }
        case(5): {
            printf("\nUsing Merge Sort...\n");
            mergeSort(arr, 0, n-1);
            break;
        }
        default: {
            printf("\nInvalid option.\n");
            return 0;
        }
    }

    printf("\nAfter sorting:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}