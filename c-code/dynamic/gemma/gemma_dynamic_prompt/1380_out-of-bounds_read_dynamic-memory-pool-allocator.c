#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main()
{
    void *pool = malloc(1024);
    int *ptr = (int *)pool;

    ptr = (int *)((char *)ptr - 1);
    *ptr = 42;

    free(pool);
    return 0;
}
