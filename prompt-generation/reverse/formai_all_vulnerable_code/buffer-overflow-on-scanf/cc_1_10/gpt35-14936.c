//FormAI DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubble_sort(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int i, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // calculate the time taken by selection sort algorithm
    clock_t t;
    t = clock();
    selection_sort(arr, n);
    t = clock() - t;
    double time_taken_sel = ((double)t)/CLOCKS_PER_SEC;

    printf("Time taken by selection sort: %f seconds\n", time_taken_sel);

    // calculate the time taken by bubble sort algorithm
    t = clock();
    bubble_sort(arr, n);
    t = clock() - t;
    double time_taken_bub = ((double)t)/CLOCKS_PER_SEC;

    printf("Time taken by bubble sort: %f seconds\n", time_taken_bub);

    return 0;
}