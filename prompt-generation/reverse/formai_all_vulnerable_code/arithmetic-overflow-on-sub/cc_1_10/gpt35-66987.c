//FormAI DATASET v1.0 Category: Benchmarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A function to generate an array of random numbers */
void generate_array(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }
}

/* A function to print the array */
void print_array(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* A function to perform bubble sort on the array */
void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/* A function to perform selection sort on the array */
void selection_sort(int arr[], int n)
{
    int i, j, min_index, temp;
    for (i = 0; i < n-1; i++)
    {
        min_index = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main()
{
    int n, i;
    clock_t t1, t2;
    double time_taken;

    /* Get the input from the user */
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    /* Generate the array of random numbers */
    generate_array(arr, n);

    /* Print the unsorted array */
    printf("Unsorted array: ");
    print_array(arr, n);

    /* Benchmark the bubble sort function */
    t1 = clock();
    bubble_sort(arr, n);
    t2 = clock();

    /* Print the sorted array */
    printf("Sorted array (bubble sort): ");
    print_array(arr, n);

    /* Calculate the time taken by bubble sort */
    time_taken = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Time taken by bubble sort: %f seconds\n", time_taken);

    /* Generate the array of random numbers */
    generate_array(arr, n);

    /* Print the unsorted array */
    printf("Unsorted array: ");
    print_array(arr, n);

    /* Benchmark the selection sort function */
    t1 = clock();
    selection_sort(arr, n);
    t2 = clock();

    /* Print the sorted array */
    printf("Sorted array (selection sort): ");
    print_array(arr, n);

    /* Calculate the time taken by selection sort */
    time_taken = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Time taken by selection sort: %f seconds\n", time_taken);

    return 0;
}