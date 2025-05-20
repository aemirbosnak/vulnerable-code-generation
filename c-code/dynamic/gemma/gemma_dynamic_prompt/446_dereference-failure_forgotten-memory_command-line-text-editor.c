#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = NULL;
    int i = 0;

    ptr = malloc(10);

    for (i = 0; i < 10; i++)
    {
        printf("%c", ptr[i]);
    }

    free(ptr);

    return 0;
}
