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

    // Evict element at index 10 (out of bounds)
    arr[10] = 5;

    free(arr);

    return 0;
}
