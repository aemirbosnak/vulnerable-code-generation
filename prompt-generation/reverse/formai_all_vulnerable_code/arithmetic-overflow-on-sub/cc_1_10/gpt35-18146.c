//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>  
#include <time.h>  
#include <stdlib.h>  
#define MAX 1000000  
 
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        int temp = arr[min_idx];  
        arr[min_idx] = arr[i];  
        arr[i] = temp;  
    }  
}  
  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
 
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
        {  
            int temp = arr[j];  
            arr[j] = arr[j+1];  
            arr[j+1] = temp;  
        }  
}  

int main()  
{
    int arr[MAX], i, n, option;  
    clock_t start, end;  

    printf("Enter the number of elements in the array (MAX = %d): ", MAX);  
    scanf("%d", &n);  
    printf("Generating %d random numbers...\n", n);  
    for(i = 0; i < n; i++)  
        arr[i] = rand() % 10000;  

    printf("Enter the option to benchmark:\n1. Selection Sort\n2. Bubble Sort\n");  
    scanf("%d", &option);  

    switch(option)  
    {  
        case 1:  
            start = clock();  
            selectionSort(arr, n);  
            end = clock();  
            printf("CPU time taken by Selection sort: %lf seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);  
            break;  
        case 2:  
            start = clock();  
            bubbleSort(arr, n);  
            end = clock();  
            printf("CPU time taken by Bubble sort: %lf seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);  
            break;  
        default:  
            printf("Wrong option selected!\n");  
            break;  
    }  
    return 0;  
}