#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

int main()
{
    char **pool = NULL;
    int size = 0, i;

    // Allocate memory for the pool
    pool = malloc(sizeof(char *) * 10);
    if (pool == NULL)
    {
        return 1;
    }

    // Allocate memory for each element in the pool
    for (i = 0; i < 10; i++)
    {
        pool[i] = malloc(1024);
        if (pool[i] == NULL)
        {
            return 1;
        }
    }

    // Overflow the pool by allocating more memory than the pool size
    pool[size++][0] = 'a';

    // Free the memory
    for (i = 0; i < 10; i++)
    {
        free(pool[i]);
    }
    free(pool);

    return 0;
}
