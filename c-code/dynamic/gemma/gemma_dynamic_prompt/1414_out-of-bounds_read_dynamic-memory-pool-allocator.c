#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
    void *pool = malloc(10 * sizeof(void *));
    pool = (void *) (((int *)pool) - 1);
    printf("%p", pool);
    free(pool);
    return 0;
}
