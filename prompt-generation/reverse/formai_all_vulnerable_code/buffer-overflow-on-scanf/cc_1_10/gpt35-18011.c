//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void bucketSort(int arr[], int n) 
{ 
    int i, j; 
    int count[n]; 
    for(i = 0; i < n; i++) 
        count[i] = 0; 
  
    for(i = 0; i < n; i++) 
        (count[arr[i]])++; 
  
    for(i = 0, j = 0; i < n; i++) 
        for(; count[i] > 0; (count[i])--) 
            arr[j++] = i; 
} 

int main() 
{ 
    printf("Welcome to the Bucket Sort Puzzler!\n");
    printf("You are given an unsorted array in Range [0-9].\n");
    printf("Your task is to sort the given array in ascending order using Bucket Sort algorithm. But there's a twist!\n");
    printf("You are only allowed to use the following operations:\n");
    printf("1. Increment\n");
    printf("2. Decrement\n");
    printf("3. Insert\n");
    printf("4. Delete\n");
    printf("You have to complete this task using above operations only.\n");
    printf("Let's Begin!\n\n");
    
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
  
    int arr[n];
    printf("Enter elements of array in Range [0-9]: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
  
    printf("\nUnsorted Array: ");
    printArray(arr, n);
    
    printf("\nSorting in Progress...\n");
    
    for(int i = 0; i < n; i++) 
    { 
        for(int j = 0; j < n-i-1; j++) 
        { 
            if(arr[j] > arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                printf("\nDecrementing %d from index %d\n", arr[j], j);
                arr[j]--;
                printf("Incrementing %d to index %d\n", arr[j], j+1);
                arr[j+1]++;
            }
        }
    } 
    
    printf("\nSorted Array: ");
    printArray(arr, n); 
    return 0; 
}