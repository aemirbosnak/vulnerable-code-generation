#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
    void *pool = NULL;
    int size = 0;

    // Allocate memory for the pool
    pool = malloc(1024);
    if (pool == NULL)
    {
        return 1;
    }

    // Free the memory that was not allocated
    free(pool);

    return 0;
}
