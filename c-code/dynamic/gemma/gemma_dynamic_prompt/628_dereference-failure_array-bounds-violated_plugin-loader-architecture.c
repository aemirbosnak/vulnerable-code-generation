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

    // Array bounds violation
    arr[10] = 5;

    printf("Value of arr[10]: %d", arr[10]);

    free(arr);

    return 0;
}
