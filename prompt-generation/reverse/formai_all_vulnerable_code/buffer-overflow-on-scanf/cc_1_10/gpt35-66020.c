//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void bubble_sort(int arr[], int n){
    int i, j, temp;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
   }
}

void quick_sort(int arr[], int left, int right){
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
 
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
              i++;
        while (arr[j] > pivot)
              j--;
        if (i <= j) {
              tmp = arr[i];
              arr[i] = arr[j];
              arr[j] = tmp;
              i++;
              j--;
        }
    };
 
    /* recursion */
    if (left < j)
        quick_sort(arr, left, j);
    if (i < right)
        quick_sort(arr, i, right);
}

int main(){

    int n, i, arr[MAX];
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Generating random unsorted array of size %d.\n", n);
    srand(time(NULL)); 
    for(i = 0; i < n; i++){
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }

    printf("\nSorting the array using bubble sort.\n");
    bubble_sort(arr, n);

    printf("The sorted array using bubble sort is:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\nSorting the array using quick sort.\n");
    quick_sort(arr, 0, n-1);

    printf("The sorted array using quick sort is:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}