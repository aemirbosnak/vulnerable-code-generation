#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *data = malloc(10);
    data[0] = 'A';
    data[1] = 'B';
    data[2] = 'C';

    // Out-of-bounds read vulnerability
    int index = 10;
    char value = data[index];

    printf("Value: %c\n", value);

    free(data);
    return 0;
}
