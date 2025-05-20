//FormAI DATASET v1.0 Category: Sorting ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *arr, int n){
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

void insertionsort(int *arr, int n){
    int i, j, temp;
    for(i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void selectionsort(int *arr, int n){
    int i, j, k, temp;
    for(i = 0; i < n-1; i++) {
        k = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[k]) {
                k = j;
            }
        }
        temp = arr[k];
        arr[k] = arr[i];
        arr[i] = temp;
    }
}

void printarr(int *arr, int n){
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n, i, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose a sorting algorithm:\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            bubblesort(arr, n);
            break;
        case 2:
            insertionsort(arr, n);
            break;
        case 3:
            selectionsort(arr, n);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    printf("Sorted Array: ");
    printarr(arr, n);

    free(arr);

    return 0;
}