//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000000 // size of the array, increase it to test larger values

int main()
{
    int i, j, temp;
    clock_t start, end;
    double cpu_time_used;
    int arr[SIZE];
    printf("Enter %d integers: ", SIZE);
    for (i = 0; i < SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Start the timer
    start = clock();

    // Bubble sort logic
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // End the timer
    end = clock();

    // Calculate the elapsed time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted list in ascending order:\n");

    // Print the sorted list
    for (i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    printf("\n\nThe program took %f seconds to execute.\n", cpu_time_used);

    return 0;
}