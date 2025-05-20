#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int i = 0, offset = 0;

    arr = malloc(10 * sizeof(int));

    // Out-of-bounds write vulnerability
    arr[10] = 42;

    free(arr);

    return 0;
}
