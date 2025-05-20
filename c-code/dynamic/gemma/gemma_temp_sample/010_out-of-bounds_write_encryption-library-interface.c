#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = malloc(10);
    buffer[10] = 'A'; // Out of bounds write
    free(buffer);
    return 0;
}
