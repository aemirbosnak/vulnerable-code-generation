#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char *buf = malloc(1024);
    gets(buf);

    // Out-of-bounds read
    buf[1023] = 'a';

    printf("%s", buf);
    free(buf);

    return 0;
}
