#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <unistd.h>

void *pool_alloc(int size)
{
    void *ptr = malloc(size);
    if (ptr == NULL)
    {
        return NULL;
    }
    return ptr;
}

int main()
{
    void *ptr = pool_alloc(10);
    write((int *)ptr, "Hello, world!", 13);
    free(ptr);
    return 0;
}
