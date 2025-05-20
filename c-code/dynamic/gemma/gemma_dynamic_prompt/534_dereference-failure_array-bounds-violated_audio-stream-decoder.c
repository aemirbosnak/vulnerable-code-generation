#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, size = 1024;
    short* buffer = (short*)malloc(size * sizeof(short));

    // Invalid array access
    buffer[size] = 0xdeadbeef;

    free(buffer);
    return 0;
}
