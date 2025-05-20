//FormAI DATASET v1.0 Category: Sorting ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// function prototypes
int getUserInput(int arr[]);
void bubbleSort(int arr[], int len);
void selectionSort(int arr[], int len);
void insertionSort(int arr[], int len);
void printArray(int arr[], int len);

int main()
{
    int arr[MAX_SIZE]; // declare an array to hold user input
    int len; // declare a variable to store length of array

    // get user input and store it in array
    len = getUserInput(arr);

    // print original array
    printf("Original Array: ");
    printArray(arr, len);

    // sort array using bubble sort and print sorted array
    bubbleSort(arr, len);
    printf("\nSorted Array using Bubble Sort: ");
    printArray(arr, len);

    // sort array using selection sort and print sorted array
    selectionSort(arr, len);
    printf("\nSorted Array using Selection Sort: ");
    printArray(arr, len);

    // sort array using insertion sort and print sorted array
    insertionSort(arr, len);
    printf("\nSorted Array using Insertion Sort: ");
    printArray(arr, len);

    return 0;
}

/*
 * Function to get user input and store it in an array
 */
int getUserInput(int arr[])
{
    int n, i;

    // get number of elements in array
    printf("Enter the number of elements in the array (Max: %d): ", MAX_SIZE);
    scanf("%d", &n);

    // check if number of elements is within array size limit
    if (n > MAX_SIZE)
    {
        printf("Error: Maximum number of elements allowed is %d.\n", MAX_SIZE);
        exit(1);
    }

    // get elements of array from user
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    return n; // return length of array
}

/*
 * Function to sort array using Bubble Sort
 */
void bubbleSort(int arr[], int len)
{
    int i, j, temp;

    for (i = 0; i < len-1; i++)
    {
        for (j = 0; j < len-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/*
 * Function to sort array using Selection Sort
 */
void selectionSort(int arr[], int len)
{
    int i, j, min_index, temp;

    for (i = 0; i < len-1; i++)
    {
        min_index = i;
        for (j = i+1; j < len; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        // swap arr[i] and arr[min_index]
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

/*
 * Function to sort array using Insertion Sort
 */
void insertionSort(int arr[], int len)
{
    int i, j, temp;

    for (i = 1; i < len; i++)
    {
        temp = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }
}

/*
 * Function to print the elements of an array
 */
void printArray(int arr[], int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}