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

    // Out of bounds read vulnerability
    arr[-1] = 5;

    printf("%d", arr[-1]);

    free(arr);

    return 0;
}
