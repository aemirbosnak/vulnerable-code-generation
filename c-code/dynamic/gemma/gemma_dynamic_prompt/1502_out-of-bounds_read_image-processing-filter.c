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

    arr = (int *)malloc(10 * sizeof(int));
    if (arr == NULL)
    {
        return 1;
    }

    for (i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }

    // Out-of-bounds read vulnerability
    arr[-1] = 42;

    printf("Array elements:");
    for (i = 0; i < 10; i++)
    {
        printf(" %d", arr[i]);
    }

    free(arr);
    return 0;
}
