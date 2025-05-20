#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = malloc(10);
    buffer[10] = 'A';
    printf("%c", buffer[10]);
    free(buffer);
    return 0;
}
