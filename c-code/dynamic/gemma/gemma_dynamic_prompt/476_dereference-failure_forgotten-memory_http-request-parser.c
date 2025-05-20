#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* str = malloc(10);
    str = NULL;

    printf("Hello, world!");
    return 0;
}
