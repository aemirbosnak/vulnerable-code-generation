#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int *ptr = NULL;
    ptr = malloc(10);
    free(ptr);
    printf("Hello, world!");
    return 0;
}
