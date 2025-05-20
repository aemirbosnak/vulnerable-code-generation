//FormAI DATASET v1.0 Category: Sorting ; Style: statistical
/* Introducing a Statistical Sorting Program in C */

/* Importing the required header files */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Defining the maximum array size */
#define MAX_SIZE 100

/* Function to generate random numbers */
void generateRandomNumbers(int arr[], int n)
{
    srand(time(NULL));  // Seed for random function
    for(int i=0; i<n; i++)
    {
        arr[i] = rand() % 1000;  // Generate random number between 0 and 999
    }
}

/* Function to print array */
void printArray(int arr[], int n)
{
    printf("{ ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

/* Function to swap two numbers */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to perform Bubble Sort on the array */
void bubbleSort(int arr[], int n)
{
    clock_t start = clock();   // Start time of algorithm
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])   // Swap if numbers are not in order
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    printf("Bubble Sort Time: %fs\n", (double)(clock()-start)/CLOCKS_PER_SEC);   // Print time taken by algorithm
}

/* Function to perform Insertion Sort on the array */
void insertionSort(int arr[], int n)
{
    clock_t start = clock();   // Start time of algorithm
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)   // Shift numbers to right to make space for key
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;   // Place key in correct position
    }
    printf("Insertion Sort Time: %fs\n", (double)(clock()-start)/CLOCKS_PER_SEC);   // Print time taken by algorithm
}

/* Function to perform Selection Sort on the array */
void selectionSort(int arr[], int n)
{
    clock_t start = clock();   // Start time of algorithm
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min_index])   // Find minimum element in unsorted array
            {
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);   // Swap minimum element with first element of unsorted array
    }
    printf("Selection Sort Time: %fs\n", (double)(clock()-start)/CLOCKS_PER_SEC);   // Print time taken by algorithm
}

/* Main function to execute the program */
int main()
{
    /* Initialize variables */
    int n, arr[MAX_SIZE];

    /* Take input from user */
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    /* Generate and print random array */
    generateRandomNumbers(arr, n);
    printf("\nRandom Array: ");
    printArray(arr, n);

    /* Sort array using Bubble Sort */
    int arr_bubble[MAX_SIZE];
    for(int i=0; i<n; i++)
    {
        arr_bubble[i] = arr[i];
    }
    printf("\nBubble Sorted Array: ");
    bubbleSort(arr_bubble, n);
    printArray(arr_bubble, n);

    /* Sort array using Insertion Sort */
    int arr_insertion[MAX_SIZE];
    for(int i=0; i<n; i++)
    {
        arr_insertion[i] = arr[i];
    }
    printf("\nInsertion Sorted Array: ");
    insertionSort(arr_insertion, n);
    printArray(arr_insertion, n);

    /* Sort array using Selection Sort */
    int arr_selection[MAX_SIZE];
    for(int i=0; i<n; i++)
    {
        arr_selection[i] = arr[i];
    }
    printf("\nSelection Sorted Array: ");
    selectionSort(arr_selection, n);
    printArray(arr_selection, n);

    return 0;
}