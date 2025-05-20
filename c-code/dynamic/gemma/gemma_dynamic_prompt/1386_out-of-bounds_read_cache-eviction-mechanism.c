#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0, j = 0, k = 0;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Out-of-bounds read
    i = 10;
    j = arr[i];
    printf("Value at index %d: %d\n", i, j);

    return 0;
}
