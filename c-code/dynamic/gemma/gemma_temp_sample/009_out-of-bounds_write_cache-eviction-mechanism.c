#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    arr[10] = 10; // Out of bounds write

    free(arr);

    return 0;
}
