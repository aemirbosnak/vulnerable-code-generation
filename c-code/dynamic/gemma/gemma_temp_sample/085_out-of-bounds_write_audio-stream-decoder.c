#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = malloc(10);
    int i = 0;

    // Out-of-bounds write vulnerability
    buffer[i] = 0x41;

    free(buffer);

    return 0;
}
