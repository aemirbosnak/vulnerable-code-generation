#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *buf = NULL;
    int len = 0;

    // Allocate memory for the buffer
    buf = malloc(1024);

    // Write beyond the buffer bounds
    buf[1024] = 'a';

    // Free the memory
    free(buf);

    return 0;
}
