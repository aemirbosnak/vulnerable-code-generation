#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    arr = (int *)malloc(5 * sizeof(int));

    arr[4] = 10; // Array bounds violation

    free(arr);
    return 0;
}
