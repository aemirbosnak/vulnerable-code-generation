//FormAI DATASET v1.0 Category: Sorting ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Function to print the elements in an array*/
void printArray(int arr[], int n){
    int i;
    printf("\nCurrent order of elements in array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*Paranoid function to check if the array is actually sorted*/
void checkSorted(int arr[], int n){
    int i;
    for (i = 0; i < n-1; i++){
        if (arr[i] > arr[i+1]){
            printf("\nALERT: Array is not sorted. Aborting program!\n");
            exit(0);
        }
    }
    printf("\nSUCCESS: Array is sorted.\n");
}

/*Function to swap two values*/
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*Randomized quicksort implementation*/
void quicksort(int arr[], int low, int high){
    if (low < high){
        int pivot_index = low + rand() % (high - low + 1); //Random pivot index
        int pivot = arr[pivot_index];
        int i = low, j;
        swap(&arr[pivot_index], &arr[high]); //Move pivot to end of subarray

        for (j = low; j < high; j++){
            if (arr[j] <= pivot){
                swap(&arr[i], &arr[j]);
                i++;
            }
        }
        swap(&arr[i], &arr[high]); //Move pivot to correct position
        quicksort(arr, low, i-1);
        quicksort(arr, i+1, high);
    }
}

/*Main function*/
int main(){
    int arr[10], i;
    printf("Enter 10 integers to be sorted: ");
    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);
    printArray(arr, 10);

    srand(time(NULL)); //Seed random number generator
    quicksort(arr, 0, 9);

    printArray(arr, 10);
    checkSorted(arr, 10);
    return 0;
}