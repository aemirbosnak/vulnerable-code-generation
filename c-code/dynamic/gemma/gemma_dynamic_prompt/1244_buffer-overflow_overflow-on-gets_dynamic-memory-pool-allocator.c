#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* allocate(int size)
{
    void* ptr = malloc(size);
    return ptr;
}

int main()
{
    allocate(1000000);
    return 0;
}
