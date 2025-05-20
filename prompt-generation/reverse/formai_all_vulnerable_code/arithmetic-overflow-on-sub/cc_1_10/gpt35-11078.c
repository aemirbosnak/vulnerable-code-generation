//FormAI DATASET v1.0 Category: Sorting ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the array
void displayArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                // Swapping the elements in the array
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++)
    {
        minIndex = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swapping the elements in the array
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[1000], n, i, ch;

    // Getting the user input for number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Filling the array randomly using rand() function
    srand(time(0));
    for (i = 0; i < n; i++)
        arr[i] = rand() % 1000;

    // Displaying the original array
    printf("\nOriginal Array:\n");
    displayArray(arr, n);

    printf("\n1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");

    // Getting the user input for type of sorting algorithm to be executed
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
        case 1:
            bubbleSort(arr, n);
            printf("\nSorted Array:\n");
            displayArray(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            printf("\nSorted Array:\n");
            displayArray(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            printf("\nSorted Array:\n");
            displayArray(arr, n);
            break;
        default:
            printf("\nInvalid Choice!\n");
            break;
    }

    return 0;
}