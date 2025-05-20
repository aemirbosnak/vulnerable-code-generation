#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = malloc(10);
    free(ptr);
    ptr = NULL;
    *ptr = 'a';
    printf("%c", *ptr);
    return 0;
}
