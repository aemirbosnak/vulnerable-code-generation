#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buffer = malloc(10);
    buffer[0] = 'H';
    buffer[1] = 'a';
    buffer[2] = 'c';
    buffer[3] = 'h';
    buffer[4] = 't';
    buffer[5] = 'a';
    buffer[6] = 'n';
    buffer[7] = 'c';
    buffer[8] = 'h';
    buffer[9] = '\0';

    // Out-of-bounds write
    buffer[-1] = 'Z';

    printf("%s\n", buffer);

    free(buffer);
    return 0;
}
