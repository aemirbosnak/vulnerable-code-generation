//FormAI DATASET v1.0 Category: Sorting ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to print the array
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

// Function to perform sorting using selection sort algorithm
void selectionSort(int arr[], int n){

    for(int i = 0; i < n; i++){
        int min_index = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main(){

    printf("Welcome to the Sorting Program!\n");

    // Getting the input from the user
    printf("Please enter the size of the array: ");
    int n;
    scanf("%d", &n);

    // Allocating memory for the array of given size
    int *arr = (int*)malloc(sizeof(int)*n);

    printf("Please enter the elements of the array:\n");
    // Getting the array elements from the user
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("The initial array: ");
    printArray(arr, n);

    printf("\nSorting the array using Selection Sort...\n");
    selectionSort(arr, n);

    printf("The sorted array: ");
    printArray(arr, n);

    printf("\nThank you for using the Sorting Program!");

    // Freeing the memory allocated to the array
    free(arr);
    return 0;
}