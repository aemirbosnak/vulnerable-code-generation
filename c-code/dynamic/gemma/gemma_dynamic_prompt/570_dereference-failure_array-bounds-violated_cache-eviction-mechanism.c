#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, size = 10, data[size], invalid_index = -1;

    for(i = 0; i < size; i++)
    {
        data[i] = i + 1;
    }

    invalid_index = size - 1;

    // Attempt to dereference an array element beyond bounds
    j = data[invalid_index];

    printf("Value at invalid index: %d", j);

    return 0;
}
