#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buf = malloc(10);
    buf[0] = 'a';
    buf[1] = 'b';
    buf[2] = 'c';
    buf[3] = 'd';
    buf[4] = 'e';

    // Out of bounds write
    buf[10] = 'f';

    free(buf);
    return 0;
}
