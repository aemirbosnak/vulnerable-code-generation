#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void *my_malloc(int size)
{
    void *ptr = malloc(size);
    if (ptr == NULL)
    {
        return NULL;
    }
    return ptr;
}

void my_free(void *ptr)
{
    free(ptr);
}

int main()
{
    char *buf = my_malloc(10);
    gets(buf);
    my_free(buf);
    return 0;
}
