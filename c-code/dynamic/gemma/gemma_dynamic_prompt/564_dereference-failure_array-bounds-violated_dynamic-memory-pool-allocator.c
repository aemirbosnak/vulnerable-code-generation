#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    arr[10] = 5; // Array bounds violation
    free(arr);

    return 0;
}
