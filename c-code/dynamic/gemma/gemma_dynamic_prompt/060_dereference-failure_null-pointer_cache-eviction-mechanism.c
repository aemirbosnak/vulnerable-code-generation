#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *arr = NULL;
    arr = (int *)malloc(10 * sizeof(int));

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    printf("%d", arr[0]);
    printf("%d", arr[1]);
    printf("%d", arr[2]);
    printf("%d", arr[3]);
    printf("%d", arr[4]);

    free(arr);

    return 0;
}
