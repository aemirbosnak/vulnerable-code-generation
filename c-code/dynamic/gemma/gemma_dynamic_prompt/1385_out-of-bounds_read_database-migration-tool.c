#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = malloc(10);
    ptr[0] = 'a';
    ptr[1] = 'b';
    ptr[2] = 'c';
    ptr[3] = 'd';
    ptr[4] = 'e';

    // Out-of-bounds read
    ptr[-1] = 'x';

    printf("%s", ptr);

    free(ptr);
    return 0;
}
