#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int i, j, k, l, m, n;

    n = 1000000;
    arr = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    l = 2000000;
    arr[l] = 10;

    printf("The value of arr[%d] is: %d", l, arr[l]);

    free(arr);

    return 0;
}
