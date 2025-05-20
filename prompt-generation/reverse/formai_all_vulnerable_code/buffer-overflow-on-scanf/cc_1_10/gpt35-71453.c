//FormAI DATASET v1.0 Category: Sorting ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void displayArray(int arr[], int n);

int main()
{
    int choice, n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nSorting Algorithms Menu\n");
        printf("\n1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                bubbleSort(arr, n);
                printf("\nSorted Array using Bubble Sort: ");
                displayArray(arr, n);
                break;

            case 2:
                selectionSort(arr, n);
                printf("\nSorted Array using Selection Sort: ");
                displayArray(arr, n);
                break;

            case 3:
                insertionSort(arr, n);
                printf("\nSorted Array using Insertion Sort: ");
                displayArray(arr, n);
                break;

            case 4:
                quickSort(arr, 0, n-1);
                printf("\nSorted Array using Quick Sort: ");
                displayArray(arr, n);
                break;

            case 5:
                mergeSort(arr, 0, n-1);
                printf("\nSorted Array using Merge Sort: ");
                displayArray(arr, n);
                break;

            case 6:
                printf("Exiting program...");
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid choice.");
        }
    } while (choice != 6);

    return 0;
}

/*
    Bubble Sort function
*/
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

/*
    Selection Sort function
*/
void selectionSort(int arr[], int n)
{
    int i, j, min_index, temp;
    for (i = 0; i < n-1; i++)
    {
        min_index = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

/*
    Insertion Sort function
*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*
    Quick Sort function
*/
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*
    Partition function for Quick Sort
*/
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

/*
    Merge Sort function
*/
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/*
    Merge function for Merge Sort
*/
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*
    Display Array function
*/
void displayArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}