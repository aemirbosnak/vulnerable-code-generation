#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *arr = NULL;
    arr = (int *)malloc(10 * sizeof(int));
    arr[10] = 5;
    printf("%d", arr[10]);
    free(arr);
    return 0;
}
