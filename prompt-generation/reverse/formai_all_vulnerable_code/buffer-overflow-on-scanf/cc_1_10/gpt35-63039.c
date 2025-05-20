//FormAI DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>

/* Define the maximum size of the array */
#define MAX_SIZE 10

/* Function prototype for bubble sort */
void bubbleSort(int arr[], int n);

int main()
{
    int arr[MAX_SIZE];
    int i, j, n;

    /* Ask user to input the number of elements they want to sort */
    printf("Enter number of elements to sort: ");
    scanf("%d", &n);

    /* Ask user to input the elements of the array */
    for(i=0; i<n; i++)
    {
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    /* Display the original array */
    printf("Original array: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    /* Sort the array using bubble sort */
    bubbleSort(arr, n);

    /* Display the sorted array */
    printf("Sorted array: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

/* Function definition for bubble sort */
void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            /* Swap the elements if the previous element is larger than the current element */
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}