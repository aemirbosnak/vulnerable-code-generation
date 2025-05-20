//FormAI DATASET v1.0 Category: Sorting ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void selectionSort(int arr[], int n) {
    int i, j, pos, temp;
    for(i = 0; i < n-1; i++) {
        pos = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[pos]) {
                pos = j;    
            }
        }
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, j, temp;
    for(i = 1; i < n; i++) {
        temp = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
    int arr[MAX_SIZE], n, i, choice;
    
    printf("Enter the number of elements to sort (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    
    printf("Enter the elements to sort: \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Choose a sorting algorithm:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Bubble Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            selectionSort(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            break;
        case 3:
            bubbleSort(arr, n);
            break;
        default:
            printf("Invalid choice!\n");
            exit(EXIT_FAILURE);
    }
    
    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}