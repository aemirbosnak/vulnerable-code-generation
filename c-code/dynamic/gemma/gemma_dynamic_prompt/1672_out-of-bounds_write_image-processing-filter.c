#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int i, j, size = 10;

    arr = (int *)malloc(size * sizeof(int));

    for(i = 0; i < size; i++)
    {
        arr[i] = 0;
    }

    // Out of bounds write vulnerability
    arr[-1] = 5;

    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}
