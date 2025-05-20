#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* my_malloc(int size)
{
    int i = 0;
    void* ptr = NULL;

    if (size <= 0)
    {
        return NULL;
    }

    ptr = malloc(size);

    if (ptr == NULL)
    {
        return NULL;
    }

    for (i = 0; i < size; i++)
    {
        ((int*)ptr)[i] = 0;
    }

    return ptr;
}

int main()
{
    void* ptr = my_malloc(10);
    int* arr = (int*)ptr;

    arr[-1] = 5;

    free(ptr);

    return 0;
}
