#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* str = malloc(10);
    strcpy(str, "Hello, world!");

    // Out of bounds write vulnerability
    str[10] = 'A';

    printf("%s\n", str);

    free(str);

    return 0;
}
