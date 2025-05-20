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
    arr[10] = 5; // Bounds violation
    printf("%d", arr[10]);
    free(arr);
    return 0;
}
