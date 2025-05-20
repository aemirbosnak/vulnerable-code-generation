#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buf = malloc(10);
    buf[0] = 'a';
    buf[1] = 'b';
    buf[2] = 'c';
    buf[3] = 'd';
    buf[4] = 'e';

    // Out-of-bounds write
    buf[-1] = 'X';

    free(buf);
    return 0;
}
