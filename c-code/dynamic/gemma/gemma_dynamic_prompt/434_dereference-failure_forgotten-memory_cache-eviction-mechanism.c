#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *ptr = NULL;
    ptr = (int *)malloc(10 * sizeof(int));

    // Evict item from cache by dereferencing a null pointer
    *ptr = 5;

    free(ptr);

    return 0;
}
