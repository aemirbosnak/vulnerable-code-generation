#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    int index = 10;
    arr[index] = 40;

    printf("%d", arr[index]);

    free(arr);

    return 0;
}
