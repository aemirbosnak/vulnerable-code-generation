#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *arr = NULL;
    int i = 0;

    arr = (int *)malloc(10 * sizeof(int));
    if (arr == NULL)
    {
        printf("Error allocating memory");
        return 1;
    }

    for (i = 0; i < 10; i++)
    {
        arr[i] = i;
    }

    free(arr);
    return 0;
}
