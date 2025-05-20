#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int i = 0;

    // Allocate memory for the array
    arr = (int *)malloc(10 * sizeof(int));

    // Initialize the array
    for (i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }

    // Access an element beyond the bounds of the array
    arr[10] = 20;

    // Print the contents of the array
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    // Free the memory allocated for the array
    free(arr);

    return 0;
}
