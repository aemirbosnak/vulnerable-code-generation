//FormAI DATASET v1.0 Category: Sorting ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void randomize(int arr[], int n) 
{ 
    srand(time(NULL)); 
    for (int i = n - 1; i > 0; i--)  
    { 
        int j = rand() % (i + 1);  
        swap(&arr[i], &arr[j]); 
    } 
} 

void sortArray(int arr[], int n) 
{ 
    int i, j; 

    for (i = 0; i < n-1; i++)       
    { 
        for (j = 0; j < n-i-1; j++)  
        { 
            if (arr[j] > arr[j+1]) 
            {
                swap(&arr[j], &arr[j+1]); 
            }
        } 
    } 
} 

int main() 
{ 
    int arr[100]; 
    int n, i; 

    printf("Enter the size of the array: \n"); 
    scanf("%d", &n); 

    printf("Enter the elements of the array: \n"); 
    for(i=0; i<n; i++) 
    {
        scanf("%d", &arr[i]); 
    }

    printf("Original Array: \n"); 
    for(i=0; i<n; i++) 
    {
        printf("%d ", arr[i]); 
    }

    printf("\nShuffled Array: \n"); 
    randomize(arr, n); 
    for(i=0; i<n; i++) 
    {
        printf("%d ", arr[i]); 
    }

    printf("\nSorted Array: \n"); 
    sortArray(arr, n); 
    for(i=0; i<n; i++) 
    {
        printf("%d ", arr[i]); 
    }

    return 0; 
}