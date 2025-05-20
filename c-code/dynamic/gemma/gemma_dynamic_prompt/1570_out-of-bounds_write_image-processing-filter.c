#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *arr = NULL;
    int i = 0;

    arr = malloc(10);

    // Out of bounds write vulnerability
    arr[10] = 5;

    free(arr);

    return 0;
}
