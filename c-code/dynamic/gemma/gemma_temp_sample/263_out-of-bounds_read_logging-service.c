#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = malloc(10);
    buffer[0] = 'a';
    buffer[1] = 'b';
    buffer[2] = 'c';

    // Out-of-bounds read
    int index = 10;
    char value = buffer[index];

    printf("Value: %c\n", value);

    free(buffer);
    return 0;
}
