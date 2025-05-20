#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* my_malloc(int size)
{
    return malloc(size);
}

int main()
{
    void* ptr = my_malloc(10);
    ptr = (void*) (((int)ptr) - 1);
    printf("%p", ptr);
    free(ptr);
    return 0;
}
