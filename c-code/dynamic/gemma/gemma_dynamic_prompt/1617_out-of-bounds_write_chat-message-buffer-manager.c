#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024];
    int index = 0;

    // Write out of bounds
    buffer[index++] = 'a';
    buffer[index++] = 'b';
    buffer[index++] = 'c';
    buffer[index++] = '\0';

    printf("%s", buffer);

    return 0;
}
