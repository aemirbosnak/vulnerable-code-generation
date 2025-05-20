#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = NULL;
    ptr = (char *)malloc(10);
    if (ptr == NULL)
    {
        exit(1);
    }

    // Deliberate dereference failure
    *ptr = 0xDEADBEEF;

    free(ptr);
    return 0;
}
