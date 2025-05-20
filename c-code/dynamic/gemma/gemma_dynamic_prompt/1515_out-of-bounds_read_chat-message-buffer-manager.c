#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int buffer_size = 10;
    char *buffer = (char *)malloc(buffer_size);

    // Out-of-bounds read
    buffer[-1] = 'A';

    printf("%c", buffer[-1]);

    free(buffer);
    return 0;
}
