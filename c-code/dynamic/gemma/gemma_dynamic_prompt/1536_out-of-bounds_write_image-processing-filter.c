#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    arr = (int *)malloc(10 * sizeof(int));

    // Out-of-bounds write vulnerability
    arr[-1] = 5;

    free(arr);
    return 0;
}
