#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *buf = malloc(10);
    buf[10] = 'a';
    printf("%s", buf);
    free(buf);
    return 0;
}
