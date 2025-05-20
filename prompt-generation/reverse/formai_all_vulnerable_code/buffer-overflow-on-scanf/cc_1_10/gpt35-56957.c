//FormAI DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[], int n){
    int key, j;
    for(int i=1; i<n; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n){
    int min_idx;
    for(int i=0; i<n-1; i++){
        min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            break;
        case 3:
            selectionSort(arr, n);
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }
    
    printf("Sorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}