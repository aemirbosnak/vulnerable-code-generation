//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// Function to generate random integers between 0 and size-1 of an array
void genArray(int* arr, int n) 
{ 
    srand(time(NULL)); 
    for (int i=0; i<n; i++) 
    { 
        arr[i] = rand()%10; 
    } 
} 

// Function to print an array vertically
void printArrayVertical(int* arr, int n) 
{ 
    for (int i=0; i<n; i++) 
    { 
        printf("%d\t", arr[i]); 
    } 
    printf("\n"); 
} 

// Function to sort an array in ascending order
void sortArray(int* arr, int n) 
{ 
    for (int i=0; i<n-1; i++) 
    { 
        for (int j=0; j<n-i-1; j++) 
        { 
            if (arr[j] > arr[j+1]) 
            { 
                int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 
            } 
        } 
    } 
} 

// Function to print an array horizontally
void printArrayHorizontal(int* arr, int n) 
{ 
    for (int i=0; i<n; i++) 
    { 
        printf("%d", arr[i]); 
        if (i!=n-1) 
        { 
            printf("\t"); 
        } 
    } 
    printf("\n"); 
} 

// Driver Code 
int main() 
{ 
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    
    int* arr = (int*)malloc(n*sizeof(int));
    
    genArray(arr,n);
    
    printf("Randomly generated array is: \n");
    printArrayVertical(arr,n);
    
    sortArray(arr,n);
    
    printf("Sorted array is: \n");
    printArrayHorizontal(arr,n);
    
    free(arr);
    
    return 0; 
}