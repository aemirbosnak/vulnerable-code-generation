#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void *allocate(int size)
{
    void *ptr = malloc(size);
    return ptr;
}

void free(void *ptr)
{
    free(ptr);
}

int main()
{
    int *arr = allocate(10);
    free(arr + 1);
    printf("Hello, world!");
    return 0;
}
