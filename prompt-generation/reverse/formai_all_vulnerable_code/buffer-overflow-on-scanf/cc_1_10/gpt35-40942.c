//FormAI DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int size) {
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int left, int middle, int right) {
    int i, j, k, n1 = middle - left + 1, n2 =  right - middle;
    int leftArr[n1], rightArr[n2];
    
    for(i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for(j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1+ j];
    
    i = 0;
    j = 0;
    k = left;
    while(i < n1 && j < n2) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, option;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 100 + 1; // Generate random integer between 1 to 100
    
    printf("Original array: ");
    printArray(arr, n);
    
    printf("\nChoose the sorting algorithm you want to use:\n");
    printf("1. Merge Sort\n2. Bubble Sort\n");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            mergeSort(arr, 0, n-1);
            printf("\nArray after Merge Sort: ");
            printArray(arr, n);
            break;
        case 2:
            bubbleSort(arr, n);
            printf("\nArray after Bubble Sort: ");
            printArray(arr, n);
            break;
        default:
            printf("Invalid Option.");
    }
    
    return 0;
}