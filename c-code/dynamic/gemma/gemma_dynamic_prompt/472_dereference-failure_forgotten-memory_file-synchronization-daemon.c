#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **ptr = NULL;
    *ptr = malloc(10);
    free(ptr);

    return 0;
}
