//FormAI DATASET v1.0 Category: Sorting ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n){
    int temp;

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n){
    int temp, min_index;

    for(int i=0; i<n-1; i++){
        min_index = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void insertion_sort(int arr[], int n){
    int key, j;

    for(int i=1; i<n; i++){
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));

    printf("Unsorted array:\n");
    for(int i=0; i<n; i++){
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Sorted array using Bubble Sort:\n");
    bubble_sort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Sorted array using Selection Sort:\n");
    selection_sort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Sorted array using Insertion Sort:\n");
    insertion_sort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}