//FormAI DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 50

// Function to swap two elements in an array
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble sort on a given array
void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to display an array
void display(int arr[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[MAX_LENGTH];
    int n, i;
    
    // Reading input from user
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    if (n > MAX_LENGTH) {
        printf("Error: maximum limit exceeded for elements to be sorted.");
        return 0;
    }
    printf("Enter the elements to be sorted: ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    // Displaying the unsorted array
    printf("Unsorted array: ");
    display(arr, n);
    
    // Sorting the array
    bubbleSort(arr, n);
    
    // Displaying the sorted array
    printf("Sorted array: ");
    display(arr, n);
    
    return 0;
}