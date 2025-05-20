#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int idx = 10;
    int value = arr[idx];

    printf("Value at index %d: %d\n", idx, value);

    return 0;
}
