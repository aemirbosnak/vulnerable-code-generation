#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main()
{
    int *arr = NULL;
    arr = malloc(10 * sizeof(int));
    free(arr);
    arr = NULL;
    arr = malloc(10 * sizeof(int));
    free(arr);
    return 0;
}
