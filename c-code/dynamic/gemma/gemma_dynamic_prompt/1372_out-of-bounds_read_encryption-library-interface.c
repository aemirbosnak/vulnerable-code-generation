#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *data = malloc(10);
    data[0] = 'a';
    data[1] = 'b';
    data[2] = 'c';
    data[3] = 'd';

    // Out-of-bounds read vulnerability
    int index = 10;
    char value = data[index];

    printf("Value at index %d: %c\n", index, value);

    free(data);

    return 0;
}
