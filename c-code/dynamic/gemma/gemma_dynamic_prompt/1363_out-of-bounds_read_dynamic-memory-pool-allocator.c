#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* my_malloc(int size)
{
    void* ptr = malloc(size);
    if (ptr == NULL)
    {
        return NULL;
    }
    return ptr;
}

int main()
{
    void* buffer = my_malloc(10);
    buffer = (void*) ((int) buffer - 1);
    printf("%c", *(char*) buffer);
    free(buffer);
    return 0;
}
