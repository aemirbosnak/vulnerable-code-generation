#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int size = 0;

    // Allocate memory for the array
    arr = (int *)malloc(size * sizeof(int));

    // Write out of bounds
    arr[-1] = 10;

    // Free the memory
    free(arr);

    return 0;
}
